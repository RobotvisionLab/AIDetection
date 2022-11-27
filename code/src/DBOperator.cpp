#include "stdafx.h"
#include "DBOperator.h"

vector<string> g_tables = { "orderbase", "circulation", "servicetype", "sampleinfo", "model", "accclass", "minivalue", "state",
"samplename", "samplerst", "detailrst", "userinfo", "role", "detrst", "measurestd", "measureist", "verifybasis","detdes"};

CDBOperator::CDBOperator()
{
	//m_types = {
	//	m_OrderBase, m_Circulation,   m_Servicetype,  m_Sampleinfo,  m_Model,  m_Accclass,  m_Minivalue, m_State,
	//	m_Samplename,  m_Samplerst,  m_Detailrst,  m_Userinfo,  m_Role,  m_Detrst,  m_Measurestd,  m_Measureist, m_VerifyBasis 
	//};

	/*OrderBase *pOB = new OrderBase();
	pOB->dh = "sd";
	pOB->_state = 3;

	m_OrderBase.push_back(pOB);
	vecs.push_back(m_OrderBase);

	string a = static_cast<OrderBase*>(vecs[0][0])->dh;
	int b = static_cast<OrderBase*>(vecs[0][0])->_state;*/

	/*vector<boost::any> some_values;
	vector<OrderBase*> m_OrderBase1;
	vector<Circulation*> m_Circulation1;

	OrderBase *pOB = new OrderBase();
	pOB->dh = "sd";
	pOB->_state = 3;
	m_OrderBase1.push_back(pOB);

	Circulation *pCC = new Circulation();
	pCC->bz = "sd2";
	pCC->_state = 2;
	m_Circulation1.push_back(pCC);

	some_values.push_back(m_OrderBase1);
	some_values.push_back(m_Circulation1);

	for (auto iter = some_values.begin(); iter != some_values.end(); iter++) {
		vector<OrderBase*> a = boost::any_cast<vector<OrderBase*>>(*iter);
		string aa = a[0]->dh;
		int bb = a[0]->_state;
	}*/
}


CDBOperator::~CDBOperator()
{
}

date stringtodate(string d) {
	if (d.empty())
		return date{ 0,0,0 };
	vector<string> ans;
	string::size_type pos_1, pos_2 = 0;
	while (pos_2 != d.npos) {
		pos_1 = d.find_first_not_of('-', pos_2);
		if (pos_1 == d.npos) break;
		pos_2 = d.find_first_of('-', pos_1);
		ans.push_back(d.substr(pos_1, pos_2 - pos_1));
	}
	date _d;
	_d.year = stoi(ans[0]);
	_d.mouth = stoi(ans[1]);
	_d.day = stoi(ans[2]);
	return _d;
}

int stringtoint(string d) {
	if (d.empty())
		return -1;
	else
		return stoi(d);
}

double stringtodouble(string d) {
	if (d.empty())
		return -1;
	else
		return atof(d.c_str());
}

bool CDBOperator::initDB()
{
	m_mydb = CMyDatabase("localhost", "root", "suep1234", "ylb_db", 3306);
	if (m_mydb.DB_Connect()) {
		return true;
	}
	else {
		return false;
	}
}

