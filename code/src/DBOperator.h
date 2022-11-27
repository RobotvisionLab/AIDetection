#pragma once
#include "MyDatabase.h"
#include "info.h"
//#include "boost/any.hpp"
#include <algorithm>
#include <map>
class CDBOperator
{
public:
	CDBOperator();
	~CDBOperator();

public:
	bool initDB();
	bool getAllInfo();

private:
	CMyDatabase m_mydb;
	//vector<boost::any> m_types;
	
	/* 
		OrderBase, Circulation, Servicetype, Sampleinfo, Model, Accclass, Minivalue,State,
		Samplename, Samplerst, Detailrst, Userinfo, Role, Detrst, Measurestd, Measureist, VerifyBasis
	*/

	//ÿһ���Ӧ���ݿ�һ�ű���������
public:
	//1-ί�е�
	vector<OrderBase> m_OrderBase;
	//2-��ת��
	vector<Circulation> m_Circulation;
	//3-��������
	vector<Servicetype> m_Servicetype;
	//4-��Ʒ��Ϣ
	vector<Sampleinfo> m_Sampleinfo;
	//5-�ͺŹ��
	vector<Model> m_Model;
	//6-׼ȷ�ȵȼ�
	vector<Accclass> m_Accclass;
	//7-��С�ֶ�ֵ
	vector<Minivalue> m_Minivalue;
	//8-״̬
	vector<State> m_State;
	//9-��Ʒ����
	vector<Samplename> m_Samplename;
	//10-��Ʒ���
	vector<Samplerst> m_Samplerst;
	//11-��Ʒ��ϸ���
	vector<Detailrst> m_Detailrst;
	//12-�û���Ϣ
	vector<Userinfo> m_Userinfo;
	//13-��ɫ
	vector<Role> m_Role;
	//14-�춨���
	vector<Detrst> m_Detrst;
	//15-������׼
	vector<Measurestd> m_Measurestd;
	//16-��������
	vector<Measureist> m_Measureist;
	//17-�춨����
	vector<VerifyBasis> m_VerifyBasis;
	//18-�춨���˵��
	vector<Detdes> m_Detdes;

