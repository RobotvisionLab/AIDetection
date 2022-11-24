// InputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AIDetection.h"
#include "InputDlg.h"
#include "afxdialogex.h"
#include "MyPropertyGrid.h"
#include "AIDetectionDlg.h"
#include "PGCalculation.h"

// CInputDlg �Ի���
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


// CInputDlg ��Ϣ�������


void CInputDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	/*CRect test;
	GetClientRect(&test);
	char s[64] = {0};
	sprintf_s(s, "InputDlg top: %d left: %d bottom: %d right: %d \n", test.top, test.left, test.bottom, test.right);
	OutputDebugString(CString(s).GetBuffer());*/

	//CRect test1;
	//CButton* p = (CButton*)GetDlgItem(IDC_BUTTON1);
	//if (!p)
	//	return;
	//p->GetWindowRect(&test1);//��ȡ�ؼ�����Ļ����
	//ScreenToClient(&test1);//ת��Ϊ�Ի����ϵĿͻ�����
	//char s1[64] = { 0 };
	//sprintf_s(s1, "Botton top: %d left: %d bottom: %d right: %d \n", test1.top, test1.left, test1.bottom, test1.right);
	//OutputDebugString(CString(s1).GetBuffer());
}


BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	g_dlg = (CAIDetectionDlg*)(this->GetParent());

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��ʼ��������
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
	m_Input_ToolBar.SetButtonText(0, _T("�½�ί�е�"));
	m_Input_ToolBar.SetButtonText(1, _T("�޸�ί�е�"));
	m_Input_ToolBar.SetButtonText(2, _T("ɾ��ί�е�"));
	m_Input_ToolBar.SetButtonText(4, _T("�½���ת��"));
	m_Input_ToolBar.SetButtonText(5, _T("�޸���ת��"));
	m_Input_ToolBar.SetButtonText(6, _T("ɾ����ת��"));
	m_Input_ToolBar.SetButtonText(8, _T("�½���Ʒ"));
	m_Input_ToolBar.SetButtonText(9, _T("�޸���Ʒ"));
	m_Input_ToolBar.SetButtonText(10, _T("ɾ����Ʒ"));
	m_Input_ToolBar.SetButtonText(12, _T("��һ��"));
	m_Input_ToolBar.SetButtonText(13, _T("��һ��"));
	m_Input_ToolBar.SetButtonText(15, _T("����"));
	m_Input_ToolBar.SetButtonText(16, _T("����ί�е�"));
	m_Input_ToolBar.SetButtonText(18, _T("�����"));
	m_Input_ToolBar.SetButtonText(19, _T("ί�е�"));
	m_Input_ToolBar.SetButtonText(20, _T("�춨֤��"));

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

	//��̬����  
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CInputDlg::initWTLZ()
{
	m_tree_wtd.DeleteAllItems();
	for (int i = 0; i < g_dlg->m_dboperator.m_OrderBase.size(); i++) {
		CString wtdh_s, wtdw_s, sjdw_s;
		string wtdh = g_dlg->m_dboperator.m_OrderBase[i].m_wtdbh;
		string wtdw = g_dlg->m_dboperator.m_OrderBase[i].m_wtdw;
		string sjdw = g_dlg->m_dboperator.m_OrderBase[i].m_sjdwqc;
		wtdh_s.Format(_T("ί�е��ţ�%s"), CStringW(wtdh.c_str()));
		wtdw_s.Format(_T("ί�е�λ��%s"), CStringW(wtdw.c_str()));
		sjdw_s.Format(_T("�ܼ쵥λ��%s"), CStringW(sjdw.c_str()));

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
			lzdh_s.Format(_T("��ת���ţ�%s"), CStringW(lzdh.c_str()));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	HTREEITEM item = m_tree_wtd.GetSelectedItem();
	m_current_tree_item = item;
	CString a = m_tree_wtd.GetItemText(item);
	if (a.Find(_T("��ת����")) < 0) {
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

	//ί�е�������ť���ã����򲻿���
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

	/////////��ת����Ϣ
	showLZD_info();
	/////////ί�е���Ϣ
	showWTD_info();

	//���Կؼ�
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
	//���Կؼ�
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_yp.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	vector<Sampleinfo> sp = g_dlg->m_dboperator.getSampleinfoVecbyLZDH(m_currentInfo.lzdh);
	//���е�����ָ��Ҫ������������delete
	CMFCPropertyGridProperty *pGroup1 = new CMFCPropertyGridProperty(_T("��Ʒ��Ϣ"));

	CMFCPropertyGridProperty* pPropYPBH = new CMFCPropertyGridProperty(_T("��Ʒ���"), (_variant_t)_T("00000001"), _T(""));
	pGroup1->AddSubItem(pPropYPBH);
	//-0
	m_mfcprogridpro_yp.push_back(pPropYPBH);

	CMFCPropertyGridProperty* pPropYPMC = new CMFCPropertyGridProperty(_T("��Ʒ����"), _T("ѹ����"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Samplename.size(); i++) {
		pPropYPMC->AddOption(CStringW(g_dlg->m_dboperator.m_Samplename[i].ypmc.c_str()));

	}
	pGroup1->AddSubItem(pPropYPMC);
	//-1
	m_mfcprogridpro_yp.push_back(pPropYPMC);

	CMFCPropertyGridProperty* pPropYPLC = new CMFCPropertyGridProperty(_T("����"), _T("(-0.1-0.06)MPa"),
		_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Model.size(); i++) {
		pPropYPLC->AddOption(CStringW(g_dlg->m_dboperator.m_Model[i].xhgg.c_str()));
	}
	pGroup1->AddSubItem(pPropYPLC);
	//-2
	m_mfcprogridpro_yp.push_back(pPropYPLC);

	CMFCPropertyGridProperty* pPropYPZZDDJ = new CMFCPropertyGridProperty(_T("׼ȷ�ȵȼ�"), _T("1.0"),_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Accclass.size(); i++) {
		pPropYPZZDDJ->AddOption(CStringW(g_dlg->m_dboperator.m_Accclass[i].zqddj.c_str()));
	}
	pGroup1->AddSubItem(pPropYPZZDDJ);
	//-3
	m_mfcprogridpro_yp.push_back(pPropYPZZDDJ);


	CMFCPropertyGridProperty* pPropZXFDZ = new CMFCPropertyGridProperty(_T("��С�ֶ�ֵ"), _T(""),_T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Minivalue.size(); i++) {
		pPropZXFDZ->AddOption(CStringW(g_dlg->m_dboperator.m_Minivalue[i].zxfdz.c_str()));
	}
	pGroup1->AddSubItem(pPropZXFDZ);
	//-4
	m_mfcprogridpro_yp.push_back(pPropZXFDZ);

	CMFCPropertyGridProperty* pPropZDYXWC = new CMFCPropertyGridProperty(_T("����������"), _T(""), _T(""));
	pGroup1->AddSubItem(pPropZDYXWC);
	//-5
	m_mfcprogridpro_yp.push_back(pPropZDYXWC);

	CMFCPropertyGridProperty* pPropSCCS = new CMFCPropertyGridProperty(_T("��������"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropTPBH = new CMFCPropertyGridProperty(_T("���̱��"), (_variant_t)_T(""), _T(""));
	pGroup1->AddSubItem(pPropSCCS);
	pGroup1->AddSubItem(pPropTPBH);

	//-6
	m_mfcprogridpro_yp.push_back(pPropSCCS);
	//-7
	m_mfcprogridpro_yp.push_back(pPropTPBH);

	CMFCPropertyGridProperty* pPropWGJC = new CMFCPropertyGridProperty(_T("��ۼ��"), _T("/"),_T(""));
	pPropWGJC->AddOption(_T("�ϸ�"));
	pPropWGJC->AddOption(_T("���ϸ�"));
	pGroup1->AddSubItem(pPropWGJC);
	//-8
	m_mfcprogridpro_yp.push_back(pPropWGJC);

	CMFCPropertyGridProperty* pPropLWJC = new CMFCPropertyGridProperty(_T("��λ���"), _T("/"),_T(""));
	pPropLWJC->AddOption(_T("�ϸ�"));
	pPropLWJC->AddOption(_T("���ϸ�"));
	pGroup1->AddSubItem(pPropLWJC);
	//-9
	m_mfcprogridpro_yp.push_back(pPropLWJC);

	CMFCPropertyGridProperty* pPropDQZT = new CMFCPropertyGridProperty(_T("��ǰ״̬"), _T("���춨"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_State.size(); i++) {
		pPropDQZT->AddOption(CStringW(g_dlg->m_dboperator.m_State[i].status.c_str()));
	}
	pGroup1->AddSubItem(pPropDQZT);
	//-10
	m_mfcprogridpro_yp.push_back(pPropDQZT);
	//-11
	m_mfcprogridpro_yp.push_back(pGroup1);

	m_proper_yp.AddProperty(pGroup1);

	//��ʼ������״̬
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

	CMFCPropertyGridProperty *pGroup2 = new CMFCPropertyGridProperty(_T("��ת����Ϣ"));
	CMFCPropertyGridProperty* pPropLZDBH = new CMFCPropertyGridProperty(_T("��ת�����"), (_variant_t)_T("00000001"), _T(""));
	pGroup2->AddSubItem(pPropLZDBH);
	m_mfcprogridpro_lzd.push_back(pPropLZDBH);

	CMFCPropertyGridProperty* pPropJLQJMC1 = new CMFCPropertyGridProperty(_T("������������"), _T("����ʽ�����ⱨ����"), _T(""));
	pPropJLQJMC1->AddOption(_T("����������"));
	pPropJLQJMC1->AddOption(_T("��ز���ϵͳ"));
	pPropJLQJMC1->AddOption(_T("RTU�춨װ��"));
	pGroup2->AddSubItem(pPropJLQJMC1);
	m_mfcprogridpro_lzd.push_back(pPropJLQJMC1);

	CMFCPropertyGridProperty* pPropZQDDJ = new CMFCPropertyGridProperty(_T("׼ȷ�ȵȼ�"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropCLFW = new CMFCPropertyGridProperty(_T("������Χ"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropXHGG = new CMFCPropertyGridProperty(_T("�ͺŹ��"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropCCBH = new CMFCPropertyGridProperty(_T("�������"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSL = new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("0"), _T(""));
	CMFCPropertyGridProperty* pPropFJ = new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("��"), _T(""));
	CMFCPropertyGridProperty* pPropQJLX = new CMFCPropertyGridProperty(_T("ǿ������"), (_variant_t)_T("0"), _T(""));
	CMFCPropertyGridProperty* pPropFWFS = new CMFCPropertyGridProperty(_T("����ʽ"), (_variant_t)_T("����"), _T(""));
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

	CMFCPropertyGridProperty* pPropJCLX = new CMFCPropertyGridProperty(_T("��������"), _T("�춨"), _T(""));
	for (int i = 0; i < g_dlg->m_dboperator.m_Servicetype.size(); i++) {
		pPropJCLX->AddOption(CStringW(g_dlg->m_dboperator.m_Servicetype[i].fwlx.c_str()));
	}
	pGroup2->AddSubItem(pPropJCLX);
	m_mfcprogridpro_lzd.push_back(pPropJCLX);

	CMFCPropertyGridProperty* pPropJBJCF = new CMFCPropertyGridProperty(_T("��������"), (_variant_t)_T("0"), _T(""));
	pGroup2->AddSubItem(pPropJBJCF);
	m_mfcprogridpro_lzd.push_back(pPropJBJCF);

	CMFCPropertyGridProperty* pPropBZ = new CMFCPropertyGridProperty(_T("��ע"), (_variant_t)_T("ͬ�����з���ѡ���ķ���"), _T(""));
	pGroup2->AddSubItem(pPropBZ);
	m_mfcprogridpro_lzd.push_back(pPropBZ);

	CMFCPropertyGridProperty *pPropQJRQ = new CMFCPropertyGridDateTimeProperty(_T("ȡ��ʱ��"), _T("2022-10-1"), _T("��ѡ������"), true);
	pGroup2->AddSubItem(pPropQJRQ);
	m_mfcprogridpro_lzd.push_back(pPropQJRQ);

	CMFCPropertyGridProperty *pPropQJDD= new CMFCPropertyGridProperty(_T("ȡ���ص�"), (_variant_t)_T("�Ž�"), _T(""));
	pGroup2->AddSubItem(pPropQJDD);
	m_mfcprogridpro_lzd.push_back(pPropQJDD);

	CMFCPropertyGridProperty *pPropLQR = new CMFCPropertyGridProperty(_T("��ȡ��"), (_variant_t)_T(""), _T(""));
	pGroup2->AddSubItem(pPropLQR);
	m_mfcprogridpro_lzd.push_back(pPropLQR);

	CMFCPropertyGridProperty *pPropLQJRQ = new CMFCPropertyGridDateTimeProperty(_T("��ȡ����"), _T("2022-10-1"), _T("��ѡ������"), true);
	pGroup2->AddSubItem(pPropLQJRQ);
	m_mfcprogridpro_lzd.push_back(pPropLQJRQ);

	m_proper_lzd.AddProperty(pGroup2);
	m_mfcprogridpro_lzd.push_back(pGroup2);

	//��ʼ������״̬
	pGroup2->Expand(false);
	m_proper_lzd.EnableWindow(false);
}

void CInputDlg::initWTD_P()
{
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_wtd.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	CMFCPropertyGridProperty *pGroup3 = new CMFCPropertyGridProperty(_T("ί�е���Ϣ"));
	CMFCPropertyGridProperty* pPropWTDBH = new CMFCPropertyGridProperty(_T("ί�е����"), (_variant_t)_T("00000001"), _T(""));
	pGroup3->AddSubItem(pPropWTDBH);
	m_mfcprogridpro_wtd.push_back(pPropWTDBH);

	CMFCPropertyGridProperty* pPropTT = new CMFCPropertyGridProperty(_T("̧ͷ"), (_variant_t)_T("�Ϻ��м������Լ����о�Ժ"), _T(""));
	CMFCPropertyGridProperty* pPropWTDWQC = new CMFCPropertyGridProperty(_T("ί�е�λȫ��"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJDWQC = new CMFCPropertyGridProperty(_T("�ܼ쵥λȫ��"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJDWDZ = new CMFCPropertyGridProperty(_T("�ܼ쵥λ��ַ"), (_variant_t)_T(""), _T(""));
	pGroup3->AddSubItem(pPropTT);
	pGroup3->AddSubItem(pPropWTDWQC);
	pGroup3->AddSubItem(pPropSJDWQC);
	pGroup3->AddSubItem(pPropSJDWDZ);
	m_mfcprogridpro_wtd.push_back(pPropTT);
	m_mfcprogridpro_wtd.push_back(pPropWTDWQC);
	m_mfcprogridpro_wtd.push_back(pPropSJDWQC);
	m_mfcprogridpro_wtd.push_back(pPropSJDWDZ);

	CMFCPropertyGridProperty* pPropSJDWLX = new CMFCPropertyGridProperty(_T("�ܼ쵥λ����"), _T("��ҵ"),_T(""));
	pPropSJDWLX->AddOption(_T("����"));
	pGroup3->AddSubItem(pPropSJDWLX);
	m_mfcprogridpro_wtd.push_back(pPropSJDWLX);

	CMFCPropertyGridProperty* pPropSJDWDM = new CMFCPropertyGridProperty(_T("�ܼ쵥λ��֯��������"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropHTBH = new CMFCPropertyGridProperty(_T("��ͬ���"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropLXR = new CMFCPropertyGridProperty(_T("��ϵ��"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSJ = new CMFCPropertyGridProperty(_T("�ֻ�"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropLXDH = new CMFCPropertyGridProperty(_T("��ϵ�绰"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropKHYQ = new CMFCPropertyGridProperty(_T("�ͻ�Ҫ��"), (_variant_t)_T(""), _T(""));
	CMFCPropertyGridProperty* pPropSLR = new CMFCPropertyGridProperty(_T("������"), (_variant_t)_T(""), _T(""));
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

	CMFCPropertyGridProperty *pPropSLRQ = new CMFCPropertyGridDateTimeProperty(_T("��������"), _T("2022-10-1"), _T("��ѡ������"), true);
	pGroup3->AddSubItem(pPropSLRQ);
	m_mfcprogridpro_wtd.push_back(pPropSLRQ);
	m_mfcprogridpro_wtd.push_back(pGroup3);

	m_proper_wtd.AddProperty(pGroup3);

	//��ʼ������״̬
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
	//��Ʒ���
	Sampleinfo si = g_dlg->m_dboperator.getSampleinfobyYPBH_id(id);
	m_mfcprogridpro_yp[0]->SetValue(_variant_t(si.ypbh.c_str()));
	//��Ʒ����
	string ypmc = g_dlg->m_dboperator.getSamplenamebyID(si.ypmc_id);
	m_mfcprogridpro_yp[1]->SetValue(_variant_t(ypmc.c_str()));
	//�ͺŹ��
	string xhgg = g_dlg->m_dboperator.getModelbyID(si.xhgg);
	m_mfcprogridpro_yp[2]->SetValue(_variant_t(xhgg.c_str()));
	//׼ȷ�ȵȼ�
	string zqddj = g_dlg->m_dboperator.getAccclassbyID(si.zqddj_id);
	m_mfcprogridpro_yp[3]->SetValue(_variant_t(zqddj.c_str()));
	//��С�ֶ�ֵ
	string zxfdz = g_dlg->m_dboperator.getMinivaluebyID(si.zxfdz_id);
	m_mfcprogridpro_yp[4]->SetValue(_variant_t(zxfdz.c_str()));
	//����������
	string zdyxwc = CPGCalculation::getMPE(xhgg, zqddj);
	m_mfcprogridpro_yp[5]->SetValue(_variant_t(zdyxwc.c_str()));
	//��������
	m_mfcprogridpro_yp[6]->SetValue(_variant_t(si.sccs.c_str()));
	//���̱�� 7
	m_mfcprogridpro_yp[7]->SetValue(_variant_t(si.tpbh.c_str()));
	//���-��λ��� 8-9
	vector<string>  wglw = g_dlg->m_dboperator.getWG_LWJCbyID(si.id);
	m_mfcprogridpro_yp[8]->SetValue(_variant_t(wglw[0].c_str()));
	m_mfcprogridpro_yp[9]->SetValue(_variant_t(wglw[1].c_str()));
	//��ǰ״̬ 10
	string dqzt = g_dlg->m_dboperator.getStatebyID(si.dqzt);
	m_mfcprogridpro_yp[10]->SetValue(_variant_t(dqzt.c_str()));
}

void CInputDlg::showLZD_info()
{
	//��ת�����
	m_mfcprogridpro_lzd[0]->SetValue(_variant_t(m_currentInfo.lzdh.c_str()));
	//������������
	Circulation cr = g_dlg->m_dboperator.getCirbyLZDH(m_currentInfo.lzdh);
	m_mfcprogridpro_lzd[1]->SetValue(_variant_t(cr.jlqjmc.c_str()));
	//׼ȷ�ȵȼ�2
	//������Χ3
	//�ͺŹ��4
	//�������5
	//����6
	m_mfcprogridpro_lzd[6]->SetValue(_variant_t(to_string(cr.sl).c_str()));
	//����7
	m_mfcprogridpro_lzd[7]->SetValue(_variant_t(cr.fj.c_str()));
	//ǿ������8
	m_mfcprogridpro_lzd[8]->SetValue(_variant_t(cr.qjlx.c_str()));
	//����ʽ9
	m_mfcprogridpro_lzd[9]->SetValue(_variant_t(cr.fwfs.c_str()));
	//��������10
	m_mfcprogridpro_lzd[10]->SetValue(_variant_t(cr.fwlx.c_str()));
	//��������11
	m_mfcprogridpro_lzd[11]->SetValue(_variant_t(cr.jbjcfy.c_str()));
	//��ע12
	m_mfcprogridpro_lzd[12]->SetValue(_variant_t(cr.bz.c_str()));
	//ȡ��ʱ��13
	date qjsj = cr.qjsj;
	CString qjsj_c;
	qjsj_c.Format(_T("%04d-%02d-%02d"), qjsj.year, qjsj.mouth, qjsj.day);
	m_mfcprogridpro_lzd[13]->SetValue(qjsj_c);
	//ȡ���ص�14
	m_mfcprogridpro_lzd[14]->SetValue(_variant_t(cr.qjdd.c_str()));
	//��ȡ��15
	m_mfcprogridpro_lzd[15]->SetValue(_variant_t(cr.lxr.c_str()));
	//ȡ������16
	date qjrq = cr.lqrq;
	CString qjrq_c;
	qjrq_c.Format(_T("%04d-%02d-%02d"), qjrq.year, qjrq.mouth, qjrq.day);
	m_mfcprogridpro_lzd[16]->SetValue(qjrq_c);
}

void CInputDlg::showWTD_info()
{
	//ί�е����
	m_mfcprogridpro_wtd[0]->SetValue(_variant_t(m_currentInfo.wtdbh.c_str()));
	OrderBase ob = g_dlg->m_dboperator.getOrderBasebyWTDH(m_currentInfo.wtdbh);
	//̧ͷ
	m_mfcprogridpro_wtd[1]->SetValue(_variant_t(ob.m_title.c_str()));
	//ί�е�λȫ��
	m_mfcprogridpro_wtd[2]->SetValue(_variant_t(ob.m_wtdw.c_str()));
	//�ܼ쵥λȫ��
	m_mfcprogridpro_wtd[3]->SetValue(_variant_t(ob.m_sjdwqc.c_str()));
	//�ܼ쵥λ��ַ
	m_mfcprogridpro_wtd[4]->SetValue(_variant_t(ob.m_sjdwdz.c_str()));
	//�ܼ쵥λ����
	m_mfcprogridpro_wtd[5]->SetValue(_variant_t(ob.m_sjdwlx.c_str()));
	//�ܼ쵥λ��֯��������
	m_mfcprogridpro_wtd[6]->SetValue(_variant_t(ob.m_sjdwdm.c_str()));
	//��ͬ���
	m_mfcprogridpro_wtd[7]->SetValue(_variant_t(ob.m_htbh.c_str()));
	//��ϵ��
	m_mfcprogridpro_wtd[8]->SetValue(_variant_t(ob.m_lxr.c_str()));
	//�ֻ�
	m_mfcprogridpro_wtd[9]->SetValue(_variant_t(ob.m_sj.c_str()));
	//��ϵ�绰
	m_mfcprogridpro_wtd[10]->SetValue(_variant_t(ob.m_dh.c_str()));
	//�ͻ�Ҫ��
	m_mfcprogridpro_wtd[11]->SetValue(_variant_t(ob.m_khyq.c_str()));
	//������
	m_mfcprogridpro_wtd[12]->SetValue(_variant_t(ob.m_slr.c_str()));
	//��������
	date slrq = ob.m_slrq;
	CString slrq_c;
	slrq_c.Format(_T("%04d-%02d-%02d"), slrq.year, slrq.mouth, slrq.day);
	m_mfcprogridpro_wtd[13]->SetValue(slrq_c);
}

int CInputDlg::saveModifyornot()
{
	//int ret = MessageBox(_T("Save your changes or not?"), _T("Warning"), MB_YESNOCANCEL);
	//if (ret == IDYES) {
	//	//�����޸ģ��л�
	//	OnSaveSampleInfo();
	//	return 1;
	//}
	//else if (ret == IDCANCEL) {
	//	//���ֲ��䣬���л�
	//	//if (m_current_tree_item) {
	//	//	m_tree_wtd.Select(m_current_tree_item, TVGN_DROPHILITE);
	//	//}
	//	return 0;
	//}
	//else {
	//	//�������޸ģ��л�
	//	resetValue();
	//	return 1;
	//}
	int ret = MessageBox(_T("Save your changes or not?"), _T("Warning"), MB_YESNO);
	if (ret == IDYES) {
		//�����޸ģ��л�
		OnSaveSampleInfo();
		return 1;
	}
	else {
		//�������޸ģ��л�
		resetValue();
		return 1;
	}
}

void CInputDlg::resetValue()
{
	/*
	TVGN_CARET ���������У����������չ��������Ӧ��Ϣ����GetSelectedItem�õ����ǵ�ǰ�ڵ�
	TVGN_DROPHILITE ֻ������ڵ㣬����չ��������Ӧ��Ϣ����GetSelectedItem�õ����Ǹ��ڵ�
	TVGN_FIRSTVISIBLE ���������չ�������ǲ�����Ӧ��Ϣ����GetSelectedItem�õ����Ǹ��ڵ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	*pResult = 0;

	if (m_current_button_state == NEW_YP) {
		return;
	}

	int ypbh_id = -1;
	if (-1 != pNMListView->iItem)   
	{
		 /////////��Ʒ��Ϣ
		 ypbh_id = (int)m_listctrl_yp.GetItemData(pNMListView->iItem);
		 showYP_info(ypbh_id);
		/////////��ת����Ϣ
		 //showLZD_info();
		/////////ί�е���Ϣ
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

		//���õ���Ʒ���ɲ鿴����������򲻿���
		Sampleinfo si = g_dlg->m_dboperator.getSampleinfobyYPBH_id(ypbh_id);
		if (si.dqzt > 1) {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_DET, true);
		}
		else {
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_VIEW_DET, false);
		}

		//�Ѿ���ʼ����ˣ������޸�
		if (g_dlg->m_dboperator.getSampleStatebyYPBH_ID(m_currentInfo.ypbh_id) > 1) {
			//AfxMessageBox(CString("Can not be modified in detection!"));
			m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_MOD, false);
		}

		//����������Ʒ�����춨֤����ڣ���ɲ鿴�����򲻿���
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
	wtdh_s.Format(_T("ί�е��ţ�%s"), CStringW(wtdh.c_str()));
	wtdw_s = CString(_T("ί�е�λ��-"));
	sjdw_s = CString(_T("�ܼ쵥λ��-"));

	HTREEITEM hSubItem = m_tree_wtd.InsertItem(wtdh_s);
	HTREEITEM hSubSubItem_1 = m_tree_wtd.InsertItem(wtdw_s, hSubItem);
	HTREEITEM hSubSubItem_2 = m_tree_wtd.InsertItem(sjdw_s, hSubItem);

	lzdh_s.Format(_T("��ת���ţ�%s"), CStringW(lzdh.c_str()));
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

	//ɾһ����һ������˲����ڣ�ɾ�˶���ٱ�������
}

void CInputDlg::OnNewSample()
{
	m_current_button_state = NEW_YP;
	m_proper_yp.EnableWindow(true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SAVE, true);
	m_Input_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON_SP_NEW, false);
	Invalidate(false);
	canNotMod_P(0);

	//�б��½�
	string ypbh = g_dlg->m_dboperator.getNewYPBH(m_currentInfo.lzdh);
	int new_id = g_dlg->m_dboperator.getNewID();
	m_currentInfo.ypbh_id = new_id;
	CString ypmc_s;
	ypmc_s.Format(_T("%s-%s"), CStringW(ypbh.c_str()), CStringW("��Ʒ"));
	int newindex = m_listctrl_yp.GetItemCount();
	m_listctrl_yp.InsertItem(newindex, ypmc_s);
	m_listctrl_yp.SetItemData(newindex, (DWORD)new_id);

	//���ý���
	//NMITEMACTIVATE NMItemActive;
	//NMHDR thdr;
	//thdr.code = NM_CLICK;				
	//thdr.hwndFrom = m_listctrl_yp.m_hWnd;	
	//thdr.idFrom = IDC_LIST_YP;		
	//NMItemActive.hdr = thdr;
	//int row = m_listctrl_yp.GetSelectionMark();
	//NMItemActive.iItem = newindex;					//����ѡ�еڼ���
	//NMItemActive.iSubItem = 0;				//����ѡ�еڼ���
	//SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);

	m_listctrl_yp.SetItemState(m_listctrl_yp.GetSelectionMark(), 0, -1);
	m_listctrl_yp.SetItemState(newindex, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_listctrl_yp.SetSelectionMark(newindex);

	m_mfcprogridpro_yp[11]->Expand();
	//���Կ�����
	m_mfcprogridpro_yp[0]->SetValue(_variant_t(ypbh.c_str()));
	m_mfcprogridpro_yp[1]->SetValue(_variant_t("ѹ����"));
	m_mfcprogridpro_yp[2]->SetValue(_variant_t("(-0.1-1)MPa"));
	m_mfcprogridpro_yp[3]->SetValue(_variant_t("1.0"));
	m_mfcprogridpro_yp[4]->SetValue(_variant_t("0.002"));
	string zdyxwc = CPGCalculation::getMPE("1.0", "0.002");
	m_mfcprogridpro_yp[5]->SetValue(_variant_t(zdyxwc.c_str()));
	string tpbh = g_dlg->m_dboperator.getNewTPBH(m_currentInfo.lzdh);
	m_mfcprogridpro_yp[7]->SetValue(_variant_t(tpbh.c_str()));
	//���-��λ��� 8-9
	m_mfcprogridpro_yp[8]->SetValue(_variant_t("���ϸ�"));
	m_mfcprogridpro_yp[9]->SetValue(_variant_t("���ϸ�"));
	m_mfcprogridpro_yp[10]->SetValue(_variant_t("�����"));

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
		thdr.code = NM_CLICK;					//NM_CLICK����	NM_DBLCKL ˫��  NM_RCLICK�Ҽ�����
		thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList���б�ؼ������ı���
		thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  �б�ؼ�ID
		NMItemActive.hdr = thdr;
		NMItemActive.iItem = new_row;					//����ѡ�еڼ���
		NMItemActive.iSubItem = 0;				//����ѡ�еڼ���

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
	thdr.code = NM_CLICK;					//NM_CLICK����	NM_DBLCKL ˫��  NM_RCLICK�Ҽ�����
	thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList���б�ؼ������ı���
	thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  �б�ؼ�ID
	NMItemActive.hdr = thdr;
	int row = m_listctrl_yp.GetSelectionMark();
	NMItemActive.iItem = row-1;					//����ѡ�еڼ���
	NMItemActive.iSubItem = 0;				//����ѡ�еڼ���
	SendMessage(WM_NOTIFY, IDC_LIST_YP, (LPARAM)&NMItemActive);

	m_listctrl_yp.SetItemState(row, 0, -1);
	m_listctrl_yp.SetItemState(row - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_listctrl_yp.SetSelectionMark(row - 1);
}

void CInputDlg::OnNextSample()
{
	NMITEMACTIVATE NMItemActive;
	NMHDR thdr;
	thdr.code = NM_CLICK;					//NM_CLICK����	NM_DBLCKL ˫��  NM_RCLICK�Ҽ�����
	thdr.hwndFrom = m_listctrl_yp.m_hWnd;	//m_TestList���б�ؼ������ı���
	thdr.idFrom = IDC_LIST_YP;		//IDC_TESTSETTING_LIST  �б�ؼ�ID
	NMItemActive.hdr = thdr;
	int row = m_listctrl_yp.GetSelectionMark();
	NMItemActive.iItem = row + 1;					//����ѡ�еڼ���
	NMItemActive.iSubItem = 0;				//����ѡ�еڼ���
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
			//�ҵ��޸���Ŀ
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
			rst.hyjg = string("���ϸ�");
			rst.spjg = string("���ϸ�");
			rst._state = ADDED;
			g_dlg->m_dboperator.m_Sampleinfo.push_back(sp);
			g_dlg->m_dboperator.m_Samplerst.push_back(rst);

			//�б��½�
			CString ypmc_s;
			ypmc_s.Format(_T("%s-%s"), CStringW(m_mfcprogridpro_yp[0]->GetValue()), CStringW(m_mfcprogridpro_yp[1]->GetValue()));
			m_listctrl_yp.SetItemText(m_listctrl_yp.GetSelectionMark(), 0, ypmc_s);
			//todo  ��Ʒ����+1

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
			wtdw_s.Format(_T("ί�е�λ��%s"), wtdw_string);
			sjdw_s.Format(_T("�ܼ쵥λ��%s"), sjdw_string);
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
	// TODO: �ڴ���������������

}


void CInputDlg::OnMenuSearchLzd()
{
	// TODO: �ڴ���������������
}


void CInputDlg::OnMenuSearchWtgs()
{
	// TODO: �ڴ���������������
}


void CInputDlg::OnMenuSearchSjdw()
{
	// TODO: �ڴ���������������
}


void CInputDlg::OnDblclkTreeWtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//0->TRUE ����˫��չ��/����
	*pResult = TRUE;
}


void CInputDlg::OnClickTreeWtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}



