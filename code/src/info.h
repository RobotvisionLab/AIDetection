#pragma once
#include <string>
#include <vector>
using namespace std;

struct date {
	int year;
	int mouth;
	int day;
};

enum INFO_STATE {
	DEFAULT=0,
	MODIFIED,
	ADDED,
	DELETED
};

class TypeFather
{
public:
	TypeFather() {};
	~TypeFather() {};
};

//1-委托单 OrderBase
class OrderBase: public TypeFather
{
public:
	OrderBase() {};
	//OrderBase(string title, string wtdbh, string m_wtdw, string sjdwqc, string sjdwdz, string sjdwlx, string sjdwdm,
	//	string khyq, string lxr, string sj, string dh, string htbh, string slr, string slrq, int state) {
	//};
	~OrderBase() {};
	//0-id
	int m_id;
	//1抬头
	string m_title;
	//2委托单编号
	string m_wtdbh;
	//3委托单位
	string m_wtdw;
	//4受检单位全称
	string m_sjdwqc;
	//5受检单位地址
	string m_sjdwdz;
	//6受检单位类型
	string m_sjdwlx;
	//7受检单位代码
	string m_sjdwdm;
	//8客户要求
	string m_khyq;
	//9联系人
	string m_lxr;
	//10手机
	string m_sj;
	//11电话
	string m_dh;
	//12合同编号
	string m_htbh;
	//13受理人
	string m_slr;
	//14受理日期
	date m_slrq;
	//15修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE m_state;
};

//2-流转单 Circulation
class Circulation : public TypeFather
{
public:
	Circulation() {};
	~Circulation() {};

	//0-id
	int id;
	//1流转单号
	string lzdh;
	//2委托单号
	string wtdh;
	//3计量器具名称
	string jlqjmc;
	//4准确度等级
	int zqddj;
	//5测量范围
	string clfw;
	//6型号规格
	string xhgg;
	//7出厂编号
	string ccbh;
	//8数量
	int sl;
	//9附件
	string fj;
	//10强检类型
	string qjlx;
	//11计量器具用途
	string jlqjlx;
	//12服务方式
	string fwfs;
	//13服务类型
	string fwlx;
	//14基本检测费用
	string jbjcfy;
	//15备注
	string bz;
	//16取件时间 
	date qjsj;
	//17取件地点
	string qjdd;
	//18领取人
	string lxr;
	//19领取日期
	date lqrq;
	//20修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE _state;
};


//3-服务类型 Servicetype
class Servicetype : public TypeFather
{
public:
	Servicetype() {};
	~Servicetype() {};
	//0-id
	int id;
	string fwlx;
};

//4-样品信息 Sampleinfo
class Sampleinfo : public TypeFather
{
public:
	Sampleinfo() {};
	~Sampleinfo() {};

	//0-id
	int id;
	//1-流转单号
	string lzdh;
	//2-样品名称-id
	int ypmc_id;
	//3-样品编号
	string ypbh;
	//4-型号规格-id
	int xhgg;
	//5-生产厂商
	string sccs;
	//6-准确度等级-id
	int zqddj_id;
	//7-最小分度值-id
	int zxfdz_id;
	//8-托盘编号
	string tpbh;
	//9-当前状态-id
	int dqzt;
	//10-修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE _state;
};


//5-型号规格 Model
class Model : public TypeFather
{
public:
	Model() {};
	~Model() {};

	//0-id
	int id;
	string xhgg;
};

//6-准确度等级 Accclass
class Accclass : public TypeFather
{
public:
	Accclass() {};
	~Accclass() {};

	//0-id
	int id;
	string zqddj;
};

//7-最小分度值 Minivalue
class Minivalue : public TypeFather
{
public:
	Minivalue() {};
	~Minivalue() {};

	//0-id
	int id;
	string zxfdz;
};

//8-状态 State
class State : public TypeFather
{
public:
	State() {};
	~State() {};

	//0-id
	int id;
	string status;
};

//9-样品名称 Samplename
class Samplename : public TypeFather
{
public:
	Samplename() {};
	~Samplename() {};

	//0-id
	int id;
	string ypmc;
};

//10-样品结果 Samplerst
class Samplerst : public TypeFather
{
public:
	Samplerst() {};
	~Samplerst() {};

	//0-id
	int id;
	//1-结果编号
	string jgbh;
	//2-样品编号-id (sampleinfo)
	int ypbh_id;
	//外观结果
	string wgjg;
	//零位检查
	string lwjc;
	//最大示值误差
	double zdszwc;
	//最大回程误差
	double zdhcwc;
	//最大轻敲位移
	double zdqqwy;
	//零位误差
	//double lwwc;
	//核验结果
	string hyjg;
	//审批结果
	string spjg;
	//检定员-id
	int jdy;
	//核验员-id
	int hyy;
	//审批员-id
	int spy;
	//修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE _state;
};

