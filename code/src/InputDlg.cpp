// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "InputDlg.h"
#include "afxdialogex.h"
#include "MyPropertyGrid.h"
#include "AIDetectionDlg.h"
#include "PGCalculation.h"

// CInputDlg 对话框
CAIDetectionDlg *g_dlg = nullptr;
IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)
extern date stringtodate(string d);
CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUTDLG, pParent)
{
	m_currentInfo.ypbh_id = -1;
}

CInputDlg::~CInputDlg()
{
	m_Input_ImageList.DeleteImageList();
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_WTD, m_tree_wtd);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_YP, m_proper_yp);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_LZD, m_proper_lzd);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_WTD, m_proper_wtd);
	DDX_Control(pDX, IDC_STATIC_FZX, m_static_fgx);
	DDX_Control(pDX, IDC_STATIC_YPXI, m_static_ypxi);
	DDX_Control(pDX, IDC_STATIC_LZXI, m_static_lzxx);
	DDX_Control(pDX, IDC_STATIC_WTXX, m_static_wtxx);
	DDX_Control(pDX, IDC_STATIC_YP, m_static_yp);
	DDX_Control(pDX, IDC_STATIC_WTLZ, m_static_wtlz);
	DDX_Control(pDX, IDC_EDIT_SEARCH, m_edit_search);
	DDX_Control(pDX, IDC_SPLIT_SEARCH, m_splitbotton_search);
	DDX_Control(pDX, IDC_LIST_YP, m_listctrl_yp);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_WM_SIZE()
	ON_COMMAND(ID_MENU_SEARCH_WTD, &CInputDlg::OnMenuSearchWtd)
	ON_COMMAND(ID_MENU_SEARCH_LZD, &CInputDlg::OnMenuSearchLzd)
	ON_COMMAND(ID_MENU_SEARCH_WTGS, &CInputDlg::OnMenuSearchWtgs)
	ON_COMMAND(ID_MENU_SEARCH_SJDW, &CInputDlg::OnMenuSearchSjdw)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_WTD, &CInputDlg::OnDblclkTreeWtd)
	ON_NOTIFY(NM_CLICK, IDC_TREE_WTD, &CInputDlg::OnClickTreeWtd)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_WTD, &CInputDlg::OnSelchangedTreeWtd)
	ON_NOTIFY(NM_CLICK, IDC_LIST_YP, &CInputDlg::OnNMClickListYp)

	ON_COMMAND(ID_BUTTON_WTD_NEW, &OnNewWTD)
	ON_COMMAND(ID_BUTTON_WTD_MOD, &OnModWTD)
	ON_COMMAND(ID_BUTTON_WTD_DEL, &OnDelWTD)
	ON_COMMAND(ID_BUTTON_LZD_NEW, &OnNewLZD)
	ON_COMMAND(ID_BUTTON_LZD_MOD, &OnModLZD)
	ON_COMMAND(ID_BUTTON_LZD_DEL, &OnDelLZD)
	ON_COMMAND(ID_BUTTON_SP_NEW, &OnNewSample)
	ON_COMMAND(ID_BUTTON_SP_MOD, &OnModSample)
	ON_COMMAND(ID_BUTTON_SP_DEL, &OnDelSample)
	ON_COMMAND(ID_BUTTON_LAST, &OnLastSample)
	ON_COMMAND(ID_BUTTON_NEXT, &OnNextSample)
	ON_COMMAND(ID_BUTTON_SAVE, &OnSaveSampleInfo)
	ON_COMMAND(ID_BUTTON_GENERATE, &OnExportWTD)
	ON_COMMAND(ID_BUTTON_VIEW_DET, &OnViewDetResult)
	ON_COMMAND(ID_BUTTON_VIEW_WTD, &OnViewWTD)
	ON_COMMAND(ID_BUTTON_VIEW_JDZS, &OnViewJDZS)

END_MESSAGE_MAP()


// CInputDlg 消息处理程序


void CInputDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	/*CRect test;
	GetClientRect(&test);
	char s[64] = {0};
	sprintf_s(s, "InputDlg top: %d left: %d bottom: %d right: %d \n", test.top, test.left, test.bottom, test.right);
	OutputDebugString(CString(s).GetBuffer());*/

	//CRect test1;
	//CButton* p = (CButton*)GetDlgItem(IDC_BUTTON1);
	//if (!p)
	//	return;
	//p->GetWindowRect(&test1);//获取控件的屏幕坐标
	//ScreenToClient(&test1);//转换为对话框上的客户坐标
	//char s1[64] = { 0 };
	//sprintf_s(s1, "Botton top: %d left: %d bottom: %d right: %d \n", test1.top, test1.left, test1.bottom, test1.right);
	//OutputDebugString(CString(s1).GetBuffer());
}


BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	g_dlg = (CAIDetectionDlg*)(this->GetParent());

	// TODO:  在此添加额外的初始化
	//初始化工具栏
	m_Input_ImageList.Create(18, 18, ILC_COLOR24 | ILC_MASK, 0, 1);
	for (int i = 0; i < 16; i++)
	{
		m_Input_ImageList.Add(AfxGetApp()->LoadIconW(IDI_ICON_WT_NEW + i));
	}

	if (!m_Input_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | 
		WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_Input_ToolBar.LoadToolBar(IDR_TOOLBAR_INPUT))
	{
		EndDialog(IDCANCEL);
	}
	m_Input_ToolBar.SetSizes(CSize(36,40), CSize(18, 18));
	m_Input_ToolBar.GetToolBarCtrl().SetImageList(&m_Input_ImageList);
	//m_Input_ToolBar.ModifyStyle(0, BTNS_SHOWTEXT | TBSTYLE_EX_MIXEDBUTTONS | TBSTYLE_LIST);
	m_Input_ToolBar.ModifyStyle(0, BTNS_SHOWTEXT | TBSTYLE_EX_MIXEDBUTTONS );
	m_Input_ToolBar.SetButtonText(0, _T("新建委托单"));
	m_Input_ToolBar.SetButtonText(1, _T("修改委托单"));
	m_Input_ToolBar.SetButtonText(2, _T("删除委托单"));
	m_Input_ToolBar.SetButtonText(4, _T("新建流转单"));
	m_Input_ToolBar.SetButtonText(5, _T("修改流转单"));
	m_Input_ToolBar.SetButtonText(6, _T("删除流转单"));
	m_Input_ToolBar.SetButtonText(8, _T("新建样品"));
	m_Input_ToolBar.SetButtonText(9, _T("修改样品"));
	m_Input_ToolBar.SetButtonText(10, _T("删除样品"));
	m_Input_ToolBar.SetButtonText(12, _T("上一个"));
	m_Input_ToolBar.SetButtonText(13, _T("下一个"));
	m_Input_ToolBar.SetButtonText(15, _T("保存"));
	m_Input_ToolBar.SetButtonText(16, _T("生成委托单"));
	m_Input_ToolBar.SetButtonText(18, _T("检测结果"));
	m_Input_ToolBar.SetButtonText(19, _T("委托单"));
	m_Input_ToolBar.SetButtonText(20, _T("检定证书"));

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	for (int i = 1; i < 17; i++) {
		m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_NEW + i, false);
	}

	initWTLZ();

	initYP_P();
	initLZD_P();
	initWTD_P();

	m_current_button_state = VIEW;
	m_current_tree_item = nullptr;

	m_splitbotton_search.SetDropDownMenu(IDR_MENU_SEARCH_WTLZ, 0);

	//动态布局  
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		if (pdlmanager->Create(this)) {
			pdlmanager->AddItem(m_Input_ToolBar.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(m_tree_wtd.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(50, 100));
			pdlmanager->AddItem(m_listctrl_yp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(50, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(50, 100));
			pdlmanager->AddItem(m_static_fgx.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(m_proper_yp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 100));
			pdlmanager->AddItem(m_proper_lzd.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 100));
			pdlmanager->AddItem(m_proper_wtd.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 100));
			pdlmanager->AddItem(m_static_ypxi.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_static_lzxx.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_static_wtxx.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(100, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_edit_search.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(50, 0));
			pdlmanager->AddItem(m_splitbotton_search.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(50, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_static_yp.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(50, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CInputDlg::initWTLZ()
{
	m_tree_wtd.DeleteAllItems();
	for (int i = 0; i < g_dlg->m_dboperator.m_OrderBase.size(); i++) {
		CString wtdh_s, wtdw_s, sjdw_s;
		string wtdh = g_dlg->m_dboperator.m_OrderBase[i].m_wtdbh;
		string wtdw = g_dlg->m_dboperator.m_OrderBase[i].m_wtdw;
		string sjdw = g_dlg->m_dboperator.m_OrderBase[i].m_sjdwqc;
		wtdh_s.Format(_T("委托单号：%s"), CStringW(wtdh.c_str()));
		wtdw_s.Format(_T("委托单位：%s"), CStringW(wtdw.c_str()));
		sjdw_s.Format(_T("受检单位：%s"), CStringW(sjdw.c_str()));

		HTREEITEM hSubItem = m_tree_wtd.InsertItem(wtdh_s);
		HTREEITEM hSubSubItem_1 = m_tree_wtd.InsertItem(wtdw_s, hSubItem);
		HTREEITEM hSubSubItem_2 = m_tree_wtd.InsertItem(sjdw_s, hSubItem);

		vector<Circulation> cir = g_dlg->m_dboperator.getCirculationVecbyWTDH(wtdh);
		for each (auto c in cir)
		{
			if (c._state == DELETED)
				continue;

			CString lzdh_s;
			string lzdh = c.lzdh;
			lzdh_s.Format(_T("流转单号：%s"), CStringW(lzdh.c_str()));
			HTREEITEM hSubSubItem = m_tree_wtd.InsertItem(lzdh_s, hSubSubItem_2);

			TreeNodeData* pNd = new TreeNodeData;
			pNd->wtdbh = wtdh.c_str();
			pNd->lzdh = lzdh.c_str();

			if (g_dlg->m_dboperator.m_Sampleinfo.size()>0) {
				pNd->ypbh_id = g_dlg->m_dboperator.m_Sampleinfo[0].id;
			}
			else {
				pNd->ypbh_id = -1;
			}

			m_tree_wtd.SetItemData(hSubSubItem, (DWORD_PTR)pNd);
			//int l1 = sizeof(DWORD_PTR);
			//int l2 = sizeof(pNd);
		}

		expandTree(hSubItem);
		expandTree(hSubSubItem_2);
	}
}


void CInputDlg::OnSelchangedTreeWtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	HTREEITEM item = m_tree_wtd.GetSelectedItem();
	m_current_tree_item = item;
	CString a = m_tree_wtd.GetItemText(item);
	if (a.Find(_T("流转单号")) < 0) {
		m_tree_wtd.SetItemState(item, 0, TVIS_SELECTED);
		return;
	}
	if (m_current_button_state == NEW_WTD) {
		return;
	}

	if (m_current_button_state != VIEW) {
		/*	if (saveModifyornot() == 0) {
		*pResult = 1;
		return;
		}*/
		saveModifyornot();
	}
	item = m_tree_wtd.GetSelectedItem();
	if (item == nullptr)
		return;
	TreeNodeData* td = (TreeNodeData*)m_tree_wtd.GetItemData(item);
	if (td == nullptr)
		return;
	m_currentInfo = *td;
	initYP();

	//for (int i = 0; i < 14; i++) {
	//	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_NEW + i, true);
	//	if (i > 7 && i < 14) {
	//		m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_NEW + i, false);
	//	}
	//}

	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_NEW, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_MOD, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_WTD_DEL, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LZD_NEW, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LZD_MOD, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LZD_DEL, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_NEW, true);

	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_GENERATE, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);

	//委托单存在则按钮可用，否则不可用
	CString wtd_path, temp;
	current_WTD_JDZS_paths(wtd_path, temp);
	if(!PathFileExists(wtd_path)){
		m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_WTD, false);
	}
	else {
		m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_WTD, true);
	}

	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_DET, false);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_JDZS, false);

	/////////流转单信息
	showLZD_info();
	/////////委托单信息
	showWTD_info();

	//属性控件
	m_mfcprogridpro_yp.back()->Expand(false);
	m_proper_yp.EnableWindow(false);
	m_mfcprogridpro_lzd.back()->Expand(true);
	m_proper_lzd.EnableWindow(false);
	m_mfcprogridpro_wtd.back()->Expand(true);
	m_proper_wtd.EnableWindow(false);

	Invalidate(false);
}


void CInputDlg::initYP(bool isupdate )
{
	m_listctrl_yp.DeleteAllItems();

	vector<Sampleinfo> sp = g_dlg->m_dboperator.getSampleinfoVecbyLZDH(m_currentInfo.lzdh);
	int index = 0;
	for (int i = 0; i < sp.size(); i++)
	{
		if (sp[i]._state == DELETED)
			continue;
		CString ypmc_s;
		int id = sp[i].id;
		string ypbh = sp[i].ypbh;
		int ypmc_id =sp[i].ypmc_id;
		string ypmc = g_dlg->m_dboperator.getSamplenamebyID(ypmc_id);
		//ypmc_s.Format(_T("(%03d)-%s-%s"), id, CStringW(ypmc.c_str()), CStringW(ypbh.c_str()));
		ypmc_s.Format(_T("%s-%s"), CStringW(ypbh.c_str()), CStringW(ypmc.c_str()));
		m_listctrl_yp.InsertItem(index, ypmc_s);
		m_listctrl_yp.SetItemData(index, (DWORD)id);
		index++;
	}
}

