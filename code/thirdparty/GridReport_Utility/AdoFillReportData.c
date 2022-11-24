#include <vector>
//#include "AdoFillReportData.h"
using namespace std;

#import "C:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace raw_interfaces_only rename("EOF", "EndOfFile")

/////////////////////////////////////////////////////////////////////////////
struct ADOFIELD_PAIR
{
	IGRField *pGRField;
	Field *pAdoField;
};

bstr_t BuildDBFieldName(LPOLESTR FieldName, int col)
{
	ATLASSERT(FieldName != NULL);

	bstr_t bstrFieldName(FieldName);
	if ( bstrFieldName.length() == 0)
	{
		CHAR Name[8] = "Expnm";
		Name[3] = CHAR( '0'+ (col / 10) );
		Name[4] = CHAR( '0'+ (col % 10) );
		bstrFieldName = Name;
	}
	return bstrFieldName;
}

BOOL FillRecordsetFromAdoQuery(IGRRecordset *pRecordset, const CString &ConnectionString, const CString &QuerySQL)
{
    HRESULT  hr;

	try
	{
		CComBSTR bstrConnectionString;
		ConnectionString.SetSysString( &bstrConnectionString );
		CComBSTR bstrQuerySQL;
		QuerySQL.SetSysString( &bstrQuerySQL );

		//open connection and record set
		CComPtr<_Connection> pConnection;
		hr = pConnection.CoCreateInstance(__uuidof(Connection));
		if ( !SUCCEEDED(hr) )
			return FALSE;

		hr = pConnection->Open(bstrConnectionString, L"", L"", adConnectUnspecified); 
		if ( !SUCCEEDED(hr) )
			return FALSE;

		//使用Command，以便设置TimeOut，默认30秒的超时设定太短
		CComPtr<_Command> pCommand;
		hr = pCommand.CoCreateInstance(__uuidof(Command));
		ATLASSERT( SUCCEEDED(hr) );
		pCommand->put_ActiveConnection( CComVariant(pConnection) );
		pCommand->put_CommandText( bstrQuerySQL );
		pCommand->put_CommandTimeout( 0 ); //设置为不超时

		CComPtr<_Recordset> pAdoRecordset;
		hr = pCommand->Execute(NULL, NULL, adCmdText, &pAdoRecordset); 
		if ( !SUCCEEDED(hr) )
		{
			pConnection->Close();
			return FALSE;
		}

		//存储过程中如果使用了临时表，就应该取NextRecordset，不然就取不到数据
		CComPtr<Fields> pFields;    
		pAdoRecordset->get_Fields( &pFields );
		long Count;
		pFields->get_Count( &Count );
		while (Count <= 0)
		{
			CComPtr<_Recordset> pAdoRecordset2;
			pAdoRecordset->NextRecordset(0, &pAdoRecordset2);
			if ( pAdoRecordset2 )
			{
				pAdoRecordset->Close();
				pFields.Release();

				pAdoRecordset =  pAdoRecordset2;
				pAdoRecordset->get_Fields( &pFields );
				pFields->get_Count( &Count );
			}
			else
			{
				break;
			}
		}
		if (Count <= 0)
		{
			pAdoRecordset->Close();
			pConnection->Close();
			return FALSE;
		}

		//匹配ado记录集字段与报表字段
		vector<ADOFIELD_PAIR> FieldPairs;
		VARIANT Index;
		Index.vt = VT_I2;
		for (int i=0; i<Count; i++)
		{
			Index.iVal=i;

			CComPtr<Field> pAdoField;
			pFields->get_Item(Index, &pAdoField);

			CComBSTR FieldName;
			pAdoField->get_Name( &FieldName );

			if ( FieldName )
			{
				bstr_t bstrFieldName = BuildDBFieldName(FieldName, i+1);

				IGRField *pField = pRecordset->FieldByDBName( bstrFieldName );
				if ( pField )
				{
					ADOFIELD_PAIR fp;
					fp.pAdoField = pAdoField;
					fp.pGRField = pField;
					FieldPairs.push_back( fp );
				}
			}
		}
	    
		//取ADO数据并填入报表中
		hr = pAdoRecordset->MoveFirst();
		VARIANT_BOOL EndOfFile;
		pAdoRecordset->get_EndOfFile( &EndOfFile );
		while ( !EndOfFile )
		{
			pRecordset->Append();

			for (vector<ADOFIELD_PAIR>::iterator it=FieldPairs.begin(); it!=FieldPairs.end(); ++it)
			{
				CComVariant val;
				it->pAdoField->get_Value( &val );
				if (val.vt != VT_NULL)
					it->pGRField->put_Value( val );
			}

			pRecordset->Post();

			pAdoRecordset->MoveNext();
			pAdoRecordset->get_EndOfFile( &EndOfFile );
		}

		// Clean up objects before exit.
		pAdoRecordset->Close();
		pConnection->Close();
	}
	catch (...)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL FetchRecordFromAdoQuery(IGridppReport *pReport, const CString &ConnectionString, const CString &QuerySQL)
{
	if ( pReport->DetailGrid )
	{
		return FillRecordsetFromAdoQuery(pReport->DetailGrid->Recordset, ConnectionString, QuerySQL);
	}
	return FALSE;
}