	//19-ί�е���Ϣ
	OrderbaseInfo m_OrderbaseInfo;
	//20-�춨���/˵��
	DetRstInfo m_DetRstInfo;
	//21-�춨֤��
	DetectionInfo m_DetectionInfo;

public:
	//����ί�е��Ż�ȡί�е��ϼ�
	vector<OrderBase> getOrderBaseVecbyWTDH(string wtdh);
	//����ί�е��Ż�ȡ��ת���ϼ�
	vector<Circulation> getCirculationVecbyWTDH(string wtdh);
	//����ί�е��Ż�ȡ��ת��ID�ϼ�
	vector<string> getCirculation_idVecbyWTDH(string wtdh);
	//������ת���Ż�ȡ��ת���ϼ�
	vector<Circulation> getCirculationVecbyLZDH(string lzdh);
	//������ת���Ż�ȡ��Ʒ�ϼ�
	vector<Sampleinfo> getSampleinfoVecbyLZDH(string lzdh);
	//������ת���Ż�ȡ��Ʒ���ID�ϼ�
	vector<int> CDBOperator::getYPBH_idVecbyLZDH(string lzdh);
	//������Ʒ����ID��ȡ��Ʒ����
	string getSamplenamebyID(int id);
	//������Ʒ���ƻ�ȡ��Ʒ����ID
	int getSampleIDbyName(string name);
	//������Ʒ��ϢID��ȡ��ת����
	string getLZDHbyYPBH_id(int ypbh_id);
	//������Ʒ��ϢID��ȡ��Ʒ��Ϣ
	Sampleinfo getSampleinfobyYPBH_id(int ypbh_id);
	//�����ͺŹ��ID��ȡ�ͺŹ��
	string getModelbyID(int id);
	//�����ͺŹ���ȡ�ͺŹ��ID
	int getModelIDbyModel(string model);
	//����׼ȷ�ȵȼ�ID��ȡ׼ȷ�ȵȼ�
	string getAccclassbyID(int id);
	//����׼ȷ�ȵȼ���ȡ׼ȷ�ȵȼ�ID
	int getAccclassIDbyAcc(string acc);
	//������С�ֶ�ֵID��ȡ��С�ֶ�ֵ
	string getMinivaluebyID(int id);
	//������С�ֶ�ֵ��ȡ��С�ֶ�ֵID
	int getMinivalueIDbyminiv(string miniv);
	//����״̬ID��ȡ״̬
	string getStatebyID(int id);
	//������Ʒ��ϢID��ȡ��ۺ���λ�����
	vector<string> getWG_LWJCbyID(int id);
	//������ת���Ż�ȡ��ת����Ϣ
	Circulation getCirbyLZDH(string lzdh);
	//����ί�е��Ż�ȡί�е���Ϣ
	OrderBase getOrderBasebyWTDH(string wtdh);
	//����״̬ID��ȡ��Ʒ��ϢID����ת���źϼ�
	map<int, string> getSampleID_LZDHbyState(int state);
	//������ת���Ż�ȡί�е���
	string getOrderIDbyLZDH(string lzdh);
	//������Ʒ��ϢID��ȡ��Ʒ���
	void getSamplerstbyID(Samplerst &rst, int id);
	//���ݽ����Ż�ȡ��Ʒ��ϸ����ϼ�
	vector<Detailrst> getDetailrstbyJGBH(string jgbh);
	//���ݽ����Ż�ȡ�춨���
	Detrst getDetrstbyJGBH(string jgbh);
	//���ݼ춨���ݱ�Ż�ȡ�춨����
	string getVerifyBasisbyID(int id);
	//���ݼ�����׼��Ż�ȡ������׼
	Measurestd getMeasurestdbyID(int id);
	//���ݼ������߱�Ż�ȡ��������
	Measureist getMeasureistbyID(int id);
	//�����û�id��ȡ�û���
	string getUsrnamebyID(int id);
	//������Ʒ���id��ȡ�춨���˵��
	vector<Detdes> getDetdesbyYPBH_ID(int id);
	//���ݽ����ź���Ʒ���id��ȡ��Ʒ��ϸ����ϼ�_PRO
	DetailResult getDetailrstbyJGBH_PRO(int id);
	//������Ʒ���id��ȡ������
	string getJGBHbyYPBH_ID(int id);
	//������Ʒ���id��ȡ��Ʒ���
	string getYPBHyYPBH_ID(int id);
	//������Ʒ���id��ȡ��ǰ״̬id
	int getSampleStatebyYPBH_ID(int id);
	//��ȡ֤����
	string getZSBH(int sampleinfo_id);
	//����תstring
	CString dateTostring(date d);

public:
	OrderbaseInfo getOrderbaseInfobyWTDH(string wtdh);
	DetRstInfo getDetRstInfo(int sampleinfo_id);
	DetectionInfo getDetectionInfo(string wtdh, string lzdh, int sampleinfo_id);

public:
	int getNewID();
	string getNewTPBH(string lzdh);
	string getNewLZDH();
	string getNewWTDH();
	string getNewYPBH(string lzdh);
	string getNewJGBH();

	BOOL DEL_SAMPLE(int id);
	BOOL MOD_SAMPLE(Sampleinfo& info, Samplerst & rst, vector<int>& index);
	BOOL DEL_CIRU(string lzdh);
	BOOL MOD_CIRU(Circulation& cir, vector<int>& index);
	BOOL DEL_ODB(string wtdh);
	BOOL MOD_ODB(OrderBase& odb, vector<int>& index);

	//mode: 0-ί�е� 1-��ת���� 2-ί�й�˾ 3-�ܼ쵥λ
	vector<OrderBase> searchResults(string key, int mode = 0);
};

