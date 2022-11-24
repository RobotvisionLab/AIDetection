#pragma once

inline CString GetInstallPath(void)
{
	TCHAR FileName[MAX_PATH];
	GetModuleFileName(NULL, FileName, MAX_PATH);
	::CharLower( FileName );
	CString strFileName( FileName );
	int Index = strFileName.Find( _T("samples") );
	CString Path = strFileName.Mid(0, Index);
	return Path;
};


inline CString GetReportTemplatePath(void)
{
	return GetInstallPath() + CString(_T("Samples\\reports\\"));
}

inline CString GetReportDataPath(void)
{
	return GetInstallPath() + CString(_T("Samples\\Data"));
}

inline CString GetReportDataPathFile(void)
{
	return GetInstallPath() + CString(_T("Samples\\Data\\NorthWind.mdb"));
}

inline CString GetDatabaseConnectionString(void)
{
#ifdef _WIN64
	return CString(_T("Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source="))
		+ GetReportDataPathFile() + _T(";");
#else
	return CString(_T("Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source="))
		+ GetReportDataPathFile() + _T(";");
#endif
}