void CInputDlg::initYP_P()
{
	//属性控件
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_yp.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	vector<Sampleinfo> sp = g_dlg->m_dboperator.getSampleinfoVecbyLZDH(m_currentInfo.lzdh);
	//所有的属性指针要在析构函数里delete
	CMFCPropertyGridProperty *pGroup1 = new CMFCPropertyGridProperty(_T("样品信息"));

	CMFCPropertyGridProperty* pPropYPBH = new CMFCPropertyGridProperty(_T("样品编号"), (_variant_t)_T("00000001"), _T(""));
	pGroup1->AddSubItem(pPropYPBH);
	//-0
	m_mfcprogridpro_yp.push_back(pPropYPBH);

	CMFCPropertyGridProperty* pPropYPMC = new CMFCPropertyGridProperty(_T("样品名称"), _T("压力表"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Samplename.size(); i++) {
		pPropYPMC->AddOption(CStringW(g_dlg->m_dboperator.m_Samplename[i].ypmc.c_str()));

	}
	pGroup1->AddSubItem(pPropYPMC);
	//-1
	m_mfcprogridpro_yp.push_back(pPropYPMC);

	CMFCPropertyGridProperty* pPropYPLC = new CMFCPropertyGridProperty(_T("量程"), _T("(-0.1-0.06)MPa"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Model.size(); i++) {
		pPropYPLC->AddOption(CStringW(g_dlg->m_dboperator.m_Model[i].xhgg.c_str()));
	}
	pGroup1->AddSubItem(pPropYPLC);
	//-2
	m_mfcprogridpro_yp.push_back(pPropYPLC);

	CMFCPropertyGridProperty* pPropYPZZDDJ = new CMFCPropertyGridProperty(_T("准确度等级"), _T("1.0"),_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Accclass.size(); i++) {
		pPropYPZZDDJ->AddOption(CStringW(g_dlg->m_dboperator.m_Accclass[i].zqddj.c_str()));
	}
	pGroup1->AddSubItem(pPropYPZZDDJ);
	//-3
	m_mfcprogridpro_yp.push_back(pPropYPZZDDJ);


	CMFCPropertyGridProperty* pPropZXFDZ = new CMFCPropertyGridProperty(_T("最小分度值"), _T(""),_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Minivalue.size(); i++) {
		pPropZXFDZ->AddOption(CStringW(g_dlg->m_dboperator.m_Minivalue[i].zxfdz.c_str()));
	}
	pGroup1->AddSubItem(pPropZXFDZ);
	//-4
	m_mfcprogridpro_yp.push_back(pPropZXFDZ);

	CMFCPropertyGridProperty* pPropZDYXWC = new CMFCPropertyGridProperty(_T("最大允许误差"), _T(""), _T(""));
	pGroup1->AddSubItem(pPropZDYXWC);
	//-5
	m_mfcprogridpro_yp.push_back(pPropZDYXWC);

	CMFCPropertyGridProperty* pPropSCCS = new CMFCPropertyGridProperty(_T("生产厂商"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropTPBH = new CMFCPropertyGridProperty(_T("托盘编号"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropSCCS);
	pGroup1->AddSubItem(pPropTPBH);

	//-6
	m_mfcprogridpro_yp.push_back(pPropSCCS);
	//-7
	m_mfcprogridpro_yp.push_back(pPropTPBH);

	CMFCPropertyGridProperty* pPropWGJC = new CMFCPropertyGridProperty(_T("外观检查"), _T("/"),_T(""));
	pPropWGJC->AddOption(_T("合格"));
	pPropWGJC->AddOption(_T("不合格"));
	pGroup1->AddSubItem(pPropWGJC);
	//-8
	m_mfcprogridpro_yp.push_back(pPropWGJC);

	CMFCPropertyGridProperty* pPropLWJC = new CMFCPropertyGridProperty(_T("零位检查"), _T("/"),_T(""));
	pPropLWJC->AddOption(_T("合格"));
	pPropLWJC->AddOption(_T("不合格"));
	pGroup1->AddSubItem(pPropLWJC);
	//-9
	m_mfcprogridpro_yp.push_back(pPropLWJC);

	CMFCPropertyGridProperty* pPropDQZT = new CMFCPropertyGridProperty(_T("当前状态"), _T("待检定"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_State.size(); i++) {
		pPropDQZT->AddOption(CStringW(g_dlg->m_dboperator.m_State[i].status.c_str()));
	}
	pGroup1->AddSubItem(pPropDQZT);
	//-10
	m_mfcprogridpro_yp.push_back(pPropDQZT);
	//-11
	m_mfcprogridpro_yp.push_back(pGroup1);

	m_proper_yp.AddProperty(pGroup1);

	//初始属性栏状态
	pGroup1->Expand(false);
	m_proper_yp.EnableWindow(false);
}

void CInputDlg::canNotMod_P(int index)
{
	if (index == 0) {
		m_mfcprogridpro_yp[0]->Enable(false);
		m_mfcprogridpro_yp[5]->Enable(false);
		m_mfcprogridpro_yp[7]->Enable(false);
		m_mfcprogridpro_yp[10]->Enable(false);
	}
	else if(index == 1) {
		m_mfcprogridpro_lzd[0]->Enable(false);
		m_mfcprogridpro_lzd[2]->Enable(false);
		m_mfcprogridpro_lzd[3]->Enable(false);
		m_mfcprogridpro_lzd[4]->Enable(false);
		m_mfcprogridpro_lzd[5]->Enable(false);
		m_mfcprogridpro_lzd[6]->Enable(false);
	}
	else if (index == 2) {
		m_mfcprogridpro_wtd[0]->Enable(false);
	}
}

void CInputDlg::initLZD_P()
{
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_wtd.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	CMFCPropertyGridProperty *pGroup2 = new CMFCPropertyGridProperty(_T("流转单信息"));
	CMFCPropertyGridProperty* pPropLZDBH = new CMFCPropertyGridProperty(_T("流转单编号"), (_variant_t)_T("00000001"), _T(""));
	pGroup2->AddSubItem(pPropLZDBH);
	m_mfcprogridpro_lzd.push_back(pPropLZDBH);

	CMFCPropertyGridProperty* pPropJLQJMC1 = new CMFCPropertyGridProperty(_T("计量器具名称"), _T("复合式气体检测报警器"), _T(""));
	pPropJLQJMC1->AddOption(_T("电流传感器"));
	pPropJLQJMC1->AddOption(_T("电池测试系统"));
	pPropJLQJMC1->AddOption(_T("RTU检定装置"));
	pGroup2->AddSubItem(pPropJLQJMC1);
	m_mfcprogridpro_lzd.push_back(pPropJLQJMC1);

	CMFCPropertyGridProperty* pPropZQDDJ = new CMFCPropertyGridProperty(_T("准确度等级"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropCLFW = new CMFCPropertyGridProperty(_T("测量范围"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropXHGG = new CMFCPropertyGridProperty(_T("型号规格"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropCCBH = new CMFCPropertyGridProperty(_T("出厂编号"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSL = new CMFCPropertyGridProperty(_T("数量"), (_variant_t)_T("0"), _T(""));
	CMFCPropertyGridProperty* pPropFJ = new CMFCPropertyGridProperty(_T("附件"), (_variant_t)_T("无"), _T(""));
	CMFCPropertyGridProperty* pPropQJLX = new CMFCPropertyGridProperty(_T("强检类型"), (_variant_t)_T("0"), _T(""));
	CMFCPropertyGridProperty* pPropFWFS = new CMFCPropertyGridProperty(_T("服务方式"), (_variant_t)_T("常规"), _T(""));
	pGroup2->AddSubItem(pPropZQDDJ);
	pGroup2->AddSubItem(pPropCLFW);
	pGroup2->AddSubItem(pPropXHGG);
	pGroup2->AddSubItem(pPropCCBH);
	pGroup2->AddSubItem(pPropSL);
	pGroup2->AddSubItem(pPropFJ);
	pGroup2->AddSubItem(pPropQJLX);
	pGroup2->AddSubItem(pPropFWFS);
	m_mfcprogridpro_lzd.push_back(pPropZQDDJ);
	m_mfcprogridpro_lzd.push_back(pPropCLFW);
	m_mfcprogridpro_lzd.push_back(pPropXHGG);
	m_mfcprogridpro_lzd.push_back(pPropCCBH);
	m_mfcprogridpro_lzd.push_back(pPropSL);
	m_mfcprogridpro_lzd.push_back(pPropFJ);
	m_mfcprogridpro_lzd.push_back(pPropQJLX);
	m_mfcprogridpro_lzd.push_back(pPropFWFS);

	CMFCPropertyGridProperty* pPropJCLX = new CMFCPropertyGridProperty(_T("服务类型"), _T("检定"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Servicetype.size(); i++) {
		pPropJCLX->AddOption(CStringW(g_dlg->m_dboperator.m_Servicetype[i].fwlx.c_str()));
	}
	pGroup2->AddSubItem(pPropJCLX);
	m_mfcprogridpro_lzd.push_back(pPropJCLX);

	CMFCPropertyGridProperty* pPropJBJCF = new CMFCPropertyGridProperty(_T("基本检测费"), (_variant_t)_T("0"), _T(""));
	pGroup2->AddSubItem(pPropJBJCF);
	m_mfcprogridpro_lzd.push_back(pPropJBJCF);

	CMFCPropertyGridProperty* pPropBZ = new CMFCPropertyGridProperty(_T("备注"), (_variant_t)_T("同意受托方所选定的方法"), _T(""));
	pGroup2->AddSubItem(pPropBZ);
	m_mfcprogridpro_lzd.push_back(pPropBZ);

	CMFCPropertyGridProperty *pPropQJRQ = new CMFCPropertyGridDateTimeProperty(_T("取件时间"), _T("2022-10-1"), _T("请选择日期"), true);
	pGroup2->AddSubItem(pPropQJRQ);
	m_mfcprogridpro_lzd.push_back(pPropQJRQ);

	CMFCPropertyGridProperty *pPropQJDD= new CMFCPropertyGridProperty(_T("取件地点"), (_variant_t)_T("张江"), _T(""));
	pGroup2->AddSubItem(pPropQJDD);
	m_mfcprogridpro_lzd.push_back(pPropQJDD);

	CMFCPropertyGridProperty *pPropLQR = new CMFCPropertyGridProperty(_T("领取人"), (_variant_t)_T(""), _T(""));
	pGroup2->AddSubItem(pPropLQR);
	m_mfcprogridpro_lzd.push_back(pPropLQR);

	CMFCPropertyGridProperty *pPropLQJRQ = new CMFCPropertyGridDateTimeProperty(_T("领取日期"), _T("2022-10-1"), _T("请选择日期"), true);
	pGroup2->AddSubItem(pPropLQJRQ);
	m_mfcprogridpro_lzd.push_back(pPropLQJRQ);

	m_proper_lzd.AddProperty(pGroup2);
	m_mfcprogridpro_lzd.push_back(pGroup2);

	//初始属性栏状态
	pGroup2->Expand(false);
	m_proper_lzd.EnableWindow(false);
}

void CInputDlg::initWTD_P()
{
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_wtd.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	CMFCPropertyGridProperty *pGroup3 = new CMFCPropertyGridProperty(_T("委托单信息"));
	CMFCPropertyGridProperty* pPropWTDBH = new CMFCPropertyGridProperty(_T("委托单编号"), (_variant_t)_T("00000001"), _T(""));
	pGroup3->AddSubItem(pPropWTDBH);
	m_mfcprogridpro_wtd.push_back(pPropWTDBH);

	CMFCPropertyGridProperty* pPropTT = new CMFCPropertyGridProperty(_T("抬头"), (_variant_t)_T("上海市计量测试技术研究院"), _T(""));
	CMFCPropertyGridProperty* pPropWTDWQC = new CMFCPropertyGridProperty(_T("委托单位全称"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJDWQC = new CMFCPropertyGridProperty(_T("受检单位全称"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJDWDZ = new CMFCPropertyGridProperty(_T("受检单位地址"), (_variant_t)_T(""), _T(""));
	pGroup3->AddSubItem(pPropTT);
	pGroup3->AddSubItem(pPropWTDWQC);
	pGroup3->AddSubItem(pPropSJDWQC);
	pGroup3->AddSubItem(pPropSJDWDZ);
	m_mfcprogridpro_wtd.push_back(pPropTT);
	m_mfcprogridpro_wtd.push_back(pPropWTDWQC);
	m_mfcprogridpro_wtd.push_back(pPropSJDWQC);
	m_mfcprogridpro_wtd.push_back(pPropSJDWDZ);

	CMFCPropertyGridProperty* pPropSJDWLX = new CMFCPropertyGridProperty(_T("受检单位类型"), _T("企业"),_T(""));
	pPropSJDWLX->AddOption(_T("其他"));
	pGroup3->AddSubItem(pPropSJDWLX);
	m_mfcprogridpro_wtd.push_back(pPropSJDWLX);

	CMFCPropertyGridProperty* pPropSJDWDM = new CMFCPropertyGridProperty(_T("受检单位组织机构代码"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropHTBH = new CMFCPropertyGridProperty(_T("合同编号"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropLXR = new CMFCPropertyGridProperty(_T("联系人"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJ = new CMFCPropertyGridProperty(_T("手机"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropLXDH = new CMFCPropertyGridProperty(_T("联系电话"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropKHYQ = new CMFCPropertyGridProperty(_T("客户要求"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSLR = new CMFCPropertyGridProperty(_T("受理人"), (_variant_t)_T(""), _T(""));
	pGroup3->AddSubItem(pPropSJDWDM);
	pGroup3->AddSubItem(pPropHTBH);
	pGroup3->AddSubItem(pPropLXR);
	pGroup3->AddSubItem(pPropSJ);
	pGroup3->AddSubItem(pPropLXDH);
	pGroup3->AddSubItem(pPropKHYQ);
	pGroup3->AddSubItem(pPropSLR);
	m_mfcprogridpro_wtd.push_back(pPropSJDWDM);
	m_mfcprogridpro_wtd.push_back(pPropHTBH);
	m_mfcprogridpro_wtd.push_back(pPropLXR);
	m_mfcprogridpro_wtd.push_back(pPropSJ);
	m_mfcprogridpro_wtd.push_back(pPropLXDH);
	m_mfcprogridpro_wtd.push_back(pPropKHYQ);
	m_mfcprogridpro_wtd.push_back(pPropSLR);

	CMFCPropertyGridProperty *pPropSLRQ = new CMFCPropertyGridDateTimeProperty(_T("受理日期"), _T("2022-10-1"), _T("请选择日期"), true);
	pGroup3->AddSubItem(pPropSLRQ);
	m_mfcprogridpro_wtd.push_back(pPropSLRQ);
	m_mfcprogridpro_wtd.push_back(pGroup3);

	m_proper_wtd.AddProperty(pGroup3);

	//初始属性栏状态
	pGroup3->Expand(false);
	m_proper_wtd.EnableWindow(false);
}

void CInputDlg::expandTree(HTREEITEM hTreeItem)
{
	if (!m_tree_wtd.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hChildItem;
	while (hTreeItem)
	{
		hChildItem = m_tree_wtd.GetChildItem(hTreeItem);
		if (hChildItem)
		{
			expandTree(hChildItem);
			m_tree_wtd.Expand(hTreeItem, TVE_EXPAND);
		}
		hTreeItem = m_tree_wtd.GetNextSiblingItem(hTreeItem);
	}
}


void CInputDlg::viewPDF(CString pdfDir)
{
	CWebBrowser2 m_Web;
	CRect rect;
	GetClientRect(&rect);
	m_Web.Create(NULL, WS_CHILD | WS_VISIBLE, rect, this, NULL);
	m_Web.Navigate(pdfDir, NULL, NULL, NULL, NULL);
	m_Web.SetResizable(TRUE);
}

void CInputDlg::showYP_info(int id)
{
	//样品编号
	Sampleinfo si = g_dlg->m_dboperator.getSampleinfobyYPBH_id(id);
	m_mfcprogridpro_yp[0]->SetValue(_variant_t(si.ypbh.c_str()));
	//样品名称
	string ypmc = g_dlg->m_dboperator.getSamplenamebyID(si.ypmc_id);
	m_mfcprogridpro_yp[1]->SetValue(_variant_t(ypmc.c_str()));
	//型号规格
	string xhgg = g_dlg->m_dboperator.getModelbyID(si.xhgg);
	m_mfcprogridpro_yp[2]->SetValue(_variant_t(xhgg.c_str()));
	//准确度等级
	string zqddj = g_dlg->m_dboperator.getAccclassbyID(si.zqddj_id);
	m_mfcprogridpro_yp[3]->SetValue(_variant_t(zqddj.c_str()));
	//最小分度值
	string zxfdz = g_dlg->m_dboperator.getMinivaluebyID(si.zxfdz_id);
	m_mfcprogridpro_yp[4]->SetValue(_variant_t(zxfdz.c_str()));
	//最大允许误差
	string zdyxwc = CPGCalculation::getMPE(xhgg, zqddj);
	m_mfcprogridpro_yp[5]->SetValue(_variant_t(zdyxwc.c_str()));
	//生产厂商
	m_mfcprogridpro_yp[6]->SetValue(_variant_t(si.sccs.c_str()));
	//托盘编号 7
	m_mfcprogridpro_yp[7]->SetValue(_variant_t(si.tpbh.c_str()));
	//外观-零位检查 8-9
	vector<string>  wglw = g_dlg->m_dboperator.getWG_LWJCbyID(si.id);
	m_mfcprogridpro_yp[8]->SetValue(_variant_t(wglw[0].c_str()));
	m_mfcprogridpro_yp[9]->SetValue(_variant_t(wglw[1].c_str()));
	//当前状态 10
	string dqzt = g_dlg->m_dboperator.getStatebyID(si.dqzt);
	m_mfcprogridpro_yp[10]->SetValue(_variant_t(dqzt.c_str()));
}

void CInputDlg::showLZD_info()
{
	//流转单编号
	m_mfcprogridpro_lzd[0]->SetValue(_variant_t(m_currentInfo.lzdh.c_str()));
	//计量器具名称
	Circulation cr = g_dlg->m_dboperator.getCirbyLZDH(m_currentInfo.lzdh);
	m_mfcprogridpro_lzd[1]->SetValue(_variant_t(cr.jlqjmc.c_str()));
	//准确度等级2
	//测量范围3
	//型号规格4
	//出厂编号5
	//数量6
	m_mfcprogridpro_lzd[6]->SetValue(_variant_t(to_string(cr.sl).c_str()));
	//附件7
	m_mfcprogridpro_lzd[7]->SetValue(_variant_t(cr.fj.c_str()));
	//强检类型8
	m_mfcprogridpro_lzd[8]->SetValue(_variant_t(cr.qjlx.c_str()));
	//服务方式9
	m_mfcprogridpro_lzd[9]->SetValue(_variant_t(cr.fwfs.c_str()));
	//服务类型10
	m_mfcprogridpro_lzd[10]->SetValue(_variant_t(cr.fwlx.c_str()));
	//基本检测费11
	m_mfcprogridpro_lzd[11]->SetValue(_variant_t(cr.jbjcfy.c_str()));
	//备注12
	m_mfcprogridpro_lzd[12]->SetValue(_variant_t(cr.bz.c_str()));
	//取件时间13
	date qjsj = cr.qjsj;
	CString qjsj_c;
	qjsj_c.Format(_T("%04d-%02d-%02d"), qjsj.year, qjsj.mouth, qjsj.day);
	m_mfcprogridpro_lzd[13]->SetValue(qjsj_c);
	//取件地点14
	m_mfcprogridpro_lzd[14]->SetValue(_variant_t(cr.qjdd.c_str()));
	//领取人15
	m_mfcprogridpro_lzd[15]->SetValue(_variant_t(cr.lxr.c_str()));
	//取件日期16
	date qjrq = cr.lqrq;
	CString qjrq_c;
	qjrq_c.Format(_T("%04d-%02d-%02d"), qjrq.year, qjrq.mouth, qjrq.day);
	m_mfcprogridpro_lzd[16]->SetValue(qjrq_c);
}

void CInputDlg::showWTD_info()
{
	//委托单编号
	m_mfcprogridpro_wtd[0]->SetValue(_variant_t(m_currentInfo.wtdbh.c_str()));
	OrderBase ob = g_dlg->m_dboperator.getOrderBasebyWTDH(m_currentInfo.wtdbh);
	//抬头
	m_mfcprogridpro_wtd[1]->SetValue(_variant_t(ob.m_title.c_str()));
	//委托单位全称
	m_mfcprogridpro_wtd[2]->SetValue(_variant_t(ob.m_wtdw.c_str()));
	//受检单位全称
	m_mfcprogridpro_wtd[3]->SetValue(_variant_t(ob.m_sjdwqc.c_str()));
	//受检单位地址
	m_mfcprogridpro_wtd[4]->SetValue(_variant_t(ob.m_sjdwdz.c_str()));
	//受检单位类型
	m_mfcprogridpro_wtd[5]->SetValue(_variant_t(ob.m_sjdwlx.c_str()));
	//受检单位组织机构代码
	m_mfcprogridpro_wtd[6]->SetValue(_variant_t(ob.m_sjdwdm.c_str()));
	//合同编号
	m_mfcprogridpro_wtd[7]->SetValue(_variant_t(ob.m_htbh.c_str()));
	//联系人
	m_mfcprogridpro_wtd[8]->SetValue(_variant_t(ob.m_lxr.c_str()));
	//手机
	m_mfcprogridpro_wtd[9]->SetValue(_variant_t(ob.m_sj.c_str()));
	//联系电话
	m_mfcprogridpro_wtd[10]->SetValue(_variant_t(ob.m_dh.c_str()));
	//客户要求
	m_mfcprogridpro_wtd[11]->SetValue(_variant_t(ob.m_khyq.c_str()));
	//受理人
	m_mfcprogridpro_wtd[12]->SetValue(_variant_t(ob.m_slr.c_str()));
	//受理日期
	date slrq = ob.m_slrq;
	CString slrq_c;
	slrq_c.Format(_T("%04d-%02d-%02d"), slrq.year, slrq.mouth, slrq.day);
	m_mfcprogridpro_wtd[13]->SetValue(slrq_c);
}

int CInputDlg::saveModifyornot()
{
	//int ret = MessageBox(_T("Save your changes or not?"), _T("Warning"), MB_YESNOCANCEL);
	//if (ret == IDYES) {
	//	//保存修改，切换
	//	OnSaveSampleInfo();
	//	return 1;
	//}
	//else if (ret == IDCANCEL) {
	//	//保持不变，不切换
	//	//if (m_current_tree_item) {
	//	//	m_tree_wtd.Select(m_current_tree_item, TVGN_DROPHILITE);
	//	//}
	//	return 0;
	//}
	//else {
	//	//不保存修改，切换
	//	resetValue();
	//	return 1;
	//}
	int ret = MessageBox(_T("Save your changes or not?"), _T("Warning"), MB_YESNO);
	if (ret == IDYES) {
		//保存修改，切换
		OnSaveSampleInfo();
		return 1;
	}
	else {
		//不保存修改，切换
		resetValue();
		return 1;
	}
}

void CInputDlg::resetValue()
{
	/*
	TVGN_CARET 就像被鼠标点中，会高亮，会展开，会响应消息，用GetSelectedItem得到的是当前节点
	TVGN_DROPHILITE 只会高亮节点，不会展开不会响应消息，用GetSelectedItem得到的是根节点
	TVGN_FIRSTVISIBLE 会高亮，会展开，但是不会响应消息，用GetSelectedItem得到的是根节点
	*/
	g_dlg->m_dboperator.getAllInfo();
	if (m_current_button_state == MODIFY_YP || m_current_button_state == DEL_YP) {
		if (m_current_tree_item) {
			m_current_button_state = VIEW;
			//m_tree_wtd.Select(m_current_tree_item, TVGN_CARET);
		}
	}
	else if (m_current_button_state == DEL_LZD) {
		initWTLZ();
		m_current_button_state = VIEW;
	}
	else if(m_current_button_state == MODIFY_LZD){
		if (m_current_tree_item) {
			m_current_button_state = VIEW;
		}
	}
}

void CInputDlg::newLZD()
{
	Circulation cir;
	cir.wtdh = m_currentInfo.wtdbh;
	cir.sl = 0;
	CStringA lzdh = m_mfcprogridpro_lzd[0]->GetValue();
	cir.lzdh = lzdh;
	CStringA fj = m_mfcprogridpro_lzd[7]->GetValue();
	cir.fj = string(fj);
	CStringA qjlx = m_mfcprogridpro_lzd[8]->GetValue();
	cir.qjlx = string(qjlx);
	CStringA fwfs = m_mfcprogridpro_lzd[9]->GetValue();
	cir.fwfs = string(fwfs);
	CStringA fwlx = m_mfcprogridpro_lzd[10]->GetValue();
	cir.fwlx = string(fwlx);
	CStringA jbjcf = m_mfcprogridpro_lzd[11]->GetValue();
	cir.jbjcfy = string(jbjcf);
	CStringA bz = m_mfcprogridpro_lzd[12]->GetValue();
	cir.bz = string(bz);
	CStringA str = m_mfcprogridpro_lzd[13]->GetValue();
	cir.qjsj = stringtodate(string(str));
	CStringA qjdd = m_mfcprogridpro_lzd[14]->GetValue();
	cir.qjdd = string(qjdd);
	CStringA qjr = m_mfcprogridpro_lzd[15]->GetValue();
	cir.lxr = string(qjr);
	str = m_mfcprogridpro_lzd[16]->GetValue();
	cir.lqrq = stringtodate(string(str));
	cir._state = ADDED;
	g_dlg->m_dboperator.m_Circulation.push_back(cir);
}

void CInputDlg::OnNMClickListYp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	*pResult = 0;

	if (m_current_button_state == NEW_YP) {
		return;
	}

	int ypbh_id = -1;
	if (-1 != pNMListView->iItem)   
	{
		 /////////样品信息
		 ypbh_id = (int)m_listctrl_yp.GetItemData(pNMListView->iItem);
		 showYP_info(ypbh_id);
		/////////流转单信息
		 //showLZD_info();
		/////////委托单信息
		 //showWTD_info();
		m_currentInfo.ypbh_id = ypbh_id;

		//
		for (int i = 0; i < 3; i++) {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_NEW + i, true);
		}
		;
		if (m_listctrl_yp.GetItemCount() == 1) {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LAST, false);
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_NEXT, false);
		}
		else {
			if (pNMListView->iItem == 0) {
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LAST, false);
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_NEXT, true);
			}
			else if (pNMListView->iItem == m_listctrl_yp.GetItemCount() - 1) {
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LAST, true);
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_NEXT, false);
			}
			else {
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_LAST, true);
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_NEXT, true);
			}
		}

		//检测好的样品，可查看检测结果，否则不可用
		Sampleinfo si = g_dlg->m_dboperator.getSampleinfobyYPBH_id(ypbh_id);
		if (si.dqzt > 1) {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_DET, true);
		}
		else {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_DET, false);
		}

		//已经开始检测了，则不能修改
		if (g_dlg->m_dboperator.getSampleStatebyYPBH_ID(m_currentInfo.ypbh_id) > 1) {
			//AfxMessageBox(CString("Can not be modified in detection!"));
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_MOD, false);
		}

		//已审批的样品，若检定证书存在，则可查看，否则不可以
		CString temp, jdzs_path;
		current_WTD_JDZS_paths(temp, jdzs_path);
		if (si.dqzt = 5) {
			if (!PathFileExists(jdzs_path)) {
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_JDZS, false);
			}
			else {
				m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_JDZS, true);
			}
		}

		m_mfcprogridpro_yp.back()->Expand(true);
		m_proper_yp.EnableWindow(false);
		m_mfcprogridpro_lzd.back()->Expand(true);
		m_proper_lzd.EnableWindow(false);
		m_mfcprogridpro_wtd.back()->Expand(true);
		m_proper_wtd.EnableWindow(false);
	}
	Invalidate(FALSE);
}

void CInputDlg::OnNewWTD()
{
	m_current_button_state = NEW_WTD;
	string wtdh = g_dlg->m_dboperator.getNewWTDH();
	string lzdh = g_dlg->m_dboperator.getNewLZDH();
	CString wtdh_s, wtdw_s, sjdw_s, lzdh_s;
	wtdh_s.Format(_T("委托单号：%s"), CStringW(wtdh.c_str()));
	wtdw_s = CString(_T("委托单位：-"));
	sjdw_s = CString(_T("受检单位：-"));

	HTREEITEM hSubItem = m_tree_wtd.InsertItem(wtdh_s);
	HTREEITEM hSubSubItem_1 = m_tree_wtd.InsertItem(wtdw_s, hSubItem);
	HTREEITEM hSubSubItem_2 = m_tree_wtd.InsertItem(sjdw_s, hSubItem);

	lzdh_s.Format(_T("流转单号：%s"), CStringW(lzdh.c_str()));
	HTREEITEM hSubSubItem = m_tree_wtd.InsertItem(lzdh_s, hSubSubItem_2);
	
	TreeNodeData* pNd = new TreeNodeData;
	pNd->wtdbh = wtdh.c_str();
	pNd->lzdh = lzdh.c_str();

	if (g_dlg->m_dboperator.m_Sampleinfo.size()>0) {
		pNd->ypbh_id = g_dlg->m_dboperator.m_Sampleinfo[0].id;
	}
	else {
		pNd->ypbh_id = -1;
	}

	m_tree_wtd.SetItemData(hSubSubItem, (DWORD_PTR)pNd);

	expandTree(hSubItem);
	expandTree(hSubSubItem_2);
	m_tree_wtd.SelectItem(hSubSubItem);

	m_currentInfo.wtdbh = wtdh;
	m_currentInfo.lzdh = lzdh;

	m_listctrl_yp.DeleteAllItems();
	m_mfcprogridpro_lzd[17]->Expand();
	m_proper_lzd.EnableWindow();
	m_proper_wtd.EnableWindow();
	m_mfcprogridpro_wtd[14]->Expand();

	canNotMod_P(1);
	canNotMod_P(2);
	Invalidate(false);
	m_mfcprogridpro_lzd[0]->SetValue(_variant_t(lzdh.c_str()));
	m_mfcprogridpro_wtd[0]->SetValue(_variant_t(wtdh.c_str()));

	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_NEW, false);
}

void CInputDlg::OnModWTD()
{
	if (m_current_button_state != VIEW) {
		AfxMessageBox(CStringW("Please save your changes first!"));
		return;
	}
	m_current_button_state = MODIFY_WTD;
}

void CInputDlg::OnDelWTD()
{
	if (m_current_button_state != VIEW) {
		AfxMessageBox(CStringW("Please save your changes first!"));
		return;
	}
	m_current_button_state = MODIFY_WTD;
}

void CInputDlg::OnNewLZD()
{
	m_current_button_state = MODIFY_LZD;
}

void CInputDlg::OnModLZD()
{
	m_current_button_state = MODIFY_LZD;
	m_proper_lzd.EnableWindow(true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
	Invalidate(false);
	canNotMod_P(1);
}

void CInputDlg::OnDelLZD()
{
	m_current_button_state = DEL_LZD;
	HTREEITEM item = m_tree_wtd.GetSelectedItem();
	HTREEITEM parentItem = m_tree_wtd.GetParentItem(item);
	parentItem = m_tree_wtd.GetParentItem(parentItem);
	m_tree_wtd.DeleteItem(parentItem);

	m_listctrl_yp.DeleteAllItems();
	m_mfcprogridpro_yp[11]->Expand(FALSE);
	m_mfcprogridpro_lzd[17]->Expand(FALSE);
	m_mfcprogridpro_wtd[14]->Expand(FALSE);
	g_dlg->m_dboperator.DEL_CIRU(m_currentInfo.lzdh);

	//删一个存一个，因此不存在，删了多个再保存的情况
}

void CInputDlg::OnNewSample()
{
	m_current_button_state = NEW_YP;
	m_proper_yp.EnableWindow(true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_NEW, false);
	Invalidate(false);
	canNotMod_P(0);

	//列表新建
	string ypbh = g_dlg->m_dboperator.getNewYPBH(m_currentInfo.lzdh);
	int new_id = g_dlg->m_dboperator.getNewID();
	m_currentInfo.ypbh_id = new_id;
	CString ypmc_s;
	ypmc_s.Format(_T("%s-%s"), CStringW(ypbh.c_str()), CStringW("样品"));
	int newindex = m_listctrl_yp.GetItemCount();
	m_listctrl_yp.InsertItem(newindex, ypmc_s);
	m_listctrl_yp.SetItemData(newindex, (DWORD)new_id);

	//设置焦点
	//NMITEMACTIVATE NMItemActive;
	//NMHDR thdr;
	//thdr.code = NM_CLICK;				
	//thdr.hwndFrom = m_listctrl_yp.m_hWnd;	
	//thdr.idFrom = IDC_LIST_YP;		
	//NMItemActive.hdr = thdr;
	//int row = m_listctrl_yp.GetSelectionMark();
	//NMItemActive.iItem = newindex;					//设置选中第几行
	//NMItemActive.iSubItem = 0;				//设置选中第几列
	//SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);

	m_listctrl_yp.SetItemState(m_listctrl_yp.GetSelectionMark(), 0, -1);
	m_listctrl_yp.SetItemState(newindex, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_listctrl_yp.SetSelectionMark(newindex);

	m_mfcprogridpro_yp[11]->Expand();
	//属性框重设
	m_mfcprogridpro_yp[0]->SetValue(_variant_t(ypbh.c_str()));
	m_mfcprogridpro_yp[1]->SetValue(_variant_t("压力表"));
	m_mfcprogridpro_yp[2]->SetValue(_variant_t("(-0.1-1)MPa"));
	m_mfcprogridpro_yp[3]->SetValue(_variant_t("1.0"));
	m_mfcprogridpro_yp[4]->SetValue(_variant_t("0.002"));
	string zdyxwc = CPGCalculation::getMPE("1.0", "0.002");
	m_mfcprogridpro_yp[5]->SetValue(_variant_t(zdyxwc.c_str()));
	string tpbh = g_dlg->m_dboperator.getNewTPBH(m_currentInfo.lzdh);
	m_mfcprogridpro_yp[7]->SetValue(_variant_t(tpbh.c_str()));
	//外观-零位检查 8-9
	m_mfcprogridpro_yp[8]->SetValue(_variant_t("不合格"));
	m_mfcprogridpro_yp[9]->SetValue(_variant_t("不合格"));
	m_mfcprogridpro_yp[10]->SetValue(_variant_t("待检测"));

}

void CInputDlg::OnModSample()
{
	//m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_MOD, true);
	m_current_button_state = MODIFY_YP;
	m_proper_yp.EnableWindow(true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
	Invalidate(false);
	canNotMod_P(0);
}

void CInputDlg::OnDelSample()
{
	int row = m_listctrl_yp.GetSelectionMark();
	g_dlg->m_dboperator.DEL_SAMPLE(m_currentInfo.ypbh_id);

	int count = m_listctrl_yp.GetItemCount();
	int new_row;
	NMITEMACTIVATE NMItemActive;
	int rows = m_listctrl_yp.GetItemCount();
	if (rows == 1) {
		m_listctrl_yp.DeleteItem(row);
	}
	else {
		if (row != count - 1) {
			new_row = row;
		}
		else {
			new_row = row - 1;
		}

		NMHDR thdr;
		thdr.code = NM_CLICK;					//NM_CLICK单击	NM_DBLCKL 双击  NM_RCLICK右键单击
		thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList是列表控件关联的变量
		thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  列表控件ID
		NMItemActive.hdr = thdr;
		NMItemActive.iItem = new_row;					//设置选中第几行
		NMItemActive.iSubItem = 0;				//设置选中第几列

		m_listctrl_yp.DeleteItem(row);
		//m_listctrl_yp.SetItemState(row, 0, -1);
		m_listctrl_yp.SetItemState(new_row, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		m_listctrl_yp.SetSelectionMark(new_row);
		SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);
	}
	m_current_button_state = DEL_YP;

	string ypbh_new = g_dlg->m_dboperator.getNewYPBH(m_currentInfo.lzdh);
	string jgbh_new = g_dlg->m_dboperator.getNewJGBH();
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
}

void CInputDlg::OnLastSample()
{
	NMITEMACTIVATE NMItemActive;
	NMHDR thdr;
	thdr.code = NM_CLICK;					//NM_CLICK单击	NM_DBLCKL 双击  NM_RCLICK右键单击
	thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList是列表控件关联的变量
	thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  列表控件ID
	NMItemActive.hdr = thdr;
	int row = m_listctrl_yp.GetSelectionMark();
	NMItemActive.iItem = row-1;					//设置选中第几行
	NMItemActive.iSubItem = 0;				//设置选中第几列
	SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);

	m_listctrl_yp.SetItemState(row, 0, -1);
	m_listctrl_yp.SetItemState(row - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_listctrl_yp.SetSelectionMark(row - 1);
}

void CInputDlg::OnNextSample()
{
	NMITEMACTIVATE NMItemActive;
	NMHDR thdr;
	thdr.code = NM_CLICK;					//NM_CLICK单击	NM_DBLCKL 双击  NM_RCLICK右键单击
	thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList是列表控件关联的变量
	thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  列表控件ID
	NMItemActive.hdr = thdr;
	int row = m_listctrl_yp.GetSelectionMark();
	NMItemActive.iItem = row + 1;					//设置选中第几行
	NMItemActive.iSubItem = 0;				//设置选中第几列
	SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);

	m_listctrl_yp.SetItemState(row, 0, -1);
	m_listctrl_yp.SetItemState(row + 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_listctrl_yp.SetSelectionMark(row + 1);
}

void CInputDlg::OnSaveSampleInfo()
{
	if (m_current_button_state != VIEW) {
		if (m_current_button_state == MODIFY_YP) {
			BOOL a = false;
			//找到修改项目
			CStringA str;
			Sampleinfo info;
			Samplerst rst;
			vector<int> index;
			info.id = m_currentInfo.ypbh_id;
			rst.ypbh_id = m_currentInfo.ypbh_id;
			for (int i = 1; i < m_mfcprogridpro_yp.size(); i++) {
				CString name = m_mfcprogridpro_yp[i]->GetName();
				a = m_mfcprogridpro_yp[i]->IsModified();
				str = m_mfcprogridpro_yp[i]->GetValue();
				if (a == FALSE) continue;
				if (i == 1) {
					int newSampleID = g_dlg->m_dboperator.getSampleIDbyName(string(str));
					info.ypmc_id = newSampleID;
					index.push_back(1);
				}
				else if (i == 2)
				{
					int newModelID = g_dlg->m_dboperator.getModelIDbyModel(string(str));
					info.xhgg = newModelID;
					index.push_back(2);
				}
				else if (i == 3)
				{
					int newAccID = g_dlg->m_dboperator.getAccclassIDbyAcc(string(str));
					info.zqddj_id = newAccID;
					index.push_back(3);
				}
				else if (i == 4)
				{
					int newMiniID = g_dlg->m_dboperator.getMinivalueIDbyminiv(string(str));
					info.zxfdz_id = newMiniID;
					index.push_back(4);
				}
				else if (i == 6)
				{
					//CString newManufactor = (CStringW)str;
					info.sccs = string(str);
					index.push_back(6);
				}
				else if (i == 8)
				{
					//CString newWGJC = (CStringW)str;
					rst.wgjg = string(str);
					index.push_back(8);
				}
				else if (i == 9)
				{
					//CString newLWJC = (CStringW)str;
					rst.lwjc = string(str);
					index.push_back(9);
				}

				/*CString str;
				str.Format(_T("%d"), (int)a);
				OutputDebugStringW(name);
				OutputDebugStringW(str);
				OutputDebugStringW(CString("\n"));*/
			}
			g_dlg->m_dboperator.MOD_SAMPLE(info, rst, index);
			m_proper_yp.EnableWindow(false);
		}
		else if (m_current_button_state == NEW_YP) {
			Sampleinfo sp;
			CStringA ypbh = m_mfcprogridpro_yp[0]->GetValue();
			sp.id = m_currentInfo.ypbh_id;
			sp.ypbh = string(ypbh);
			sp.lzdh= m_currentInfo.lzdh;
			CStringA ypmc = m_mfcprogridpro_yp[1]->GetValue();
			sp.ypmc_id = g_dlg->m_dboperator.getSampleIDbyName(string(ypmc));
			CStringA model = m_mfcprogridpro_yp[2]->GetValue();
			sp.xhgg = g_dlg->m_dboperator.getModelIDbyModel(string(model));
			CStringA accclass = m_mfcprogridpro_yp[3]->GetValue();
			sp.zqddj_id = g_dlg->m_dboperator.getAccclassIDbyAcc(string(accclass));
			CStringA minval = m_mfcprogridpro_yp[4]->GetValue();
			sp.zxfdz_id = g_dlg->m_dboperator.getMinivalueIDbyminiv(string(minval));
			CStringA manfactor = m_mfcprogridpro_yp[6]->GetValue();
			sp.sccs = string(manfactor);
			CStringA tpbh = m_mfcprogridpro_yp[7]->GetValue();
			sp.tpbh = string(tpbh);
			sp._state = ADDED;
			sp.dqzt = 1; 
			Samplerst rst;
			rst.jgbh = g_dlg->m_dboperator.getNewJGBH();
			rst.ypbh_id = m_currentInfo.ypbh_id;
			CStringA wgjc = m_mfcprogridpro_yp[8]->GetValue();
			rst.wgjg = string(wgjc);
			CStringA lwjc = m_mfcprogridpro_yp[9]->GetValue();
			rst.lwjc = string(lwjc);
			rst.hyjg = string("不合格");
			rst.spjg = string("不合格");
			rst._state = ADDED;
			g_dlg->m_dboperator.m_Sampleinfo.push_back(sp);
			g_dlg->m_dboperator.m_Samplerst.push_back(rst);

			//列表新建
			CString ypmc_s;
			ypmc_s.Format(_T("%s-%s"), CStringW(m_mfcprogridpro_yp[0]->GetValue()), CStringW(m_mfcprogridpro_yp[1]->GetValue()));
			m_listctrl_yp.SetItemText(m_listctrl_yp.GetSelectionMark(), 0, ypmc_s);
			//todo  样品数量+1

			m_proper_yp.EnableWindow(false);
		}
		else if (m_current_button_state == NEW_LZD) {
			newLZD();
		}
		else if (m_current_button_state == MODIFY_LZD) {
			BOOL a = false;
			CStringA str;
			vector<int> index;
			Circulation cir;
			cir.lzdh = m_currentInfo.lzdh;
			cir.wtdh = m_currentInfo.wtdbh;
			for (int i = 1; i < m_mfcprogridpro_lzd.size(); i++) {
				CString name = m_mfcprogridpro_lzd[i]->GetName();
				a = m_mfcprogridpro_lzd[i]->IsModified();
				str = m_mfcprogridpro_lzd[i]->GetValue();
				if (a == FALSE) continue;
				if (i == 1) {
					cir.jlqjmc = string(str);
					index.push_back(i);
				}
				else if (i == 7) {
					cir.fj = string(str);
					index.push_back(i);
				}
				else if (i == 8) {
					cir.qjlx = string(str);
					index.push_back(8);
				}
				else if (i == 9) {
					cir.fwfs = string(str);
					index.push_back(9);
				}
				else if (i == 10) {
					cir.fwlx = string(str);
					index.push_back(10);
				}
				else if (i == 11) {
					cir.jbjcfy = string(str);
					index.push_back(11);
				}
				else if (i == 12) {
					cir.bz = string(str);
					index.push_back(12);
				}
				else if (i == 13) {
					cir.qjsj = stringtodate(string(str));
					index.push_back(13);
				}
				else if (i == 14) {
					cir.qjdd = string(str);
					index.push_back(14);
				}
				else if (i == 15) {
					cir.lxr = string(str);
					index.push_back(15);
				}
				else if (i == 16) {
					cir.lqrq = stringtodate(string(str));
					index.push_back(16);
				}
			}
			g_dlg->m_dboperator.MOD_CIRU(cir, index);
			m_proper_lzd.EnableWindow(false);
		}
		else if (m_current_button_state == NEW_WTD) {
			OrderBase odb;
			CStringA wtdh = m_mfcprogridpro_wtd[0]->GetValue();
			odb.m_wtdbh = string(wtdh);
			CStringA title = m_mfcprogridpro_wtd[1]->GetValue();
			odb.m_title = string(title);
			CStringA wtdw = m_mfcprogridpro_wtd[2]->GetValue();
			odb.m_wtdw = string(wtdw);
			CStringA sjdwqc = m_mfcprogridpro_wtd[3]->GetValue();
			odb.m_sjdwqc = string(sjdwqc);
			CStringA sjdwdz = m_mfcprogridpro_wtd[4]->GetValue();
			odb.m_sjdwdz = string(sjdwdz);
			CStringA sjdwlx = m_mfcprogridpro_wtd[5]->GetValue();
			odb.m_sjdwlx = string(sjdwlx);
			CStringA sjdwdm = m_mfcprogridpro_wtd[6]->GetValue();
			odb.m_sjdwdm = string(sjdwdm);
			CStringA htbh = m_mfcprogridpro_wtd[7]->GetValue();
			odb.m_htbh = string(htbh);
			CStringA lxr = m_mfcprogridpro_wtd[8]->GetValue();
			odb.m_lxr = string(lxr);
			CStringA sj = m_mfcprogridpro_wtd[9]->GetValue();
			odb.m_sj = string(sj);
			CStringA lxdh = m_mfcprogridpro_wtd[10]->GetValue();
			odb.m_dh = string(lxdh);
			CStringA khyq = m_mfcprogridpro_wtd[11]->GetValue();
			odb.m_khyq = string(khyq);
			CStringA slr = m_mfcprogridpro_wtd[12]->GetValue();
			odb.m_slr = string(slr);
			CStringA str = m_mfcprogridpro_wtd[13]->GetValue();
			date slrq = stringtodate(string(str));
			odb.m_slrq = slrq;
			odb.m_state = ADDED;
			g_dlg->m_dboperator.m_OrderBase.push_back(odb);
			newLZD();

			HTREEITEM item = m_tree_wtd.GetSelectedItem();
			HTREEITEM item_SJ = m_tree_wtd.GetParentItem(item);
			HTREEITEM item_WT = m_tree_wtd.GetNextItem(item_SJ, TVGN_PREVIOUS);
			CString wtdw_s, sjdw_s;
			CStringW wtdw_string = m_mfcprogridpro_wtd[2]->GetValue();
			CStringW sjdw_string = m_mfcprogridpro_wtd[3]->GetValue();
			wtdw_s.Format(_T("委托单位：%s"), wtdw_string);
			sjdw_s.Format(_T("受检单位：%s"), sjdw_string);
			m_tree_wtd.SetItemText(item_SJ, wtdw_s);
			m_tree_wtd.SetItemText(item_WT, sjdw_s);

		}

		m_current_button_state = VIEW;
		Invalidate(false);
		AfxMessageBox(CString("Saved!"));
		m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, false);
	}
}

void CInputDlg::OnExportWTD()
{
	CViewReportDlg pDlg;
	CViewReportDlg::m_currentType = WTD;
	CViewReportDlg::m_orderbaseinfo = g_dlg->m_dboperator.getOrderbaseInfobyWTDH(m_currentInfo.wtdbh);
	CViewReportDlg::m_template_FileName = (CStringA)g_dlg->m_configDlg.m_ordertemplate.GetBuffer();
	CString save_filename;
	save_filename.Format(_T("%s%s.pdf"), g_dlg->m_configDlg.m_orderbase_dir, CStringW(m_currentInfo.wtdbh.c_str()));
	CViewReportDlg::m_save_FileName = (CStringA)save_filename.GetBuffer();
	pDlg.DoModal();
}


void CInputDlg::current_WTD_JDZS_paths(CString & wtdPath, CString & jdzsPath)
{
	wtdPath.Format(_T("%s%s.pdf"), g_dlg->m_configDlg.m_orderbase_dir, CStringW(m_currentInfo.wtdbh.c_str()));
	string zsbh = g_dlg->m_dboperator.getZSBH(m_currentInfo.ypbh_id);
	//g_dlg->m_dboperator.getDetectionInfo(m_currentInfo.wtdbh, m_currentInfo.lzdh, m_currentInfo.ypbh_id).m_zsbh;
	string ypbh = g_dlg->m_dboperator.getYPBHyYPBH_ID(m_currentInfo.ypbh_id);
	jdzsPath.Format(_T("%s%s_%s_%s_[%s].pdf"), g_dlg->m_configDlg.m_detection_dir, CStringW(m_currentInfo.wtdbh.c_str()),
	CStringW(m_currentInfo.lzdh.c_str()), CStringW(ypbh.c_str()).Trim(),CStringW(zsbh.c_str()).TrimRight());
}

void CInputDlg::OnViewWTD()
{
	CString filename;
	filename.Format(_T("%s%s.pdf"), g_dlg->m_configDlg.m_orderbase_dir, CStringW(m_currentInfo.wtdbh.c_str()));
	if(!PathFileExists(filename))
		AfxMessageBox(CString("Not exist!"));

	viewPDF(filename);
}


void CInputDlg::OnViewDetResult()
{
	CViewReportDlg pDlg;
	CViewReportDlg::m_currentType = JCJG;
	CViewReportDlg::m_detailinfo = g_dlg->m_dboperator.getDetailrstbyJGBH_PRO(m_currentInfo.ypbh_id);
	CViewReportDlg::m_template_FileName = (CStringA)g_dlg->m_configDlg.m_detresulttemplate.GetBuffer();
	CString save_filename;
	string ypbh = g_dlg->m_dboperator.getYPBHyYPBH_ID(m_currentInfo.ypbh_id);
	save_filename.Format(_T("%s%s_%s_[%s].pdf"), g_dlg->m_configDlg.m_detresult_dir, CStringW(m_currentInfo.wtdbh.c_str()),
		CStringW(m_currentInfo.lzdh.c_str()), CStringW(ypbh.c_str()));
	CViewReportDlg::m_save_FileName = (CStringA)save_filename.GetBuffer();
	pDlg.DoModal();
}

void CInputDlg::OnViewJDZS()
{
	CString filename;
	string zsbh = g_dlg->m_dboperator.getDetectionInfo(m_currentInfo.wtdbh, m_currentInfo.lzdh, m_currentInfo.ypbh_id).m_zsbh;
	string ypbh = g_dlg->m_dboperator.getYPBHyYPBH_ID(m_currentInfo.ypbh_id);
	filename.Format(_T("%s%s_%s_%s_[%s].pdf"), g_dlg->m_configDlg.m_detection_dir, CStringW(m_currentInfo.wtdbh.c_str()), 
		CStringW(m_currentInfo.lzdh.c_str()), CStringW(ypbh.c_str()),CStringW(zsbh.c_str()).TrimRight());
	if (!PathFileExists(filename))
		AfxMessageBox(CString("Not exist!"));

	viewPDF(filename);
}


void CInputDlg::OnMenuSearchWtd()
{
	// TODO: 在此添加命令处理程序代码

}


void CInputDlg::OnMenuSearchLzd()
{
	// TODO: 在此添加命令处理程序代码
}


void CInputDlg::OnMenuSearchWtgs()
{
	// TODO: 在此添加命令处理程序代码
}


void CInputDlg::OnMenuSearchSjdw()
{
	// TODO: 在此添加命令处理程序代码
}


void CInputDlg::OnDblclkTreeWtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	//0->TRUE 屏蔽双击展开/收缩
	*pResult = TRUE;
}


void CInputDlg::OnClickTreeWtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