//11-详细检测结果 Detailrst
class Detailrst : public TypeFather
{
public:
	Detailrst() {};
	~Detailrst() {};

	//0-id
	int id;
	//结果编号
	string jgbh;
	//标准值
	string bzz;
	//升压1
	string syy;
	//降压1
	string jyy;
	//升压2
	string sye;
	//降压2
	string jye;
	//轻敲位移1
	string qqwyy;
	//轻敲位移2
	string qqwye;
	//修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE _state;
};


//12-用户信息 Userinfo
class Userinfo : public TypeFather
{
public:
	Userinfo() {};
	~Userinfo() {};

	//0-id
	int id;
	//姓名
	string xm;
	//密码
	string mm;
	//角色-id
	int js;
};

//13-角色 Role
class Role : public TypeFather
{
public:
	Role() {};
	~Role() {};

	//0-id
	int id;
	string js;
};

//14-检定结果 Detrst
class Detrst : public TypeFather
{
public:
	Detrst() {};
	~Detrst() {};

	//0-id
	int id;
	//证书编号
	string zsbh;
	//结果编号
	string jgbh;
	//抬头1
	string tty;
	//抬头2
	string tte;
	//出厂编号
	string ccbh;
	//检定依据-id
	int jdyj;
	//检定结论 
	string jdjl;
	//检定日期  date->string
	date jdrq;
	//有效期 date->string
	date yxq;
	//授权证书号
	string sqzsh;
	//地址
	string dz;
	//传真
	string cz;
	//邮编
	string yb;
	//网址
	string wz;
	//计量标准-id
	int jlbz;
	//计量器具-id
	int jlqj;
	//修改标记 0-未修改 1-修改 2-添加 3-删除
	INFO_STATE _state;
};


//15-计量标准 Measurestd
class Measurestd : public TypeFather
{
public:
	Measurestd() {};
	~Measurestd() {};

	//0-id
	int id;
	//名称
	string mc;
	//测量范围
	string clfw;
	//准确度等级
	string zqddj;
	//证书编号
	string zsbh;
	//有效期限 date->string
	date yxqx;
	//
	string ref;
};

//16-计量器具 Measureist
class Measureist : public TypeFather
{
public:
	Measureist() {};
	~Measureist() {};

	//0-id
	int id;
	//名称
	string mc;
	//型号规格
	string xhgg;
	//编号
	string bh;
	//测量范围
	string clfw;
	//准确度等级
	string zqddj;
	//证书编号
	string zsbh;
	//有效期限 date->string
	date yxqx;
	//
	string ref;
};


//17-检定依据 VerifyBasis
class VerifyBasis : public TypeFather
{
public:
	VerifyBasis() {};
	~VerifyBasis() {};

	//0-id
	int id;
	string jdyj;
	string ref;
};

//18-检定结果说明 Detdes
class Detdes : public TypeFather
{
public:
	Detdes() {};
	~Detdes() {};

	//0-id
	int id;
	int ypbh;
	string jdxm;
	string cljg;
	string jsyq;
	INFO_STATE _state;
};

//重新组合的，方便界面显示和报表生成的类型
//19-委托单信息 OrderbaseInfo
class OrderbaseInfo
{
public:
	OrderbaseInfo() {};
	~OrderbaseInfo() {};

public:
	OrderBase m_wtdinfo;
	vector<Circulation> m_circinfos;
	//信息中日期单独存储
	CString m_slrq;
	vector<CString> m_qjsj;
};

//20-检定结果/说明
class DetRstInfo
{
public:
	DetRstInfo() {};
	~DetRstInfo(){};

public:
	vector<Detdes> des;
};

//21-详细检测结果
class DetailResult
{
public:
	DetailResult() {};
	~DetailResult() {};

public:
	vector<Detailrst> des;
	double zdszwc;
	double zdhcwc;
	double zdqqwy;
	string lwwc;
};

//22-检定证书 DetectionInfo
class DetectionInfo
{
public:
	DetectionInfo() {};
	~DetectionInfo() {};

public:
	string m_tty;
	string m_tte;
	string m_zsbh;
	string m_sjdw;
	string m_jlqjmc;
	string m_xhgg;
	string m_ccbh;
	string m_zzdw;
	string m_jdyj;
	string m_jdjl;
	string m_jdy;
	string m_hyy;
	string m_pzr;
	date m_jdrq;
	date m_yxq;
	string m_jdjgsqzsh;
	string m_dh;
	string m_dz;
	string m_yb;
	string m_cz;
	string m_wz;
	Measurestd m_mstd;
	Measureist m_msit;
	string m_dd;
	DetRstInfo m_detrst;
};