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

//1-ί�е� OrderBase
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
	//1̧ͷ
	string m_title;
	//2ί�е����
	string m_wtdbh;
	//3ί�е�λ
	string m_wtdw;
	//4�ܼ쵥λȫ��
	string m_sjdwqc;
	//5�ܼ쵥λ��ַ
	string m_sjdwdz;
	//6�ܼ쵥λ����
	string m_sjdwlx;
	//7�ܼ쵥λ����
	string m_sjdwdm;
	//8�ͻ�Ҫ��
	string m_khyq;
	//9��ϵ��
	string m_lxr;
	//10�ֻ�
	string m_sj;
	//11�绰
	string m_dh;
	//12��ͬ���
	string m_htbh;
	//13������
	string m_slr;
	//14��������
	date m_slrq;
	//15�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE m_state;
};

//2-��ת�� Circulation
class Circulation : public TypeFather
{
public:
	Circulation() {};
	~Circulation() {};

	//0-id
	int id;
	//1��ת����
	string lzdh;
	//2ί�е���
	string wtdh;
	//3������������
	string jlqjmc;
	//4׼ȷ�ȵȼ�
	int zqddj;
	//5������Χ
	string clfw;
	//6�ͺŹ��
	string xhgg;
	//7�������
	string ccbh;
	//8����
	int sl;
	//9����
	string fj;
	//10ǿ������
	string qjlx;
	//11����������;
	string jlqjlx;
	//12����ʽ
	string fwfs;
	//13��������
	string fwlx;
	//14����������
	string jbjcfy;
	//15��ע
	string bz;
	//16ȡ��ʱ�� 
	date qjsj;
	//17ȡ���ص�
	string qjdd;
	//18��ȡ��
	string lxr;
	//19��ȡ����
	date lqrq;
	//20�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE _state;
};


//3-�������� Servicetype
class Servicetype : public TypeFather
{
public:
	Servicetype() {};
	~Servicetype() {};
	//0-id
	int id;
	string fwlx;
};

//4-��Ʒ��Ϣ Sampleinfo
class Sampleinfo : public TypeFather
{
public:
	Sampleinfo() {};
	~Sampleinfo() {};

	//0-id
	int id;
	//1-��ת����
	string lzdh;
	//2-��Ʒ����-id
	int ypmc_id;
	//3-��Ʒ���
	string ypbh;
	//4-�ͺŹ��-id
	int xhgg;
	//5-��������
	string sccs;
	//6-׼ȷ�ȵȼ�-id
	int zqddj_id;
	//7-��С�ֶ�ֵ-id
	int zxfdz_id;
	//8-���̱��
	string tpbh;
	//9-��ǰ״̬-id
	int dqzt;
	//10-�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE _state;
};


//5-�ͺŹ�� Model
class Model : public TypeFather
{
public:
	Model() {};
	~Model() {};

	//0-id
	int id;
	string xhgg;
};

//6-׼ȷ�ȵȼ� Accclass
class Accclass : public TypeFather
{
public:
	Accclass() {};
	~Accclass() {};

	//0-id
	int id;
	string zqddj;
};

//7-��С�ֶ�ֵ Minivalue
class Minivalue : public TypeFather
{
public:
	Minivalue() {};
	~Minivalue() {};

	//0-id
	int id;
	string zxfdz;
};

//8-״̬ State
class State : public TypeFather
{
public:
	State() {};
	~State() {};

	//0-id
	int id;
	string status;
};

//9-��Ʒ���� Samplename
class Samplename : public TypeFather
{
public:
	Samplename() {};
	~Samplename() {};

	//0-id
	int id;
	string ypmc;
};

//10-��Ʒ��� Samplerst
class Samplerst : public TypeFather
{
public:
	Samplerst() {};
	~Samplerst() {};