bool CDBOperator::getAllInfo()
{
	if (!m_mydb.IsConnected())
		return false;

	int cols = 0;
	int rows = 0;

	m_OrderBase.clear();
	m_Circulation.clear();
	m_Servicetype.clear();
	m_Sampleinfo.clear();
	m_Model.clear();
	m_Accclass.clear();
	m_Minivalue.clear();
	m_State.clear();
	m_Samplename.clear();
	m_Samplerst.clear();
	m_Detailrst.clear();
	m_Userinfo.clear();
	m_Role.clear();
	m_Detrst.clear();
	m_Measurestd.clear();
	m_Measureist.clear();
	m_VerifyBasis.clear();
	m_Detdes.clear();

	for (int table = 0; table < g_tables.size(); table++) {
		char query[128] = { 0 };
		sprintf_s(query, "select * from %s;", g_tables[table].c_str());

		vector<string> fileds;
		vector<int> fileds_type;
		vector<vector<string>> values;

		if (!m_mydb.DB_Exc(query)) {
			if (m_mydb.DB_GetValues(fileds, fileds_type, values, rows, cols)) {
				if (table == 0) {
					for (int r = 0; r < rows; r++) {
						OrderBase o;
						o.m_id = stringtoint(values[r][0]);
						o.m_title = values[r][1];
						o.m_wtdbh = values[r][2];
						o.m_wtdw = values[r][3];
						o.m_sjdwqc = values[r][4];
						o.m_sjdwdz = values[r][5];
						o.m_sjdwlx = values[r][6];
						o.m_sjdwdm = values[r][7];
						o.m_khyq = values[r][8];
						o.m_lxr = values[r][9];
						o.m_sj = values[r][10];
						o.m_dh = values[r][11];
						o.m_htbh = values[r][12];
						o.m_slr = values[r][13];
						o.m_slrq = stringtodate(values[r][14]);
						o.m_state = DEFAULT;
						m_OrderBase.push_back(o);
					}
				}
				else if (table == 1) {
					for (int r = 0; r < rows; r++) {
						Circulation o;
						o.id = stringtoint(values[r][0]);
						o.lzdh = values[r][1];
						o.wtdh = values[r][2];
						o.jlqjmc = values[r][3];
						o.zqddj = stringtoint(values[r][4]);
						o.clfw = values[r][5];
						o.xhgg = values[r][6];
						o.ccbh = values[r][7];
						o.sl = stringtoint(values[r][8]);
						o.fj = values[r][9];
						o.qjlx = values[r][10];
						o.jlqjlx = values[r][11];
						o.fwfs = values[r][12];
						o.fwlx = values[r][13];
						o.jbjcfy = values[r][14];
						o.bz = values[r][15];
						o.qjsj = stringtodate(values[r][16]);
						o.qjdd = values[r][17];
						o.lxr = values[r][18];
						o.lqrq = stringtodate(values[r][19]);
						o._state = DEFAULT;
						m_Circulation.push_back(o);
					}
				}
				else if (table == 2) {
					for (int r = 0; r < rows; r++) {
						Servicetype o;
						o.id = stringtoint(values[r][0]);
						o.fwlx = values[r][1];
						m_Servicetype.push_back(o);
					}
				}
				else if (table == 3) {
					for (int r = 0; r < rows; r++) {
						Sampleinfo o;
						o.id = stringtoint(values[r][0]);
						o.lzdh = values[r][1];
						o.ypmc_id = stringtoint(values[r][2]);
						o.ypbh = values[r][3];
						o.xhgg = stringtoint(values[r][4]);
						o.sccs = values[r][5];
						o.zqddj_id = stringtoint(values[r][6]);
						o.zxfdz_id = stringtoint(values[r][7]);
						o.tpbh = values[r][8];
						o.dqzt = stringtoint(values[r][9]);
						o._state = DEFAULT;
						m_Sampleinfo.push_back(o);
					}
				}
				else if (table == 4) {
					for (int r = 0; r < rows; r++) {
						Model o;
						o.id = stringtoint(values[r][0]);
						o.xhgg = values[r][1];
						m_Model.push_back(o);
					}
				}
				else if (table == 5) {
					for (int r = 0; r < rows; r++) {
						Accclass o;
						o.id = stringtoint(values[r][0]);
						o.zqddj = values[r][1];
						m_Accclass.push_back(o);
					}
				}
				else if (table == 6) {
					for (int r = 0; r < rows; r++) {
						Minivalue o;
						o.id = stringtoint(values[r][0]);
						o.zxfdz = values[r][1];
						m_Minivalue.push_back(o);
					}
				}
				else if (table == 7) {
					for (int r = 0; r < rows; r++) {
						State o;
						o.id = stringtoint(values[r][0]);
						o.status = values[r][1];
						m_State.push_back(o);
					}
				}
				else if (table == 8) {
					for (int r = 0; r < rows; r++) {
						Samplename o;
						o.id = stringtoint(values[r][0]);
						o.ypmc = values[r][1];
						m_Samplename.push_back(o);
					}
				}
				else if (table == 9) {
					for (int r = 0; r < rows; r++) {
						Samplerst o;
						o.id = stringtoint(values[r][0]);
						o.jgbh = values[r][1];
						o.ypbh_id = stringtoint(values[r][2]);
						o.wgjg = values[r][3];
						o.lwjc = values[r][4];
						o.zdszwc = stringtodouble(values[r][5]);
						o.zdhcwc = stringtodouble(values[r][6]);
						o.zdqqwy = stringtodouble(values[r][7]);
						//o.lwwc= values[r][8];
						o.hyjg = values[r][8];
						o.spjg = values[r][9];
						o.jdy = stringtoint(values[r][10]);
						o.hyy = stringtoint(values[r][11]);
						o.spy = stringtoint(values[r][12]);
						o._state = DEFAULT;
						m_Samplerst.push_back(o);
					}
				}
				else if (table == 10) {
					for (int r = 0; r < rows; r++) {
						Detailrst o;
						o.id = stringtoint(values[r][0]);
						o.jgbh = values[r][1];
						o.bzz =values[r][2];
						o.syy = values[r][3];
						o.jyy = values[r][4];
						o.sye = values[r][5];
						o.jye = values[r][6];
						o.qqwyy = values[r][7];
						o.qqwye = values[r][8];
						o._state = DEFAULT;
						m_Detailrst.push_back(o);
					}
				}
				else if (table == 11) {
					for (int r = 0; r < rows; r++) {
						Userinfo o;
						o.id = stringtoint(values[r][0]);
						o.xm = values[r][1];
						o.mm = values[r][2];
						o.js = stringtoint(values[r][3]);
						m_Userinfo.push_back(o);
					}
				}
				else if (table == 12) {
					for (int r = 0; r < rows; r++) {
						Role o;
						o.id = stringtoint(values[r][0]);
						o.js = values[r][1];
						m_Role.push_back(o);
					}
				}
				else if (table == 13) {
					for (int r = 0; r < rows; r++) {
						Detrst o;
						o.id = stringtoint(values[r][0]);
						o.zsbh = values[r][1];
						o.jgbh = values[r][2];
						o.tty = values[r][3];
						o.tte = values[r][4];
						o.ccbh = values[r][5];
						o.jdyj = stringtoint(values[r][6]);
						o.jdjl = values[r][7];
						o.jdrq = stringtodate(values[r][8]);
						o.yxq = stringtodate(values[r][9]);
						o.sqzsh = values[r][10];
						o.dz = values[r][11];
						o.cz = values[r][12];
						o.yb = values[r][13];
						o.wz = values[r][14];
						o.jlbz = stringtoint(values[r][15]);
						o.jlqj = stringtoint(values[r][16]);
						o._state = DEFAULT;
						m_Detrst.push_back(o);
					}
				}
				else if (table == 14) {
					for (int r = 0; r < rows; r++) {
						Measurestd o;
						o.id = stringtoint(values[r][0]);
						o.mc = values[r][1];
						o.clfw = values[r][2];
						o.zqddj = values[r][3];
						o.zsbh = values[r][4];
						o.yxqx = stringtodate(values[r][5]);
						m_Measurestd.push_back(o);
					}
				}
				else if (table == 15) {
					for (int r = 0; r < rows; r++) {
						Measureist o;
						o.id = stringtoint(values[r][0]);
						o.mc = values[r][1];
						o.xhgg = values[r][2];
						o.bh = values[r][3];
						o.clfw = values[r][4];
						o.zqddj = values[r][5];
						o.zsbh = values[r][6];
						o.yxqx = stringtodate(values[r][7]);
						m_Measureist.push_back(o);
					}
				}
				else if (table == 16) {
					for (int r = 0; r < rows; r++) {
						VerifyBasis o;
						o.id = stringtoint(values[r][0]);
						o.jdyj = values[r][1];
						m_VerifyBasis.push_back(o);
					}
				}
				else if (table == 17) {
					for (int r = 0; r < rows; r++) {
						Detdes o;
						o.id = stringtoint(values[r][0]);
						o.ypbh = stringtoint(values[r][1]);
						o.jdxm = values[r][2];
						o.cljg = values[r][3];
						o.jsyq = values[r][4];
						o._state = DEFAULT;
						m_Detdes.push_back(o);
					}
				}
			}
		}
	}
	return true;
}

