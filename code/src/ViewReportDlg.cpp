// ViewReportDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "ViewReportDlg.h"
#include "afxdialogex.h"
#include "AIDetectionDlg.h"
// zzh
#include "..\thirdparty\GridReport_Utility\GridppReportEventImpl.c"
#include "..\thirdparty\GridReport_Utility\GetPath.h"

extern CAIDetectionDlg *g_dlg;
REPORTTYPE CViewReportDlg::m_currentType = WTD;
//OrderBase CViewReportDlg::m_wtdinfo = {};
//vector<Circulation> CViewReportDlg::m_lzdinfo = vector<Circulation>{};
//Circulation CViewReportDlg::m_cirinfo = {};
//Detrst CViewReportDlg::m_detinfo = {};
//Sampleinfo CViewReportDlg::m_sampleinfo = {};
OrderbaseInfo CViewReportDlg::m_orderbaseinfo = {};
DetectionInfo CViewReportDlg::m_detinfo = {};
DetailResult CViewReportDlg::m_detailinfo = {};

string CViewReportDlg::m_template_FileName = "";
string CViewReportDlg::m_save_FileName = "";

class CReportEvent :public CGridppReportEventImpl
{
public:
	virtual void Initialize(void)
	{
		if (m_viewReportDlg.m_currentType == WTD) {
			//vector<string> wtd_fileds = {
			//	"title", "wtdbh", "wtdwqc", "htbh", "sjdwqc", "lxr", "sj",
			//	"lxdh", "sjdwdz", "sjdwlx", "sjdwzzdm", "khyq", "slry", "slrq"
			//};

			//vector<string> lzd_fileds = {
			//	"index", "jlqj", "zqddj", "clfw", "xhgg", "zzc", "ccbh",
			//	"sl", "fj", "qjlx", "jlqjyt", "fwfs", "fwlx", "jbjcf", "bz",
			//	"qjsj", "qjdd", "lzdh", "lqr"
			//};
			m_pGridppReport->ParameterByName("title")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_title.c_str();
			m_pGridppReport->ControlByName("Barcode1")->AsBarcode->Text = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_wtdbh.c_str();
			m_pGridppReport->ParameterByName("wtdwqc")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_wtdw.c_str();
			m_pGridppReport->ParameterByName("htbh")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_htbh.c_str();
			m_pGridppReport->ParameterByName("sjdwqc")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_sjdwqc.c_str();
			m_pGridppReport->ParameterByName("lxr")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_lxr.c_str();
			m_pGridppReport->ParameterByName("sj")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_sj.c_str();
			m_pGridppReport->ParameterByName("lxdh")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_dh.c_str();
			m_pGridppReport->ParameterByName("sjdwdz")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_sjdwdz.c_str();
			m_pGridppReport->ParameterByName("sjdwlx")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_sjdwlx.c_str();
			m_pGridppReport->ParameterByName("sjdwzzdm")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_sjdwdm.c_str();

			m_pGridppReport->ParameterByName("khyq")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_khyq.c_str();
			m_pGridppReport->ParameterByName("slry")->AsString = m_viewReportDlg.m_orderbaseinfo.m_wtdinfo.m_slr.c_str();
			m_pGridppReport->ParameterByName("slrq")->AsString = (LPCTSTR)m_viewReportDlg.m_orderbaseinfo.m_slrq;
				
			//流转信息
			m_F1Field_lzd[0] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("index");
			m_F1Field_lzd[1] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jlqj");
			m_F1Field_lzd[2] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("zqddj");
			m_F1Field_lzd[3] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("clfw");
			m_F1Field_lzd[4] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("xhgg");
			m_F1Field_lzd[5] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("zzc");
			m_F1Field_lzd[6] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("ccbh");
			m_F1Field_lzd[7] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("sl");
			m_F1Field_lzd[8] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("fj");
			m_F1Field_lzd[9] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("qjlx");
			m_F1Field_lzd[10] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jlqjyt");
			m_F1Field_lzd[11] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("fwfs");
			m_F1Field_lzd[12] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("fwlx");
			m_F1Field_lzd[13] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jbjcf");
			m_F1Field_lzd[14] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("bz");
			m_F1Field_lzd[15] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("qjsj");
			m_F1Field_lzd[16] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("qjdd");
			m_F1Field_lzd[17] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("lzdh");
			m_F1Field_lzd[18] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("lqr");

		}
		else if (m_viewReportDlg.m_currentType == JCJG)
		{
			m_pGridppReport->ParameterByName("zdszwc")->AsFloat = m_viewReportDlg.m_detailinfo.zdszwc;
			m_pGridppReport->ParameterByName("zdhcwc")->AsFloat = m_viewReportDlg.m_detailinfo.zdhcwc;
			m_pGridppReport->ParameterByName("zdqqwy")->AsFloat = m_viewReportDlg.m_detailinfo.zdqqwy;
			m_pGridppReport->ParameterByName("lwwc")->AsString = m_viewReportDlg.m_detailinfo.lwwc.c_str();

			//
			m_F1Field_jcjg[0] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("bzz");
			m_F1Field_jcjg[1] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("syy");
			m_F1Field_jcjg[2] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jyy");
			m_F1Field_jcjg[3] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("sye");
			m_F1Field_jcjg[4] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jye");

		}
		else
		{
			m_pGridppReport->ParameterByName("tty")->AsString = m_viewReportDlg.m_detinfo.m_tty.c_str();
			m_pGridppReport->ParameterByName("tte")->AsString = m_viewReportDlg.m_detinfo.m_tte.c_str();
			m_pGridppReport->ControlByName("Barcode1")->AsBarcode->Text = m_viewReportDlg.m_detinfo.m_zsbh.c_str();
			m_pGridppReport->ControlByName("Barcode2")->AsBarcode->Text = m_viewReportDlg.m_detinfo.m_zsbh.c_str();
			m_pGridppReport->ControlByName("wtdw")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_sjdw.c_str();
			m_pGridppReport->ControlByName("jlqjmc")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_jlqjmc.c_str();
			m_pGridppReport->ControlByName("xhgg")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_xhgg.c_str();
			m_pGridppReport->ControlByName("ccbh")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_ccbh.c_str();
			m_pGridppReport->ControlByName("sccs")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_zzdw.c_str();
			m_pGridppReport->ControlByName("jdyj")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_jdyj.c_str();
			m_pGridppReport->ControlByName("jdjl")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_jdjl.c_str();
			m_pGridppReport->ControlByName("jdy")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_jdy.c_str();
			m_pGridppReport->ControlByName("hyy")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_hyy.c_str();
			m_pGridppReport->ControlByName("spy")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_pzr.c_str();
			m_pGridppReport->ControlByName("jdrq_y")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_jdrq.year).c_str();
			m_pGridppReport->ControlByName("jdrq_m")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_jdrq.mouth).c_str();
			m_pGridppReport->ControlByName("jdrq_d")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_jdrq.day).c_str();
			m_pGridppReport->ControlByName("yxq_y")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_yxq.year).c_str();
			m_pGridppReport->ControlByName("yxq_m")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_yxq.mouth).c_str();
			m_pGridppReport->ControlByName("yxq_d")->AsMemoBox->Text = to_string(m_viewReportDlg.m_detinfo.m_yxq.day).c_str();
			m_pGridppReport->ControlByName("sqzsh")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_jdjgsqzsh.c_str();
			m_pGridppReport->ControlByName("dh")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_dh.c_str();
			m_pGridppReport->ControlByName("dz")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_dz.c_str();
			m_pGridppReport->ControlByName("yb")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_yb.c_str();
			m_pGridppReport->ControlByName("cz")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_cz.c_str();
			m_pGridppReport->ControlByName("wz")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_wz.c_str();
			m_pGridppReport->ControlByName("dd")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_dd.c_str();
	
			//计量标准
			m_pGridppReport->ControlByName("jlbz_mc")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_mstd.mc.c_str();
			m_pGridppReport->ControlByName("jlbz_clfw")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_mstd.clfw.c_str();
			m_pGridppReport->ControlByName("jlbz_zqddj")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_mstd.zqddj.c_str();
			m_pGridppReport->ControlByName("jlbz_zsbh")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_mstd.zsbh.c_str();
			CString jlbz_yxq = g_dlg->m_dboperator.dateTostring(m_viewReportDlg.m_detinfo.m_mstd.yxqx);
			m_pGridppReport->ControlByName("jlbz_yxq")->AsMemoBox->Text = (LPCTSTR)jlbz_yxq;

			//计量器具
			m_pGridppReport->ControlByName("jlqj_mc")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_msit.mc.c_str();
			m_pGridppReport->ControlByName("jlqj_xhgg")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_msit.xhgg.c_str();
			m_pGridppReport->ControlByName("jlqj_bh")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_msit.bh.c_str();
			m_pGridppReport->ControlByName("jlqj_clfw")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_msit.clfw.c_str();
			m_pGridppReport->ControlByName("jlqj_zqddj")->AsMemoBox->Text = m_viewReportDlg.m_detinfo.m_msit.zqddj.c_str();
			CString jlqj_yxq = g_dlg->m_dboperator.dateTostring(m_viewReportDlg.m_detinfo.m_msit.yxqx);
			m_pGridppReport->ControlByName("jlqj_yxqx")->AsMemoBox->Text = (LPCTSTR)jlqj_yxq;

			//检定结果/说明
			m_F1Field_jgsm[0] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("index");
			m_F1Field_jgsm[1] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jdxm");
			m_F1Field_jgsm[2] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("cljg");
			m_F1Field_jgsm[3] = m_pviewReportDlg->m_pGridppReportNew->FieldByName("jsyq");
		}

		//将当前记录号复位到0
		m_CurRecordNo = 0;
	}

	virtual void FetchRecord(void)
	{
		FillRecord();
	}

	int m_CurRecordNo;	//在一次只填入一条记录时,记录当前记录的记录号
	IGridppReportPtr m_pGridppReport;
	CViewReportDlg m_viewReportDlg;
	CViewReportDlg* m_pviewReportDlg;
	IGRFieldPtr m_F1Field_lzd[19];
	IGRFieldPtr m_F1Field_jgsm[4];
	IGRFieldPtr m_F1Field_jcjg[5];


