// DetectionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "AIDetectionDlg.h"
#include "DetectionDlg.h"
#include "afxdialogex.h"



extern CAIDetectionDlg *g_dlg;
// CDetectionDlg 对话框

IMPLEMENT_DYNAMIC(CDetectionDlg, CDialogEx)

CDetectionDlg::CDetectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DETECTIONDLG, pParent)
{
	
}

CDetectionDlg::~CDetectionDlg()
{
	m_Detection_ImageList.DeleteImageList();
}

void CDetectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_D_JCJG, m_list_jcjg);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_JDJG, m_proper_jdjg);
	DDX_Control(pDX, IDC_LIST_JDJG, m_list_jdjg);
	DDX_Control(pDX, IDC_STATIC_D_YPXX, m_static_d_ypxx);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_D_YPXX, m_list_d_ypxx);
	DDX_Control(pDX, IDC_STATIC_D_JCSJ, m_static_d_jcsj);
	DDX_Control(pDX, IDC_STATIC_CAM, m_static_cam);
	DDX_Control(pDX, IDC_STATIC_SSHM, m_static_sshm);
	DDX_Control(pDX, IDC_STATIC_JCJG, m_static_jcjg);
	DDX_Control(pDX, IDC_STATIC_JDJG, m_static_jdjg);
	DDX_Control(pDX, IDC_STATIC_HYSP, m_static_hysp);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_HYSP, m_proper_hysp);
	DDX_Control(pDX, IDC_TREE_DET_YP, m_list_d_yp);
}


BEGIN_MESSAGE_MAP(CDetectionDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_TREE_DET_YP, &CDetectionDlg::OnNMClickTreeDetYp)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DET_YP, &CDetectionDlg::OnTvnSelchangedTreeDetYp)
	ON_COMMAND(ID_BUTTON_SUBMIT,  &OnSubmit)
END_MESSAGE_MAP()


// CDetectionDlg 消息处理程序