vector<OrderBase> CDBOperator::getOrderBaseVecbyWTDH(string wtdh)
{
	vector<OrderBase> ret;
	for (int i = 0; i < m_OrderBase.size(); i++) {
		if (m_OrderBase[i].m_wtdbh.compare(wtdh) == 0) {
			ret.push_back(m_OrderBase[i]);
		}
	}
	return ret;
}

vector<Circulation> CDBOperator::getCirculationVecbyWTDH(string wtdh)
{
	vector<Circulation> ret;
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].wtdh.compare(wtdh) == 0) {
			ret.push_back(m_Circulation[i]);
		}
	}
	return ret;
}

vector<string> CDBOperator::getCirculation_idVecbyWTDH(string wtdh)
{
	vector<string> ret;
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].wtdh.compare(wtdh) == 0) {
			ret.push_back(m_Circulation[i].lzdh);
		}
	}
	return ret;
}

vector<Circulation> CDBOperator::getCirculationVecbyLZDH(string lzdh)
{
	vector<Circulation> ret;
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].lzdh.compare(lzdh) == 0) {
			ret.push_back(m_Circulation[i]);
		}
	}
	return ret;
}

vector<Sampleinfo> CDBOperator::getSampleinfoVecbyLZDH(string lzdh)
{
	vector<Sampleinfo> ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].lzdh.compare(lzdh) == 0) {
			ret.push_back(m_Sampleinfo[i]);
		}
	}
	return ret;
}

vector<int> CDBOperator::getYPBH_idVecbyLZDH(string lzdh)
{
	vector<int> ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].lzdh.compare(lzdh) == 0) {
			ret.push_back(m_Sampleinfo[i].id);
		}
	}
	return ret;
}

string CDBOperator::getSamplenamebyID(int id)
{
	string ret;
	for (int i = 0; i < m_Samplename.size(); i++) {
		if (m_Samplename[i].id == id) {
			ret =  m_Samplename[i].ypmc;
			break;
		}
	}
	return ret;
}