private:
	void FillRecord(void)
	{
		if (m_viewReportDlg.m_currentType == WTD) {
			for (int i = 0; i < m_viewReportDlg.m_orderbaseinfo.m_circinfos.size(); i++) {
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Append();
				m_F1Field_lzd[0]->AsInteger = i + 1;
				m_F1Field_lzd[1]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].jlqjmc.c_str();
				m_F1Field_lzd[2]->AsString = "/";
				m_F1Field_lzd[3]->AsString = "/";
				m_F1Field_lzd[4]->AsString = "/";
				m_F1Field_lzd[5]->AsString = "/";
				m_F1Field_lzd[6]->AsString = "/";
				m_F1Field_lzd[7]->AsInteger = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].sl;
				m_F1Field_lzd[8]->AsString = "无";
				m_F1Field_lzd[9]->AsString = "/";
				m_F1Field_lzd[10]->AsString = "/";
				m_F1Field_lzd[11]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].fwfs.c_str();
				m_F1Field_lzd[12]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].fwlx.c_str();
				m_F1Field_lzd[13]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].jbjcfy.c_str();
				m_F1Field_lzd[14]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].bz.c_str();
				m_F1Field_lzd[15]->AsString = (LPCTSTR)m_viewReportDlg.m_orderbaseinfo.m_qjsj[i];
				m_F1Field_lzd[16]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].qjdd.c_str();
				m_F1Field_lzd[17]->AsString = m_viewReportDlg.m_orderbaseinfo.m_circinfos[i].lzdh.c_str();
				m_F1Field_lzd[18]->AsString = "/";
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Post();
			}
		}
		else if(m_viewReportDlg.m_currentType == JCJG)
		{
			m_pviewReportDlg->m_export_button.ShowWindow(SW_HIDE);
			for (int i = 0; i < m_viewReportDlg.m_detailinfo.des.size(); i++) {
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Append();
				m_F1Field_jcjg[0]->AsString = m_viewReportDlg.m_detailinfo.des[i].bzz.c_str();
				m_F1Field_jcjg[1]->AsString = m_viewReportDlg.m_detailinfo.des[i].syy.c_str();
				m_F1Field_jcjg[2]->AsString = m_viewReportDlg.m_detailinfo.des[i].jyy.c_str();
				m_F1Field_jcjg[3]->AsString = m_viewReportDlg.m_detailinfo.des[i].sye.c_str();
				m_F1Field_jcjg[4]->AsString = m_viewReportDlg.m_detailinfo.des[i].jye.c_str();
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Post();
			}

		}
		else{
			for (int i = 0; i < m_viewReportDlg.m_detinfo.m_detrst.des.size(); i++) {
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Append();
				m_F1Field_jgsm[0]->AsInteger = i + 1;
				m_F1Field_jgsm[1]->AsString = m_viewReportDlg.m_detinfo.m_detrst.des[i].jdxm.c_str();
				m_F1Field_jgsm[2]->AsString = m_viewReportDlg.m_detinfo.m_detrst.des[i].cljg.c_str();
				m_F1Field_jgsm[3]->AsString = m_viewReportDlg.m_detinfo.m_detrst.des[i].jsyq.c_str();
				m_pviewReportDlg->m_pGridppReportNew->DetailGrid->Recordset->Post();
			}
		}
		
	}
};


