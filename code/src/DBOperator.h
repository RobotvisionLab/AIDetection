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

	//每一类对应数据库一张表中行类型
public:
	//1-委托单
	vector<OrderBase> m_OrderBase;
	//2-流转单
	vector<Circulation> m_Circulation;
	//3-服务类型
	vector<Servicetype> m_Servicetype;
	//4-样品信息
	vector<Sampleinfo> m_Sampleinfo;
	//5-型号规格
	vector<Model> m_Model;
	//6-准确度等级
	vector<Accclass> m_Accclass;
	//7-最小分度值
	vector<Minivalue> m_Minivalue;
	//8-状态
	vector<State> m_State;
	//9-样品名称
	vector<Samplename> m_Samplename;
	//10-样品结果
	vector<Samplerst> m_Samplerst;
	//11-样品详细结果
	vector<Detailrst> m_Detailrst;
	//12-用户信息
	vector<Userinfo> m_Userinfo;
	//13-角色
	vector<Role> m_Role;
	//14-检定结果
	vector<Detrst> m_Detrst;
	//15-计量标准
	vector<Measurestd> m_Measurestd;
	//16-计量器具
	vector<Measureist> m_Measureist;
	//17-检定依据
	vector<VerifyBasis> m_VerifyBasis;
	//18-检定结果说明
	vector<Detdes> m_Detdes;

	//19-委托单信息
	OrderbaseInfo m_OrderbaseInfo;
	//20-检定结果/说明
	DetRstInfo m_DetRstInfo;
	//21-检定证书
	DetectionInfo m_DetectionInfo;

public:
	//根据委托单号获取委托单合集
	vector<OrderBase> getOrderBaseVecbyWTDH(string wtdh);
	//根据委托单号获取流转单合集
	vector<Circulation> getCirculationVecbyWTDH(string wtdh);
	//根据委托单号获取流转单ID合集
	vector<string> getCirculation_idVecbyWTDH(string wtdh);
	//根据流转单号获取流转单合集
	vector<Circulation> getCirculationVecbyLZDH(string lzdh);
	//根据流转单号获取样品合集
	vector<Sampleinfo> getSampleinfoVecbyLZDH(string lzdh);
	//根据流转单号获取样品编号ID合集
	vector<int> CDBOperator::getYPBH_idVecbyLZDH(string lzdh);
	//根据样品名称ID获取样品名称
	string getSamplenamebyID(int id);
	//根据样品名称获取样品名称ID
	int getSampleIDbyName(string name);
	//根据样品信息ID获取流转单号
	string getLZDHbyYPBH_id(int ypbh_id);
	//根据样品信息ID获取样品信息
	Sampleinfo getSampleinfobyYPBH_id(int ypbh_id);
	//根据型号规格ID获取型号规格
	string getModelbyID(int id);
	//根据型号规格获取型号规格ID
	int getModelIDbyModel(string model);
	//根据准确度等级ID获取准确度等级
	string getAccclassbyID(int id);
	//根据准确度等级获取准确度等级ID
	int getAccclassIDbyAcc(string acc);
	//根据最小分度值ID获取最小分度值
	string getMinivaluebyID(int id);
	//根据最小分度值获取最小分度值ID
	int getMinivalueIDbyminiv(string miniv);
	//根据状态ID获取状态
	string getStatebyID(int id);
	//根据样品信息ID获取外观和零位检查结果
	vector<string> getWG_LWJCbyID(int id);
	//根据流转单号获取流转单信息
	Circulation getCirbyLZDH(string lzdh);
	//根据委托单号获取委托单信息
	OrderBase getOrderBasebyWTDH(string wtdh);
	//根据状态ID获取样品信息ID和流转单号合集
	map<int, string> getSampleID_LZDHbyState(int state);
	//根据流转单号获取委托单号
	string getOrderIDbyLZDH(string lzdh);
	//根据样品信息ID获取样品结果
	void getSamplerstbyID(Samplerst &rst, int id);
	//根据结果编号获取样品详细结果合集
	vector<Detailrst> getDetailrstbyJGBH(string jgbh);
	//根据结果编号获取检定结果
	Detrst getDetrstbyJGBH(string jgbh);
	//根据检定依据编号获取检定依据
	string getVerifyBasisbyID(int id);
	//根据计量标准编号获取计量标准
	Measurestd getMeasurestdbyID(int id);
	//根据计量器具编号获取计量器具
	Measureist getMeasureistbyID(int id);
	//根据用户id获取用户名
	string getUsrnamebyID(int id);
	//根据样品编号id获取检定结果说明
	vector<Detdes> getDetdesbyYPBH_ID(int id);
	//根据结果编号和样品编号id获取样品详细结果合集_PRO
	DetailResult getDetailrstbyJGBH_PRO(int id);
	//根据样品编号id获取结果编号
	string getJGBHbyYPBH_ID(int id);
	//根据样品编号id获取样品编号
	string getYPBHyYPBH_ID(int id);
	//根据样品编号id获取当前状态id
	int getSampleStatebyYPBH_ID(int id);
	//获取证书编号
	string getZSBH(int sampleinfo_id);
	//日期转string
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

	//mode: 0-委托单 1-流转单号 2-委托公司 3-受检单位
	vector<OrderBase> searchResults(string key, int mode = 0);
};