int CDBOperator::getSampleIDbyName(string name)
{
	int ret;
	for (int i = 0; i < m_Samplename.size(); i++) {
		if (m_Samplename[i].ypmc == name){
			ret = m_Samplename[i].id;
			break;
		}
	}
	return ret;
}

string CDBOperator::getLZDHbyYPBH_id(int ypbh_id)
{
	string ret;
	for (int i = 0; i <m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].id == ypbh_id) {
			ret = m_Sampleinfo[i].lzdh;
			break;
		}
	}
	return ret;
}

Sampleinfo CDBOperator::getSampleinfobyYPBH_id(int ypbh_id)
{
	Sampleinfo ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].id == ypbh_id) {
			ret =  m_Sampleinfo[i];
			break;
		}
	}
	return ret;
}

string CDBOperator::getModelbyID(int id)
{
	string ret;
	for (int i = 0; i < m_Model.size(); i++) {
		if (m_Model[i].id == id) {
			ret = m_Model[i].xhgg;
			break;
		}
	}
	return ret;
}

int CDBOperator::getModelIDbyModel(string model)
{
	int ret;
	for (int i = 0; i < m_Model.size(); i++) {
		if (m_Model[i].xhgg == model) {
			ret = m_Model[i].id;
			break;
		}
	}
	return ret;
}

string CDBOperator::getAccclassbyID(int id)
{
	string ret;
	for (int i = 0; i < m_Accclass.size(); i++) {
		if (m_Accclass[i].id == id) {
			ret = m_Accclass[i].zqddj;
			break;
		}
	}
	return ret;
}

int CDBOperator::getAccclassIDbyAcc(string acc)
{
	int ret;
	for (int i = 0; i < m_Accclass.size(); i++) {
		if (m_Accclass[i].zqddj == acc) {
			ret = m_Accclass[i].id;
			break;
		}
	}
	return ret;
}

string CDBOperator::getMinivaluebyID(int id)
{
	string ret;
	for (int i = 0; i < m_Minivalue.size(); i++) {
		if (m_Minivalue[i].id == id) {
			ret = m_Minivalue[i].zxfdz;
			break;
		}
	}
	return ret;
}

int CDBOperator::getMinivalueIDbyminiv(string miniv)
{
	int ret;
	for (int i = 0; i < m_Minivalue.size(); i++) {
		if (m_Minivalue[i].zxfdz == miniv) {
			ret = m_Minivalue[i].id;
			break;
		}
	}
	return ret;
}

string CDBOperator::getStatebyID(int id)
{
	string ret;
	for (int i = 0; i < m_State.size(); i++) {
		if (m_State[i].id == id) {
			ret = m_State[i].status;
			break;
		}
	}
	return ret;
}

vector<string> CDBOperator::getWG_LWJCbyID(int id)
{
	vector<string> ret;
	for (int i = 0; i < m_Samplerst.size(); i++) {
		if (m_Samplerst[i].ypbh_id == id) {
			ret.push_back(m_Samplerst[i].wgjg);
			ret.push_back(m_Samplerst[i].lwjc);
		}
	}
	return ret;
}

Circulation CDBOperator::getCirbyLZDH(string lzdh)
{
	Circulation ret;
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].lzdh.compare(lzdh) == 0) {
			ret = m_Circulation[i];
			break;
		}
	}
	return ret;
}

OrderBase CDBOperator::getOrderBasebyWTDH(string wtdh)
{
	OrderBase ret;
	for (int i = 0; i < m_OrderBase.size(); i++) {
		if (m_OrderBase[i].m_wtdbh.compare(wtdh) == 0) {
			ret = m_OrderBase[i];
			break;
		}
	}
	return ret;
}

map<int, string> CDBOperator::getSampleID_LZDHbyState(int state)
{
	map<int, string> ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].dqzt == state) {
			ret.insert({ m_Sampleinfo[i].id, m_Sampleinfo[i].lzdh });
		}
	}
	return ret;
}

string CDBOperator::getOrderIDbyLZDH(string lzdh)
{
	string ret;
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].lzdh == lzdh) {
			ret = m_Circulation[i].wtdh;
			break;
		}
	}
	return ret;
}

void CDBOperator::getSamplerstbyID(Samplerst& rst, int id)
{
	for (int i = 0; i < m_Samplerst.size(); i++) {
		if (m_Samplerst[i].ypbh_id == id) {
			rst = m_Samplerst[i];
			break;
		}
	}
}

vector<Detailrst> CDBOperator::getDetailrstbyJGBH(string jgbh)
{
	vector<Detailrst> ret;
	for (int i = 0; i < m_Detailrst.size(); i++) {
		if (m_Detailrst[i].jgbh == jgbh){
			ret.push_back(m_Detailrst[i]);
		}
	}
	return ret;
}

Detrst CDBOperator::getDetrstbyJGBH(string jgbh)
{
	Detrst ret;
	for (int i = 0; i < m_Detrst.size(); i++) {
		if (m_Detrst[i].jgbh == jgbh) {
			ret = m_Detrst[i];
			break;
		}
	}
	return ret;
}