	//0-id
	int id;
	//1-������
	string jgbh;
	//2-��Ʒ���-id (sampleinfo)
	int ypbh_id;
	//��۽��
	string wgjg;
	//��λ���
	string lwjc;
	//���ʾֵ���
	double zdszwc;
	//���س����
	double zdhcwc;
	//�������λ��
	double zdqqwy;
	//��λ���
	//double lwwc;
	//������
	string hyjg;
	//�������
	string spjg;
	//�춨Ա-id
	int jdy;
	//����Ա-id
	int hyy;
	//����Ա-id
	int spy;
	//�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE _state;
};

//11-��ϸ����� Detailrst
class Detailrst : public TypeFather
{
public:
	Detailrst() {};
	~Detailrst() {};

	//0-id
	int id;
	//������
	string jgbh;
	//��׼ֵ
	string bzz;
	//��ѹ1
	string syy;
	//��ѹ1
	string jyy;
	//��ѹ2
	string sye;
	//��ѹ2
	string jye;
	//����λ��1
	string qqwyy;
	//����λ��2
	string qqwye;
	//�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE _state;
};


//12-�û���Ϣ Userinfo
class Userinfo : public TypeFather
{
public:
	Userinfo() {};
	~Userinfo() {};

	//0-id
	int id;
	//����
	string xm;
	//����
	string mm;
	//��ɫ-id
	int js;
};

//13-��ɫ Role
class Role : public TypeFather
{
public:
	Role() {};
	~Role() {};

	//0-id
	int id;
	string js;
};

//14-�춨��� Detrst
class Detrst : public TypeFather
{
public:
	Detrst() {};
	~Detrst() {};

	//0-id
	int id;
	//֤����
	string zsbh;
	//������
	string jgbh;
	//̧ͷ1
	string tty;
	//̧ͷ2
	string tte;
	//�������
	string ccbh;
	//�춨����-id
	int jdyj;
	//�춨���� 
	string jdjl;
	//�춨����  date->string
	date jdrq;
	//��Ч�� date->string
	date yxq;
	//��Ȩ֤���
	string sqzsh;
	//��ַ
	string dz;
	//����
	string cz;
	//�ʱ�
	string yb;
	//��ַ
	string wz;
	//������׼-id
	int jlbz;
	//��������-id
	int jlqj;
	//�޸ı�� 0-δ�޸� 1-�޸� 2-��� 3-ɾ��
	INFO_STATE _state;
};


//15-������׼ Measurestd
class Measurestd : public TypeFather
{
public:
	Measurestd() {};
	~Measurestd() {};

	//0-id
	int id;
	//����
	string mc;
	//������Χ
	string clfw;
	//׼ȷ�ȵȼ�
	string zqddj;
	//֤����
	string zsbh;
	//��Ч���� date->string
	date yxqx;
	//
	string ref;
};

//16-�������� Measureist
class Measureist : public TypeFather
{
public:
	Measureist() {};
	~Measureist() {};

	//0-id
	int id;
	//����
	string mc;
	//�ͺŹ��
	string xhgg;
	//���
	string bh;
	//������Χ
	string clfw;
	//׼ȷ�ȵȼ�
	string zqddj;
	//֤����
	string zsbh;
	//��Ч���� date->string
	date yxqx;
	//
	string ref;
};


//17-�춨���� VerifyBasis
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

//18-�춨���˵�� Detdes
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

//������ϵģ����������ʾ�ͱ������ɵ�����
//19-ί�е���Ϣ OrderbaseInfo
class OrderbaseInfo
{
public:
	OrderbaseInfo() {};
	~OrderbaseInfo() {};

public:
	OrderBase m_wtdinfo;
	vector<Circulation> m_circinfos;
	//��Ϣ�����ڵ����洢
	CString m_slrq;
	vector<CString> m_qjsj;
};

//20-�춨���/˵��
class DetRstInfo
{
public:
	DetRstInfo() {};
	~DetRstInfo(){};

public:
	vector<Detdes> des;
};

//21-��ϸ�����
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

//22-�춨֤�� DetectionInfo
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