BOOL CDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 在此添加额外的初始化
	//初始化工具栏
	m_Detection_ImageList.Create(18, 18, ILC_COLOR24 | ILC_MASK, 0, 1);
	for (int i = 0; i < 14; i++)
	{
		m_Detection_ImageList.Add(AfxGetApp()->LoadIconW(IDI_ICON_YJC + i));
	}

	if (!m_Detection_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_Detection_ToolBar.LoadToolBar(IDR_TOOLBAR_DETECTION))
	{
		EndDialog(IDCANCEL);
	}
	m_Detection_ToolBar.SetSizes(CSize(36, 40), CSize(18, 18));
	m_Detection_ToolBar.GetToolBarCtrl().SetImageList(&m_Detection_ImageList);
	m_Detection_ToolBar.ModifyStyle(0, BTNS_SHOWTEXT | TBSTYLE_EX_MIXEDBUTTONS);
	m_Detection_ToolBar.SetButtonText(0, _T("未检测"));
	m_Detection_ToolBar.SetButtonText(1, _T("未检定"));
	m_Detection_ToolBar.SetButtonText(2, _T("未核验"));
	m_Detection_ToolBar.SetButtonText(4, _T("实时画面"));
	m_Detection_ToolBar.SetButtonText(5, _T("检定依据"));
	m_Detection_ToolBar.SetButtonText(6, _T("计量标准"));
	m_Detection_ToolBar.SetButtonText(7, _T("计量器具"));
	m_Detection_ToolBar.SetButtonText(8, _T("计量依据"));
	m_Detection_ToolBar.SetButtonText(10, _T("上一个"));
	m_Detection_ToolBar.SetButtonText(11, _T("下一个"));
	m_Detection_ToolBar.SetButtonText(13, _T("检测结果"));
	m_Detection_ToolBar.SetButtonText(14, _T("检定结果"));
	m_Detection_ToolBar.SetButtonText(16, _T("保存"));
	m_Detection_ToolBar.SetButtonText(17, _T("提交"));

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0); 
	m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_YJC, true);

	DWORD dwStyle = m_list_jcjg.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list_jcjg.SetExtendedStyle(dwStyle); 

	initYP_P();

	m_list_jcjg.InsertColumn(0, _T("0"), LVCFMT_CENTER, 55);
	m_list_jcjg.InsertColumn(1, _T("1"), LVCFMT_CENTER, 51);
	m_list_jcjg.InsertColumn(2, _T("2"), LVCFMT_CENTER, 53);
	m_list_jcjg.InsertColumn(3, _T("3"), LVCFMT_CENTER, 49);
	m_list_jcjg.InsertColumn(4, _T("4"), LVCFMT_CENTER, 51);
	m_list_jcjg.InsertColumn(5, _T("5"), LVCFMT_CENTER, 50);
	m_list_jcjg.InsertColumn(6, _T("6"), LVCFMT_CENTER, 53);


	HDITEM item;
	item.cxy = 110;
	item.mask = HDI_WIDTH;
	m_proper_jdjg.GetHeaderCtrl().SetItem(0, &item);

	//所有的属性指针要在析构函数里delete
	CMFCPropertyGridProperty *pGroup0 = new CMFCPropertyGridProperty(_T("检测依据"));
	CMFCPropertyGridProperty *pGroup0JDYJ = new CMFCPropertyGridProperty(_T("检定依据"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0JLBZ = new CMFCPropertyGridProperty(_T("计量标准"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0JLQJ = new CMFCPropertyGridProperty(_T("计量器具"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0JSYQ = new CMFCPropertyGridProperty(_T("技术要求"), (_variant_t)_T(""), _T(""));
	pGroup0->AddSubItem(pGroup0JDYJ);
	pGroup0->AddSubItem(pGroup0JLBZ);
	pGroup0->AddSubItem(pGroup0JLQJ);
	pGroup0->AddSubItem(pGroup0JSYQ);
	m_mfcprogridpro_jcjg.push_back(pGroup0JDYJ);
	m_mfcprogridpro_jcjg.push_back(pGroup0JLBZ);
	m_mfcprogridpro_jcjg.push_back(pGroup0JLQJ);
	m_mfcprogridpro_jcjg.push_back(pGroup0JSYQ);

	CMFCPropertyGridProperty *pGroup1 = new CMFCPropertyGridProperty(_T("分项结果"));
	CMFCPropertyGridProperty *pGroup0ZDSZWC = new CMFCPropertyGridProperty(_T("最大示值误差"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0ZDHCWC = new CMFCPropertyGridProperty(_T("最大回程误差"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0ZDQQWY = new CMFCPropertyGridProperty(_T("最大轻敲位移"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty *pGroup0LWWC = new CMFCPropertyGridProperty(_T("零位误差"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pGroup0ZDSZWC);
	pGroup1->AddSubItem(pGroup0ZDHCWC);
	pGroup1->AddSubItem(pGroup0ZDQQWY);
	pGroup1->AddSubItem(pGroup0LWWC);
	m_mfcprogridpro_jcjg.push_back(pGroup0ZDSZWC);
	m_mfcprogridpro_jcjg.push_back(pGroup0ZDHCWC);
	m_mfcprogridpro_jcjg.push_back(pGroup0ZDQQWY);
	m_mfcprogridpro_jcjg.push_back(pGroup0LWWC);

	CMFCPropertyGridProperty *pGroup2 = new CMFCPropertyGridProperty(_T("最终结果"));
	//CMFCPropertyGridProperty* pPropResult = new CMFCPropertyGridProperty(_T("是否合格"), _T("xx级 合格"), _T(""));
	//pPropResult->AddOption(_T("xx级 不合格"));
	CMFCPropertyGridProperty* pPropResult = new CMFCPropertyGridProperty(_T("是否合格"), _T(""), _T(""));
	pGroup2->AddSubItem(pPropResult);
	m_mfcprogridpro_jcjg.push_back(pPropResult);

	m_proper_jdjg.AddProperty(pGroup0);
	m_proper_jdjg.AddProperty(pGroup1);
	m_proper_jdjg.AddProperty(pGroup2);


	//
	dwStyle = m_list_jdjg.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list_jdjg.SetExtendedStyle(dwStyle);

	m_list_jdjg.InsertColumn(0, _T("序 号"), LVCFMT_CENTER, 40);
	m_list_jdjg.InsertColumn(1, _T("检定项目"), LVCFMT_CENTER, 105);
	m_list_jdjg.InsertColumn(2, _T("测量结果"), LVCFMT_CENTER, 80);
	m_list_jdjg.InsertColumn(3, _T("技术要求"), LVCFMT_CENTER, 130);

	m_list_jdjg.InsertItem(0, _T("1"));
	m_list_jdjg.SetItemText(0, 1, _T("外观"));
	m_list_jdjg.SetItemText(0, 2, _T("符合要求"));
	m_list_jdjg.SetItemText(0, 3, _T("规程6.1条"));

	m_list_jdjg.InsertItem(1, _T("2"));
	m_list_jdjg.SetItemText(1, 1, _T("零位误差"));
	m_list_jdjg.SetItemText(1, 2, _T("符合要求"));
	m_list_jdjg.SetItemText(1, 3, _T("规程5.2条"));

	m_list_jdjg.InsertItem(2, _T("3"));
	m_list_jdjg.SetItemText(2, 1, _T("示值误差"));
	m_list_jdjg.SetItemText(2, 2, _T("-0.01MPa"));
	m_list_jdjg.SetItemText(2, 3, _T("不超过±1.6%FS"));

	m_list_jdjg.InsertItem(3, _T("4"));
	m_list_jdjg.SetItemText(3, 1, _T("回程误差"));
	m_list_jdjg.SetItemText(3, 2, _T("0.00MPa"));
	m_list_jdjg.SetItemText(3, 3, _T("不大于1.6%FS"));

	m_list_jdjg.InsertItem(4, _T("5"));
	m_list_jdjg.SetItemText(4, 1, _T("轻敲位移"));
	m_list_jdjg.SetItemText(4, 2, _T("0.00MPa"));
	m_list_jdjg.SetItemText(4, 3, _T("不大于0.8%FS"));

	m_list_jdjg.InsertItem(5, _T("6"));
	m_list_jdjg.SetItemText(5, 1, _T("指针偏转平稳性"));
	m_list_jdjg.SetItemText(5, 2, _T("符合要求"));
	m_list_jdjg.SetItemText(5, 3, _T("指针偏转平稳，无跳动或卡针现象"));

	m_list_jdjg.InsertItem(6, _T("7"));
	m_list_jdjg.SetItemText(6, 1, _T("其他项目"));
	m_list_jdjg.SetItemText(6, 2, _T("/"));
	m_list_jdjg.SetItemText(6, 3, _T("/"));

	//
	m_proper_hysp.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	CMFCPropertyGridProperty *pGroup11 = new CMFCPropertyGridProperty(_T("核验"));
	CMFCPropertyGridProperty* pPropHY = new CMFCPropertyGridProperty(_T("是否合格"), _T("合格"), _T(""));
	pPropHY->AddOption(_T("不合格"));
	pGroup11->AddSubItem(pPropHY);
	m_mfcprogridpro_jcjg.push_back(pPropHY);

	CMFCPropertyGridProperty *pGroup22 = new CMFCPropertyGridProperty(_T("审批"));
	CMFCPropertyGridProperty* pPropSP = new CMFCPropertyGridProperty(_T("是否合格"), _T("合格"), _T(""));
	pPropSP->AddOption(_T("不合格"));
	pGroup22->AddSubItem(pPropSP);
	m_mfcprogridpro_jcjg.push_back(pPropSP);

	m_proper_hysp.AddProperty(pGroup11);
	m_proper_hysp.AddProperty(pGroup22);

	m_mfcprogridpro_jcjg.push_back(pGroup0);
	m_mfcprogridpro_jcjg.push_back(pGroup1);
	m_mfcprogridpro_jcjg.push_back(pGroup2);
	m_mfcprogridpro_jcjg.push_back(pGroup11);
	m_mfcprogridpro_jcjg.push_back(pGroup22);


	//动态布局  
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		if (pdlmanager->Create(this)) {
			pdlmanager->AddItem(m_Detection_ToolBar.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(m_list_d_yp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(20, 100));
			pdlmanager->AddItem(m_static_d_ypxx.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(20, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_list_d_ypxx.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(20, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(20, 100));
			pdlmanager->AddItem(m_static_d_jcsj.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_static_sshm.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_list_jcjg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 100));

			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L1)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L2)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L3)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L4)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L5)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L6)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L7)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L8)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L9)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L10)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L11)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L12)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L13)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L14)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L15)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L16)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L17)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L18)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L19)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L20)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L21)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_L22)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));



			pdlmanager->AddItem(m_static_jcjg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_proper_jdjg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(60, 0));
			pdlmanager->AddItem(m_static_jdjg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 100), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_static_cam.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(60, 100));
			pdlmanager->AddItem(m_proper_hysp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(60, 100));
			pdlmanager->AddItem(m_list_jdjg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 100), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));

			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_DD_FZX)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(m_static_hysp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(40, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CDetectionDlg::initYP_P()
{
	//属性控件
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_list_d_ypxx.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	//所有的属性指针要在析构函数里delete
	CMFCPropertyGridProperty *pGroup1 = new CMFCPropertyGridProperty(_T("样品信息"));
	CMFCPropertyGridProperty* pPropWTDH = new CMFCPropertyGridProperty(_T("委托编号"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropWTDH);
	CMFCPropertyGridProperty* pPropLZDH = new CMFCPropertyGridProperty(_T("流转编号"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropLZDH);
	CMFCPropertyGridProperty* pPropYPBH = new CMFCPropertyGridProperty(_T("样品编号"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropYPBH);
	m_mfcprogridpro_yp.push_back(pPropWTDH);
	m_mfcprogridpro_yp.push_back(pPropLZDH);
	m_mfcprogridpro_yp.push_back(pPropYPBH);

	CMFCPropertyGridProperty* pPropYPMC = new CMFCPropertyGridProperty(_T("样品名称"), _T("压力表"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Samplename.size(); i++) {
		pPropYPMC->AddOption(CStringW(g_dlg->m_dboperator.m_Samplename[i].ypmc.c_str()));

	}
	pPropYPMC->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropYPMC);
	m_mfcprogridpro_yp.push_back(pPropYPMC);

	CMFCPropertyGridProperty* pPropYPLC = new CMFCPropertyGridProperty(_T("量程"), _T("-0.1-0.06"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Model.size(); i++) {
		pPropYPLC->AddOption(CStringW(g_dlg->m_dboperator.m_Model[i].xhgg.c_str()));
	}
	pPropYPLC->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropYPLC);
	m_mfcprogridpro_yp.push_back(pPropYPLC);

	CMFCPropertyGridProperty* pPropYPZZDDJ = new CMFCPropertyGridProperty(_T("准确度等级"), _T("1.0"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Accclass.size(); i++) {
		pPropYPZZDDJ->AddOption(CStringW(g_dlg->m_dboperator.m_Accclass[i].zqddj.c_str()));
	}
	pPropYPZZDDJ->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropYPZZDDJ);
	m_mfcprogridpro_yp.push_back(pPropYPZZDDJ);


	CMFCPropertyGridProperty* pPropZXFDZ = new CMFCPropertyGridProperty(_T("最小分度值"), _T("0.04"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Minivalue.size(); i++) {
		pPropZXFDZ->AddOption(CStringW(g_dlg->m_dboperator.m_Minivalue[i].zxfdz.c_str()));
	}
	pPropZXFDZ->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropZXFDZ);
	m_mfcprogridpro_yp.push_back(pPropZXFDZ);

	CMFCPropertyGridProperty* pPropSCCS = new CMFCPropertyGridProperty(_T("生产厂商"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropYPJG = new CMFCPropertyGridProperty(_T("样品结果"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropTPBH = new CMFCPropertyGridProperty(_T("托盘编号"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropSCCS);
	pGroup1->AddSubItem(pPropYPJG);
	pGroup1->AddSubItem(pPropTPBH);
	m_mfcprogridpro_yp.push_back(pPropSCCS);
	m_mfcprogridpro_yp.push_back(pPropYPJG);
	m_mfcprogridpro_yp.push_back(pPropTPBH);

	CMFCPropertyGridProperty* pPropWGJC = new CMFCPropertyGridProperty(_T("外观检查"), _T("/"), _T(""));
	pPropWGJC->AddOption(_T("合格"));
	pPropWGJC->AddOption(_T("不合格"));
	pPropWGJC->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropWGJC);
	m_mfcprogridpro_yp.push_back(pPropWGJC);

	CMFCPropertyGridProperty* pPropLWJC = new CMFCPropertyGridProperty(_T("零位检查"), _T("/"), _T(""));
	pPropLWJC->AddOption(_T("合格"));
	pPropLWJC->AddOption(_T("不合格"));
	pPropLWJC->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropLWJC);
	m_mfcprogridpro_yp.push_back(pPropLWJC);

	CMFCPropertyGridProperty* pPropDQZT = new CMFCPropertyGridProperty(_T("当前状态"), _T("待检定"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_State.size(); i++) {
		pPropDQZT->AddOption(CStringW(g_dlg->m_dboperator.m_State[i].status.c_str()));
	}
	pPropDQZT->AllowEdit(FALSE);
	pGroup1->AddSubItem(pPropDQZT);
	m_mfcprogridpro_yp.push_back(pPropDQZT);
	m_mfcprogridpro_yp.push_back(pGroup1);

	m_list_d_ypxx.AddProperty(pGroup1);
}

void CDetectionDlg::setRole(ROLE role)
{
	m_role = role;
	initYP();
}

int  CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CTreeCtrl* pTreeCtrl = (CTreeCtrl*)lParamSort;
	HTREEITEM hTreeItem1 = (HTREEITEM)lParam1;
	HTREEITEM hTreeItem2 = (HTREEITEM)lParam2;

	TreeNodeData* p1, *p2;
	p1 = (TreeNodeData*)pTreeCtrl->GetItemData(hTreeItem1);
	p2 = (TreeNodeData*)pTreeCtrl->GetItemData(hTreeItem2);

	int nRank1 = p1->ypbh_id;
	int nRank2 = p2->ypbh_id;

	if (nRank1 < nRank2)
	{
		return -1;
	}
	else if (nRank1 > nRank2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CDetectionDlg::insertTreeItem(HTREEITEM item, map<int, string> info)
{
	map<int, string>::reverse_iterator  iter;
	for (iter = info.rbegin(); iter != info.rend(); iter++) {
		int sample_id = iter->first;
		string lzdh = iter->second;
		string wtdh = g_dlg->m_dboperator.getOrderIDbyLZDH(lzdh);
		CString showtxt;
		Sampleinfo sp = g_dlg->m_dboperator.getSampleinfobyYPBH_id(sample_id);
		string ypmc = g_dlg->m_dboperator.getSamplenamebyID(sp.ypmc_id);
		TreeNodeData *td = new TreeNodeData;
		*td = { wtdh, lzdh, sample_id };
		showtxt.Format(_T("(%03d)-%s-%s"), sample_id, CStringW(ypmc.c_str()), CStringW(sp.ypbh.c_str()));
		HTREEITEM hSubSubItem = m_list_d_yp.InsertItem(showtxt, item);
		m_list_d_yp.SetItemData(hSubSubItem, (DWORD_PTR)td);

	}
	//按样品信息ID排序
	/*TVSORTCB sortcb;
	sortcb.hParent = item;
	sortcb.lpfnCompare = MyCompareProc;
	sortcb.lParam = (LPARAM)&m_list_d_yp;
	m_list_d_yp.SortChildrenCB(&sortcb);*/
	m_list_d_yp.SortChildren(item);

	//展开
	expandTree(item);
}

void CDetectionDlg::initYP()
{
	m_list_d_yp.DeleteAllItems();
	//节点显示（1）-压力表-Y001   (样品信息id)-样品名称-样品编号
	//节点附加信息：样品信息-id，委托单号，流转单号
	map<int, string> info_state_1 = g_dlg->m_dboperator.getSampleID_LZDHbyState(1);
	map<int, string> info_state_2 = g_dlg->m_dboperator.getSampleID_LZDHbyState(2);
	map<int, string> info_state_3 = g_dlg->m_dboperator.getSampleID_LZDHbyState(3);
	map<int, string> info_state_4 = g_dlg->m_dboperator.getSampleID_LZDHbyState(4);
	map<int, string> info_state_5 = g_dlg->m_dboperator.getSampleID_LZDHbyState(5);

	HTREEITEM hSubItem1 = m_list_d_yp.InsertItem(CStringW("待检测"));
	HTREEITEM hSubItem2 = m_list_d_yp.InsertItem(CStringW("已检测"));
	HTREEITEM hSubItem3 = m_list_d_yp.InsertItem(CStringW("已检定"));
	HTREEITEM hSubItem4 = m_list_d_yp.InsertItem(CStringW("已核验"));
	HTREEITEM hSubItem5 = m_list_d_yp.InsertItem(CStringW("已审批"));

	insertTreeItem(hSubItem1, info_state_1);
	insertTreeItem(hSubItem2, info_state_2);
	insertTreeItem(hSubItem3, info_state_3);
	insertTreeItem(hSubItem4, info_state_4);
	insertTreeItem(hSubItem5, info_state_5);

	/////// 检定
	//样品list显示 待检测(1)、已检测(2)、已检定(3)
	if (m_role == ROLE(2)) {
		m_list_d_yp.DeleteItem(hSubItem4);
		m_list_d_yp.DeleteItem(hSubItem5);
	}
	/////// 核验&审批
	//样品list显示 已检定(3)、已核验(4)
	else if (m_role == ROLE(3)) {
		m_list_d_yp.DeleteItem(hSubItem1);
		m_list_d_yp.DeleteItem(hSubItem2);
		m_list_d_yp.DeleteItem(hSubItem5);
	}
	//样品list显示 已核验(4)、已审批(5)
	else if (m_role == ROLE(4)) {
		m_list_d_yp.DeleteItem(hSubItem1);
		m_list_d_yp.DeleteItem(hSubItem2);
		m_list_d_yp.DeleteItem(hSubItem3);
	}
	/////// 检定、核验&审批
	//样品list显示 待检测(1)，已检测(2)，已检定(3)，已核验(4)，已审批(5)
	else if (m_role == ROLE(5)) {
		;
	}

}

void CDetectionDlg::expandTree(HTREEITEM hTreeItem)
{
	if (!m_list_d_yp.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hChildItem;
	while (hTreeItem)
	{
		hChildItem = m_list_d_yp.GetChildItem(hTreeItem);
		if (hChildItem)
		{
			expandTree(hChildItem);
			m_list_d_yp.Expand(hTreeItem, TVE_EXPAND);
		}
		hTreeItem = m_list_d_yp.GetNextSiblingItem(hTreeItem);
	}
}



void CDetectionDlg::switchMode(bool isDetection)
{
	if (isDetection) {
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_YJD, false);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_WHY, false);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_D_SAVE, false);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_SUBMIT, true);
		m_static_sshm.ShowWindow(SW_SHOW);
		m_static_hysp.ShowWindow(SW_HIDE);
		m_static_cam.ShowWindow(SW_SHOW);
		m_proper_hysp.ShowWindow(SW_HIDE);
	}
	else {
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_YJD, true);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_WHY, true);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_SUBMIT, false);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_D_SAVE, true);
		m_Detection_ToolBar.GetToolBarCtrl().HideButton(ID_BUTTON_SUBMIT, false);
		m_static_sshm.ShowWindow(SW_HIDE);
		m_static_hysp.ShowWindow(SW_SHOW);
		m_static_cam.ShowWindow(SW_HIDE);
		m_proper_hysp.ShowWindow(SW_SHOW);
	}
}

void CDetectionDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	Invalidate(FALSE);
}


void CDetectionDlg::OnNMClickTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

#include <algorithm>
bool vec_comp(const Detailrst & a, const Detailrst & b)
{
	return a.id < b.id;
}

void CDetectionDlg::OnTvnSelchangedTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	HTREEITEM item = m_list_d_yp.GetSelectedItem();
	if (m_list_d_yp.ItemHasChildren(item)) return;
	TreeNodeData* td = (TreeNodeData*)m_list_d_yp.GetItemData(item);
	m_currentInfo.wtdbh = td->wtdbh;
	m_currentInfo.lzdh = td->lzdh;
	m_currentInfo.ypbh_id = td->ypbh_id;

	Sampleinfo si = g_dlg->m_dboperator.getSampleinfobyYPBH_id(td->ypbh_id);
	/////////样品信息
	//委托单编号
	m_mfcprogridpro_yp[0]->SetValue(_variant_t(td->wtdbh.c_str()));
	//流转单号
	m_mfcprogridpro_yp[1]->SetValue(_variant_t(td->lzdh.c_str()));
	//样品编号
	m_mfcprogridpro_yp[2]->SetValue(_variant_t(si.ypbh.c_str()));
	//样品名称
	string ypmc = g_dlg->m_dboperator.getSamplenamebyID(si.ypmc_id);
	m_mfcprogridpro_yp[3]->SetValue(_variant_t(ypmc.c_str()));
	//型号规格
	string xhgg = g_dlg->m_dboperator.getModelbyID(si.xhgg);
	m_mfcprogridpro_yp[4]->SetValue(_variant_t(xhgg.c_str()));
	//准确度等级
	string zqddj = g_dlg->m_dboperator.getAccclassbyID(si.zqddj_id);
	m_mfcprogridpro_yp[5]->SetValue(_variant_t(zqddj.c_str()));
	//最小分度值
	string zxfdz = g_dlg->m_dboperator.getMinivaluebyID(si.zxfdz_id);
	m_mfcprogridpro_yp[6]->SetValue(_variant_t(zxfdz.c_str()));
	//生产厂商
	m_mfcprogridpro_yp[7]->SetValue(_variant_t(si.sccs.c_str()));
	//样品结果 8
	//托盘编号 9
	//外观-零位检查 10-11
	vector<string>  wglw = g_dlg->m_dboperator.getWG_LWJCbyID(si.id);
	m_mfcprogridpro_yp[10]->SetValue(_variant_t(wglw[0].c_str()));
	m_mfcprogridpro_yp[11]->SetValue(_variant_t(wglw[1].c_str()));
	//当前状态 12
	string dqzt = g_dlg->m_dboperator.getStatebyID(si.dqzt);
	m_mfcprogridpro_yp[12]->SetValue(_variant_t(dqzt.c_str()));
	Samplerst srst;
	g_dlg->m_dboperator.getSamplerstbyID(srst, td->ypbh_id);
	/////////检测数据
	vector<Detailrst> detrsts = g_dlg->m_dboperator.getDetailrstbyJGBH(srst.jgbh);
	sort(detrsts.begin(), detrsts.end(), vec_comp);

	m_list_jcjg.DeleteAllItems();
	for (int i = 0; i < detrsts.size(); i++) {
		m_list_jcjg.InsertItem(i, CStringW(detrsts[i].bzz.c_str()));
		m_list_jcjg.SetItemText(i, 1, CStringW(detrsts[i].syy.c_str()));
		m_list_jcjg.SetItemText(i, 2, CStringW(detrsts[i].jyy.c_str()));
		m_list_jcjg.SetItemText(i, 3, CStringW(detrsts[i].sye.c_str()));
		m_list_jcjg.SetItemText(i, 4, CStringW(detrsts[i].jye.c_str()));
		m_list_jcjg.SetItemText(i, 5, CStringW(detrsts[i].qqwyy.c_str()));
		m_list_jcjg.SetItemText(i, 6, CStringW(detrsts[i].qqwye.c_str()));
	}
	/////////检测结果
	//检定依据
	Detrst detrst = g_dlg->m_dboperator.getDetrstbyJGBH(srst.jgbh);
	string jdyj = g_dlg->m_dboperator.getVerifyBasisbyID(detrst.jdyj);
	m_mfcprogridpro_jcjg[0]->SetValue(_variant_t(jdyj.c_str()));
	//计量标准
	CString jlbz_s;
	Measurestd msd = g_dlg->m_dboperator.getMeasurestdbyID(detrst.jlbz);
	jlbz_s.Format(_T("%s-%s"), CStringW(msd.mc.c_str()), CStringW(msd.zsbh.c_str()));
	m_mfcprogridpro_jcjg[1]->SetValue(jlbz_s);
	//计量器具
	string jlqj = g_dlg->m_dboperator.getMeasureistbyID(detrst.jlqj).mc;
	m_mfcprogridpro_jcjg[2]->SetValue(_variant_t(jlqj.c_str()));
	//技术要求
	m_mfcprogridpro_jcjg[3]->SetValue(_variant_t("/"));
	//最大示值误差
	CString zdszwc_s;
	zdszwc_s.Format(_T("%.2f"), srst.zdszwc);
	m_mfcprogridpro_jcjg[4]->SetValue(zdszwc_s);
	//最大回程误差
	CString zdhcwc_s;
	zdhcwc_s.Format(_T("%.2f"), srst.zdhcwc);
	m_mfcprogridpro_jcjg[5]->SetValue(zdhcwc_s);
	//最大轻敲位移
	CString zdqqwy_s;
	zdqqwy_s.Format(_T("%.2f"), srst.zdqqwy);
	m_mfcprogridpro_jcjg[6]->SetValue(zdqqwy_s);
	//零位误差
	//CString lwwc_s;
	//lwwc_s.Format(_T("%.2f"), srst.lwwc);
	m_mfcprogridpro_jcjg[7]->SetValue(_variant_t(srst.lwjc.c_str()));
	//最终结果
	//m_mfcprogridpro_jcjg[8]->RemoveAllOptions();
	/*CString o1, o2;
	o1.Format(_T("%s 级 合格"), CStringW(zqddj.c_str()));
	o1.Format(_T("%s 级 不合格"), CStringW(zqddj.c_str()));
	m_mfcprogridpro_jcjg[8]->SetValue(o1);
	m_mfcprogridpro_jcjg[8]->AddOption(o2);*/
	m_mfcprogridpro_jcjg[8]->SetValue(_variant_t(detrst.jdjl.c_str()));
	/////////检定结果
	/////////核验结果
	m_mfcprogridpro_jcjg[9]->SetValue(_variant_t(srst.hyjg.c_str()));
	/////////审批结果
	m_mfcprogridpro_jcjg[10]->SetValue(_variant_t(srst.spjg.c_str()));
}

void CDetectionDlg::OnSubmit()
{
	CViewReportDlg pDlg;
	CViewReportDlg::m_currentType = JDZS;
	CViewReportDlg::m_detinfo = g_dlg->m_dboperator.getDetectionInfo(m_currentInfo.wtdbh, m_currentInfo.lzdh, m_currentInfo.ypbh_id);
	CViewReportDlg::m_template_FileName = (CStringA)g_dlg->m_configDlg.m_detectiontemplate.GetBuffer();
	CString save_filename;
	save_filename.Format(_T("%s%s_%s_[%s].pdf"), g_dlg->m_configDlg.m_detection_dir, 
		CStringW(m_currentInfo.wtdbh.c_str()), CStringW(m_currentInfo.lzdh.c_str()), CStringW(CViewReportDlg::m_detinfo.m_zsbh.c_str()).TrimRight());
	CViewReportDlg::m_save_FileName = (CStringA)save_filename.GetBuffer();
	pDlg.DoModal();
}