string CDBOperator::getVerifyBasisbyID(int id)
{
	string ret;
	for (int i = 0; i < m_VerifyBasis.size(); i++) {
		if (m_VerifyBasis[i].id == id) {
			ret = m_VerifyBasis[i].jdyj;
			break;
		}
	}
	return ret;
}

Measurestd CDBOperator::getMeasurestdbyID(int id)
{
	Measurestd ret;
	for (int i = 0; i < m_Measurestd.size(); i++) {
		if (m_Measurestd[i].id == id) {
			ret = m_Measurestd[i];
			break;
		}
	}
	return ret;
}

Measureist CDBOperator::getMeasureistbyID(int id)
{
	Measureist ret;
	for (int i = 0; i < m_Measureist.size(); i++) {
		if (m_Measureist[i].id == id) {
			ret = m_Measureist[i];
			break;
		}
	}
	return ret;
}

string CDBOperator::getUsrnamebyID(int id)
{
	string ret;
	for (int i = 0; i < m_Userinfo.size(); i++) {
		if (m_Userinfo[i].id == id) {
			ret = m_Userinfo[i].xm;
			break;
		}
	}
	return ret;
}

vector<Detdes> CDBOperator::getDetdesbyYPBH_ID(int id)
{
	vector<Detdes> dets;
	for (int i = 0; i < m_Detdes.size(); i++) {
		if (m_Detdes[i].ypbh == id) {
			dets.push_back(m_Detdes[i]);
		}
	}
	return dets;
}

DetailResult CDBOperator::getDetailrstbyJGBH_PRO(int id)
{
	DetailResult rst;
	rst.des = getDetailrstbyJGBH(getJGBHbyYPBH_ID(id));
	Samplerst spt;
	getSamplerstbyID(spt, id);
	rst.zdszwc = spt.zdszwc;
	rst.zdhcwc = spt.zdhcwc;
	rst.zdqqwy = spt.zdqqwy;
	rst.lwwc = spt.lwjc;
	return rst;
}

string CDBOperator::getJGBHbyYPBH_ID(int id)
{
	string ret;
	for (int i = 0; i < m_Samplerst.size(); i++) {
		if (m_Samplerst[i].ypbh_id == id) {
			ret = m_Samplerst[i].jgbh;
			break;
		}
	}
	return ret;
}

string CDBOperator::getYPBHyYPBH_ID(int id)
{
	string ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].id == id) {
			ret = m_Sampleinfo[i].ypbh;
			break;
		}
	}
	return ret;
}

int CDBOperator::getSampleStatebyYPBH_ID(int id)
{
	int ret;
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].id == id) {
			ret = m_Sampleinfo[i].dqzt;
			break;
		}
	}
	return ret;
}

CString CDBOperator::dateTostring(date d)
{
	CString date_s;
	date_s.Format(_T("%04d-%02d-%02d"), d.year, d.mouth, d.day);
	return date_s;
}

OrderbaseInfo CDBOperator::getOrderbaseInfobyWTDH(string wtdh)
{
	OrderbaseInfo ret;
	ret.m_wtdinfo = getOrderBasebyWTDH(wtdh);
	ret.m_circinfos = getCirculationVecbyWTDH(wtdh);
	ret.m_slrq = dateTostring(ret.m_wtdinfo.m_slrq);
	for (int i = 0; i < ret.m_circinfos.size(); i++) {
		ret.m_qjsj.push_back(dateTostring(ret.m_circinfos[i].qjsj));
	}

	return ret;
}

string CDBOperator::getZSBH(int sampleinfo_id)
{
	Samplerst spr;
	getSamplerstbyID(spr, sampleinfo_id);
	Detrst drt = getDetrstbyJGBH(spr.jgbh);
	return drt.zsbh;
}

DetectionInfo CDBOperator::getDetectionInfo(string wtdh, string lzdh, int sampleinfo_id)
{
	DetectionInfo ret;
	OrderBase ob = getOrderBasebyWTDH(wtdh);
	Circulation ci = getCirbyLZDH(lzdh);
	Sampleinfo spi = getSampleinfobyYPBH_id(sampleinfo_id);
	Samplerst spr;
	getSamplerstbyID(spr, sampleinfo_id);
	Detrst drt = getDetrstbyJGBH(spr.jgbh);

	ret.m_tty = drt.tty;
	ret.m_tte = drt.tte;
	ret.m_zsbh = drt.zsbh;
	ret.m_sjdw = ob.m_wtdw;
	ret.m_jlqjmc = ci.jlqjmc;
	ret.m_xhgg = getModelbyID(spi.xhgg);
	ret.m_ccbh = drt.ccbh;
	ret.m_zzdw = spi.sccs;
	ret.m_jdyj = getVerifyBasisbyID(drt.jdyj);
	ret.m_jdjl = drt.jdjl;
	ret.m_jdy = getUsrnamebyID(spr.jdy);
	ret.m_hyy = getUsrnamebyID(spr.hyy);
	ret.m_pzr = getUsrnamebyID(spr.spy);
	ret.m_jdrq = drt.jdrq;
	ret.m_yxq = drt.yxq;
	ret.m_jdjgsqzsh = drt.sqzsh;
	ret.m_dh = ob.m_dh;
	ret.m_dz = drt.dz;
	ret.m_yb = drt.yb;
	ret.m_cz = drt.cz;
	ret.m_wz = drt.wz;
	ret.m_mstd = getMeasurestdbyID(drt.jlbz);
	ret.m_msit = getMeasureistbyID(drt.jlqj);
	ret.m_dd = drt.dz;
	ret.m_detrst = getDetRstInfo(sampleinfo_id);
	return ret;
}

