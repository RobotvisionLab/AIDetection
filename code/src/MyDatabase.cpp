#include "stdafx.h"
#include "MyDatabase.h"
CMyDatabase::CMyDatabase()
{
	m_values_row = 0;
	m_values_col = 0;
}

CMyDatabase::CMyDatabase(string host, string user, string password, string db, unsigned int port)
{
	m_host = host;
	m_user = user;
	m_pwd = password;
	m_db = db;
	m_port = port;

	m_values_row = 0;
	m_values_col = 0;
}

CMyDatabase::CMyDatabase(const CMyDatabase & db)
{
	m_host = db.m_host;
	m_user = db.m_user;
	m_pwd = db.m_pwd;
	m_db = db.m_db;
	m_port = db.m_port;

	m_values_row = 0;
	m_values_col = 0;
}

CMyDatabase & CMyDatabase::operator=(const CMyDatabase & db)
{
	this->m_host = db.m_host;
	this->m_user = db.m_user;
	this->m_pwd = db.m_pwd;
	this->m_db = db.m_db;
	this->m_port = db.m_port;
	return *this;
}

CMyDatabase::~CMyDatabase()
{
}

bool CMyDatabase::DB_Connect()
{
	mysql_init(&m_Connect);
	if (!mysql_real_connect(&m_Connect, m_host.c_str(), m_user.c_str(), m_pwd.c_str(), m_db.c_str(), m_port, NULL, 0))
	{
		OutputDebugStringA("connect db failed! \n");
		OutputDebugStringA(mysql_error(&m_Connect));
		OutputDebugStringA("\n");
		m_isConnected = FALSE;
		return false;
	}
	else {
		OutputDebugStringA("connect db succeed! \n");
		m_isConnected = TRUE;
		mysql_query(&m_Connect, "SET NAMES 'GB2312' ");
		return true;
	}
}

void CMyDatabase::DB_Close()
{
	mysql_close(&m_Connect);
}

bool CMyDatabase::IsConnected()
{
	return m_isConnected;
}

int CMyDatabase::DB_Exc(string cmd)
{
	if (!m_isConnected)
		return	-1;
	int ret = mysql_query(&m_Connect, cmd.c_str());
	if (ret != 0)
		return -1;
	else {
		m_Result = mysql_store_result(&m_Connect);
		if (m_Result)
		{
			m_Fd = mysql_fetch_field(m_Result);
			m_values_col = mysql_num_fields(m_Result);
			m_values_row = (int)mysql_num_rows(m_Result);
			return 0;
		}
		return -1;
	}
}

bool CMyDatabase::DB_GetValues(vector<string>& fileds, vector<int>& fileds_type, vector<vector<string>>& values, int & rows, int & cols)
{
	if (!m_Result)
		return false;

	rows = m_values_row;
	cols = m_values_col;

	for (int i = 0; i < cols; i++)
	{
		fileds.push_back(m_Fd[i].name);
		fileds_type.push_back(m_Fd[i].type);
		/*if (m_Fd[i].type == 5) {
			OutputDebugStringA("double \n");
		}
		else if (m_Fd[i].type == 3) {
			OutputDebugStringA("int \n");
		}
		else if (m_Fd[i].type == 10) {
			OutputDebugStringA("date \n");
		}
		else if (m_Fd[i].type == 253) {
			OutputDebugStringA("varchar \n");
		}*/
	}

	while ((m_Sql_row = mysql_fetch_row(m_Result)))
	{
		vector<string> temp;
		for (int j=0; j<cols; j++)
		{
			string t = m_Sql_row[j] ? m_Sql_row[j] : "";
			temp.push_back(t);
		}
		values.push_back(temp);
	}
	m_Result = NULL;
	return true;
}

//ds[128] = { 0 };
//sprintf_s(ds, "%s = %s\t\n", m_Fd[j].name, m_Sql_row[j]);
//OutputDebugStringA(ds);