// CViewReportDlg 对话框
IMPLEMENT_DYNAMIC(CViewReportDlg, CDialogEx)

CViewReportDlg::CViewReportDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VIEWREPORTDLG, pParent)
{
}

CViewReportDlg::~CViewReportDlg()
{
}

void CViewReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_export_button);
}


BEGIN_MESSAGE_MAP(CViewReportDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CViewReportDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CViewReportDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CViewReportDlg 消息处理程序


BOOL CViewReportDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//ShowWindow(SW_SHOWMAXIMIZED);
	//取得显示器控件的接口指针
	CWnd *pViewerWnd = GetDlgItem(IDC_GRPRINTVIEWER);
	LPUNKNOWN spUnk = pViewerWnd->GetControlUnknown();
	spUnk->QueryInterface(__uuidof(IGRPrintViewer), (void**)(&m_pPrintViewer));
	ATLASSERT(m_pPrintViewer != NULL);

	//创建报表主对象
	m_pGridppReportNew.CreateInstance(__uuidof(GridppReport));
	ATLASSERT(m_pGridppReportNew != NULL);

	//查询显示器控件关联报表主对象
	m_pPrintViewer->Report = m_pGridppReportNew;

	//从对应文件中载入报表模板数据
	CString  FileName = CStringW(m_template_FileName.c_str());
	m_pGridppReportNew->LoadFromFile((LPCTSTR)FileName);

	//消息响应
	CComObject<CReportEvent> *pEvent;
	CComObject<CReportEvent>::CreateInstance(&pEvent);
	m_pReportEvents = pEvent;
	m_pReportEvents->AddRef();
	pEvent->m_pGridppReport = m_pGridppReportNew;
	pEvent->m_pviewReportDlg = this;

	HRESULT hr = m_pReportEvents->DispEventAdvise(m_pGridppReportNew, &__uuidof(_IGridppReportEvents));
	hr;
	ATLASSERT(SUCCEEDED(hr));

	//显示
	m_pPrintViewer->Start();
	m_pPrintViewer->ZoomToWidth();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CViewReportDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GRExportType ExportType = gretPDF;

	//调用 ExportDirect 方法执行导出任务
	CString  FileName = CStringW(m_save_FileName.c_str());
	m_pGridppReportNew->ExportDirect(ExportType,(LPCTSTR)FileName, FALSE, FALSE);

	CDialogEx::OnOK();
}


void CViewReportDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
BEGIN_EVENTSINK_MAP(CViewReportDlg, CDialogEx)
	ON_EVENT(CViewReportDlg, IDC_GRPRINTVIEWER, DISPID_CLICK, CViewReportDlg::ClickGrprintviewer, VTS_NONE)
END_EVENTSINK_MAP()


void CViewReportDlg::ClickGrprintviewer()
{
	// TODO: 在此处添加消息处理程序代码
}