int CDBOperator::getNewID()
{
	//除去删除的id
	for (auto it = m_Sampleinfo.rbegin(); it != m_Sampleinfo.rend(); ++it) {
		if (it->_state == DELETED)
			continue;
		else
			return m_Sampleinfo.back().id + 1;
	}
	return -1;
}

string CDBOperator::getNewTPBH(string lzdh)
{
	string ret;
	string tpbh;
	vector<Sampleinfo> temp_ret = getSampleinfoVecbyLZDH(lzdh);
	for (auto it = temp_ret.rbegin(); it != temp_ret.rend(); ++it) {
		if (it->_state == DELETED)
			continue;
		else {
			tpbh = it->tpbh;
			break;
		}
	}

	if (tpbh == "") {
		tpbh = "T01";
		return tpbh;
	}
	string tpbh_last = tpbh.substr(1, 3);
	int tpbh_id = stoi(tpbh_last);
	CString tpbh_new = _T("");
	tpbh_new.Format(_T("T%02d"), tpbh_id + 1);
	ret = CW2A((LPCTSTR)tpbh_new);
	return ret;
}

string CDBOperator::getNewLZDH()
{
	string ret;
	string lzdh;
	//除去删除的
	for (auto it = m_Circulation.rbegin(); it != m_Circulation.rend(); ++it) {
		if (it->_state == DELETED)
			continue;
		else {
			lzdh = it->lzdh;
			break;
		}
	}

	string lzdh_last = lzdh.substr(1, 8);
	int lzdh_id = stoi(lzdh_last);
	CString lzdh_new = _T("");
	lzdh_new.Format(_T("L%08d"), lzdh_id + 1);
	ret = CW2A((LPCTSTR)lzdh_new);
	return ret;
}

string CDBOperator::getNewWTDH()
{
	string ret;
	string wtdh;
	//除去删除的
	for (auto it = m_OrderBase.rbegin(); it != m_OrderBase.rend(); ++it) {
		if (it->m_state == DELETED)
			continue;
		else {
			wtdh = it->m_wtdbh;
			break;
		}
	}

	string wtdbh_last = wtdh.substr(1, 8);
	int wtdh_id = stoi(wtdbh_last);
	CString wtdh_new = _T("");
	wtdh_new.Format(_T("W%08d"), wtdh_id + 1);
	ret = CW2A((LPCTSTR)wtdh_new);
	return ret;
}

string CDBOperator::getNewYPBH(string lzdh)
{
	string ret;
	string ypbh;
	vector<Sampleinfo> temp_ret = getSampleinfoVecbyLZDH(lzdh);
	for (auto it = temp_ret.rbegin(); it != temp_ret.rend(); ++it) {
		if (it->_state == DELETED)
			continue;
		else {
			ypbh = it->ypbh;
			break;
		}
	}
	
	if (ypbh == "") {
		ypbh = "Y001";
		return ypbh;
	}

	string ypbh_last = ypbh.substr(1, 3);
	int wtdh_id = stoi(ypbh_last);
	CString ypbh_new = _T("");
	ypbh_new.Format(_T("Y%03d"), wtdh_id + 1);
	ret = CW2A((LPCTSTR)ypbh_new);
	return ret;
}

string CDBOperator::getNewJGBH()
{
	string ret;
	string jgbh;
	for (auto it = m_Samplerst.rbegin(); it != m_Samplerst.rend(); ++it) {
		if (it->_state == DELETED)
			continue;
		else {
			jgbh = it->jgbh;
			break;
		}
	}

	string jgbh_last = jgbh.substr(1, 8);
	int jgbh_id = stoi(jgbh_last);
	CString jgbh_new = _T("");
	jgbh_new.Format(_T("J%03d"), jgbh_id + 1);
	ret = CW2A((LPCTSTR)jgbh_new);
	return ret;

}

