#pragma once
#include "winsock.h"
#include "mysql.h"
#include <string>
#include <vector>
using namespace  std;

class CMyDatabase
{
public:
	CMyDatabase();
	CMyDatabase(string host, string user, string password, string db, unsigned int port);
	CMyDatabase(const CMyDatabase  & db);
	CMyDatabase& operator =(const CMyDatabase& db);
	~CMyDatabase();

public:
	bool DB_Connect();
	void DB_Close();
	bool IsConnected();
	int DB_Exc(string cmd);
	bool DB_GetValues(vector<string>& fileds, vector<int>& fileds_type, vector<vector<string>>& values, int& rows, int& cols);

private:
	string m_host;
	string m_user;
	string m_pwd;
	string m_db;
	unsigned int m_port;

	//���Ӿ��
	MYSQL m_Connect;
	//�����
	MYSQL_RES *m_Result;
	//�����
	MYSQL_ROW m_Sql_row;
	//�ֶ�
	MYSQL_FIELD *m_Fd;

	int m_values_row;
	int m_values_col;

	bool m_isConnected;

};