BOOL CDBOperator::DEL_SAMPLE(int id)
{
	string jgbh = getJGBHbyYPBH_ID(id);
	//删除 sampleinfo 中相关信息
	for (int i = 0; i < m_Sampleinfo.size(); i++) {
		if (m_Sampleinfo[i].id == id) {
			m_Sampleinfo[i]._state = DELETED;
			break;
		}
	}
	//删除 samplerst 中相关信息
	for (int i = 0; i < m_Samplerst.size(); i++) {
		if (m_Samplerst[i].ypbh_id == id) {
			m_Samplerst[i]._state = DELETED;
			break;
		}
	}
	//circulation 中样品数量-1
	//todo, 样品数量=0，删除流转单？
	string lzdh = getLZDHbyYPBH_id(id);
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].lzdh == lzdh){
			m_Circulation[i].sl -=1;
			m_Circulation[i]._state = MODIFIED;
			break;
		}
	}

	//删除 detailrst 中相关信息
	for (int i = 0; i < m_Detailrst.size(); i++) {
		if (m_Detailrst[i].jgbh == jgbh) {
			m_Detailrst[i]._state = DELETED;
		}
	}

	//删除 detdes 中相关信息
	for (int i = 0; i < m_Detdes.size(); i++) {
		if (m_Detdes[i].ypbh == id) {
			m_Detdes[i]._state = DELETED;
		}
	}

	//删除 detrst 中相关信息
	for (int i = 0; i < m_Detrst.size(); i++) {
		if (m_Detrst[i].jgbh == jgbh) {
			m_Detrst[i]._state = DELETED;
			break;
		}
	}
	return 0;
}

BOOL CDBOperator::MOD_SAMPLE(Sampleinfo& info, Samplerst & rst, vector<int>& index)
{
	for (int s = 0; s < m_Sampleinfo.size(); s++) {
		if (m_Sampleinfo[s].id == info.id) {
			if(m_Sampleinfo[s]._state == DEFAULT)
				m_Sampleinfo[s]._state = MODIFIED;
			for (int i = 0; i < index.size(); i++) {
				if (index[i] == 1) {
					m_Sampleinfo[s].ypmc_id = info.ypmc_id;
				}
				else if (index[i] == 2) {
					m_Sampleinfo[s].xhgg = info.xhgg;
				}
				else if (index[i] == 3) {
					m_Sampleinfo[s].zqddj_id = info.zqddj_id;
				}
				else if(index[i] == 4) {
					m_Sampleinfo[s].zxfdz_id = info.zxfdz_id;
				}
				else if (index[i] == 6) {
					m_Sampleinfo[s].sccs = info.sccs;
				}
				else if (index[i] == 8) {
					for (int j = 0; j < m_Samplerst.size(); j++) {
						if (m_Samplerst[j].ypbh_id == m_Sampleinfo[s].id) {
							m_Samplerst[j].wgjg = rst.wgjg;
							if (m_Samplerst[j]._state == DEFAULT)
								m_Samplerst[j]._state = MODIFIED;
							break;
						}
					}
				}
				else if (index[i] == 9) {
					for (int j = 0; j < m_Samplerst.size(); j++) {
						if (m_Samplerst[j].ypbh_id == m_Sampleinfo[s].id) {
							m_Samplerst[j].lwjc = rst.lwjc;
							if (m_Samplerst[j]._state == DEFAULT)
								m_Samplerst[j]._state = MODIFIED;
							break;
						}
					}
				}
			}
			break;
		}
	}

	return 0;
}

BOOL CDBOperator::DEL_CIRU(string lzdh)
{
	//操作时，之前的修改已经保存，因此没有必要考虑，先增加后删除的情况
	//样品
	vector<int> retvec = getYPBH_idVecbyLZDH(lzdh);
	for (int i = 0; i < retvec.size(); i++) {
		DEL_SAMPLE(retvec[i]);
	}

	//circulation
	//todo, 流转单数量=0，删除委托单？
	for (int i = 0; i < m_Circulation.size(); i++) {
		if (m_Circulation[i].lzdh.compare(lzdh) == 0) {
			m_Circulation[i]._state = DELETED;
		}
	}
	return 0;
}

BOOL CDBOperator::MOD_CIRU(Circulation & cir, vector<int>& index)
{
	for (int s = 0; s < m_Circulation.size(); s++) {
		if (m_Circulation[s].lzdh == cir.lzdh) {
			if (m_Circulation[s]._state == DEFAULT)
				m_Circulation[s]._state = MODIFIED;
			for (int i = 0; i < index.size(); i++) {
				if (index[i] == 1) {
					m_Circulation[s].jlqjmc = cir.jlqjmc;
				}
				else if (index[i] == 7) {
					m_Circulation[s].fj = cir.fj;
				}
				else if (index[i] == 8) {
					m_Circulation[s].qjlx = cir.qjlx;
				}
				else if (index[i] == 9) {
					m_Circulation[s].fwfs = cir.fwfs;
				}
				else if (index[i] == 10) {
					m_Circulation[s].fwlx = cir.fwlx;
				}
				else if (index[i] == 11) {
					m_Circulation[s].jbjcfy = cir.jbjcfy;
				}
				else if (index[i] == 12) {
					m_Circulation[s].bz = cir.bz;
				}
				else if (index[i] == 13) {
					m_Circulation[s].qjsj = cir.qjsj;
				}
				else if (index[i] == 14) {
					m_Circulation[s].qjdd = cir.qjdd;
				}
				else if (index[i] == 15) {
					m_Circulation[s].lxr = cir.lxr;
				}
				else if (index[i] == 16) {
					m_Circulation[s].lqrq = cir.lqrq;
				}
			}
			break;
		}
	}
	return 0;
}

BOOL CDBOperator::MOD_ODB(OrderBase & odb, vector<int>& index)
{
	for (int s = 0; s < m_OrderBase.size(); s++) {
		if (m_OrderBase[s].m_wtdbh == odb.m_wtdbh) {
			if (m_OrderBase[s].m_state == DEFAULT)
				m_OrderBase[s].m_state = MODIFIED;
			for (int i = 0; i < index.size(); i++) {
				if (index[i] == 1) {
					m_OrderBase[s].m_title = odb.m_title;
				}
				else if (index[i] == 2) {
					m_OrderBase[s].m_wtdw = odb.m_wtdw;
				}
				else if (index[i] == 3) {
					m_OrderBase[s].m_sjdwqc = odb.m_sjdwqc;
				}
				else if (index[i] == 4) {
					m_OrderBase[s].m_sjdwdz = odb.m_sjdwdz;
				}
				else if (index[i] == 5) {
					m_OrderBase[s].m_sjdwlx = odb.m_sjdwlx;
				}
				else if (index[i] == 6) {
					m_OrderBase[s].m_sjdwdm = odb.m_sjdwdm;
				}
				else if (index[i] == 8) {
					m_OrderBase[s].m_lxr = odb.m_lxr;
				}
				else if (index[i] == 9) {
					m_OrderBase[s].m_sj = odb.m_sj;
				}
				else if (index[i] == 10) {
					m_OrderBase[s].m_dh = odb.m_dh;
				}
				else if (index[i] == 11) {
					m_OrderBase[s].m_khyq = odb.m_khyq;
				}
				else if (index[i] == 12) {
					m_OrderBase[s].m_slr = odb.m_slr;
				}
				else if (i == 13) {
					m_OrderBase[s].m_slrq = odb.m_slrq;
				}
			}
			break;
		}
	}
	return 0;
}

vector<OrderBase> CDBOperator::searchResults(string key, int mode)
{
	//此处应使用 模糊匹配字符串 算法
	vector<OrderBase> odb;
	switch (mode)
	{
	//委托单号
	case 0:
	{
		for each(auto c in m_OrderBase) {
			if (c.m_wtdbh.find(key.c_str()) != -1) {
				odb.push_back(c);
			}
		}
		break;
	}
	//流转单号
	case 1:
	{	
		//其他类似地方 也因该用 STL 的find
		for each(auto c in m_Circulation) {
			vector<string> wtdhs;
			if (c.lzdh.find(key.c_str()) != -1) {
				OrderBase o =  getOrderBasebyWTDH(c.wtdh);
				if (find(wtdhs.begin(), wtdhs.end(), c.wtdh) == wtdhs.end()) {
					wtdhs.push_back(c.wtdh);
					odb.push_back(o);
				}
			}
		}
		break;
	}
	//委托公司
	case 2:
	{
		for each(auto c in m_OrderBase) {
			if (c.m_wtdw.find(key.c_str()) != -1) {
				odb.push_back(c);
			}
		}
		break;
	}
	//受检单位
	case 3:
	{
		for each(auto c in m_OrderBase) {
			if (c.m_sjdwqc.find(key.c_str()) != -1) {
				odb.push_back(c);
			}
		}
		break;
	}
	default:
		break;
	}

	return odb;
}

BOOL CDBOperator::DEL_ODB(string wtdh)
{
	//操作时，之前的修改已经保存，因此没有必要考虑，先增加后删除的情况
	//流转单
	vector<string> retvec = getCirculation_idVecbyWTDH(wtdh);
	for (int i = 0; i < retvec.size(); i++) {
		DEL_CIRU(retvec[i]);
	}

	//orderbase
	for (int i = 0; i < m_OrderBase.size(); i++) {
		if (m_OrderBase[i].m_wtdbh.compare(wtdh) == 0) {
			m_OrderBase[i].m_state = DELETED;
		}
	}
	return 0;
}

DetRstInfo CDBOperator::getDetRstInfo(int sampleinfo_id)
{
	vector<Detdes> temp = getDetdesbyYPBH_ID(sampleinfo_id);
	DetRstInfo ret;
	ret.des = temp;
	Samplerst rst;
	getSamplerstbyID(rst, sampleinfo_id);
	return ret;
}

