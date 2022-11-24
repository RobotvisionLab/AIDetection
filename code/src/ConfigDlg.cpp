// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"
#include "..\thirdparty\GridReport_Utility\GetPath.h"
#include <shlwapi.h> 
#pragma comment(lib,"Shlwapi.lib")

// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialogEx)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONFIGDLG, pParent)
{

}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_CONFIG, m_proper_config);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_REPORT, m_proper_report);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_COMM, m_proper_comm);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_COMMAND(ID_BUTTON_SAVE_CONFIG, &OnSaveConfig)

END_MESSAGE_MAP()


// CConfigDlg 消息处理程序


BOOL CConfigDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	//缺少配置文件，则退出
	if (!PathFileExists(_T("configure.ini"))) {
		AfxMessageBox(CString("No config file!"));
		exit(-1);
		return false;
	}

	CString config_orderbasedir, config_detresultdir, config_detectiondir, config_orderbasetemplate, config_detresulttemplate, config_detectiontemplate;
	GetPrivateProfileString(_T("SaveFileDir"), _T("OrderbaseFilesDir"),_T(""), config_orderbasedir.GetBuffer(),1024,_T("config.ini"));
	GetPrivateProfileString(_T("SaveFileDir"), _T("DetectionFilesDir"), _T(""), config_detectiondir.GetBuffer(), 1024, _T("config.ini"));
	GetPrivateProfileString(_T("SaveFileDir"), _T("DetResultFilesDir"), _T(""), config_detectiondir.GetBuffer(), 1024, _T("config.ini"));


	TCHAR FileName[MAX_PATH];
	GetModuleFileName(NULL, FileName, MAX_PATH);
	CString temp = FileName;
	int pos = temp.ReverseFind('\\');
	temp = temp.Left(pos + 1);

	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;

	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = &sd;

	//保存文件路径为空，则创建缺省路径
	if (config_orderbasedir.IsEmpty())
	{
		config_orderbasedir = temp + CString("OrderbaseFiles\\");
		if (!PathIsDirectory(config_orderbasedir)) {
			if (!CreateDirectory(config_orderbasedir, &sa)) {
				AfxMessageBox(CString("Create config_orderbasedir failed!"));
				exit(-1);
				return false;
			}
		}
	}

	if (config_detresultdir.IsEmpty()) {
		config_detresultdir = temp + CString("DetresultFiles\\");
		if (!PathIsDirectory(config_detresultdir)) {
			if (!CreateDirectory(config_detresultdir, &sa)) {
				AfxMessageBox(CString("Create config_detresultdir failed!"));
				exit(-1);
				return false;
			}
		}
	}

	if (config_detectiondir.IsEmpty()) {
		config_detectiondir = temp + CString("DetectionFiles\\");
		if (!PathIsDirectory(config_detectiondir)) {
			if (!CreateDirectory(config_detectiondir, &sa)) {
				AfxMessageBox(CString("Create config_orderbasedir failed!"));
				exit(-1);
				return false;
			}
		}
	}

	m_ordertemplate = temp + CString("templates\\wtd_template.grf");
	m_detresulttemplate = temp + CString("templates\\jcjg_template.grf");
	m_detectiontemplate = temp + CString("templates\\jdzs_template.grf");

	if (!PathFileExists(m_ordertemplate)) {
		AfxMessageBox(CString("No orderbase template!"));
		exit(-1);
		return false;
	}

	if (!PathFileExists(m_detresulttemplate)) {
		AfxMessageBox(CString("No detrst template!"));
		exit(-1);
		return false;
	}

	if (!PathFileExists(m_detectiontemplate)) {
		AfxMessageBox(CString("No detection template!"));
		exit(-1);
		return false;
	}

	m_orderbase_dir = config_orderbasedir;
	m_detresult_dir = config_detresultdir;
	m_detection_dir = config_detectiondir;

	//工具栏
	m_Input_ImageList.Create(18, 18, ILC_COLOR24 | ILC_MASK, 0, 1);
	for (int i = 0; i < 16; i++)
	{
		m_Input_ImageList.Add(AfxGetApp()->LoadIconW(IDI_ICON_SAVE_CONFIG + i));
	}

	if (!m_Config_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_Config_ToolBar.LoadToolBar(IDR_TOOLBAR_CONFIG))
	{
		EndDialog(IDCANCEL);
	}
	m_Config_ToolBar.SetSizes(CSize(36, 40), CSize(18, 18));
	m_Config_ToolBar.GetToolBarCtrl().SetImageList(&m_Input_ImageList);
	m_Config_ToolBar.ModifyStyle(0, BTNS_SHOWTEXT | TBSTYLE_EX_MIXEDBUTTONS);
	m_Config_ToolBar.SetButtonText(0, _T("保存"));

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	//属性控件
	HDITEM item;
	item.cxy = 90;
	item.mask = HDI_WIDTH;
	m_proper_config.GetHeaderCtrl().SetItem(0, new HDITEM(item));

	CMFCPropertyGridProperty *pGroup1 = new CMFCPropertyGridProperty(_T("文件路径设置"));
	CMFCPropertyGridFileProperty* pFolderWT = new CMFCPropertyGridFileProperty(_T("委托单"), config_orderbasedir);
	pGroup1->AddSubItem(pFolderWT);
	m_mfcprogridpro_config.push_back(pFolderWT);
	CMFCPropertyGridFileProperty* pFolderJCJG = new CMFCPropertyGridFileProperty(_T("检测结果"), config_detectiondir);
	pGroup1->AddSubItem(pFolderJCJG);
	m_mfcprogridpro_config.push_back(pFolderJCJG);
	CMFCPropertyGridFileProperty* pFolderJDZS = new CMFCPropertyGridFileProperty(_T("检定证书"), config_detectiondir);
	pGroup1->AddSubItem(pFolderJDZS);
	m_mfcprogridpro_config.push_back(pFolderJDZS);

	m_proper_config.AddProperty(pGroup1);

	m_proper_report.GetHeaderCtrl().SetItem(0, new HDITEM(item));
	CMFCPropertyGridProperty *pGroup2 = new CMFCPropertyGridProperty(_T("报表模板选择"));
	CMFCPropertyGridFileProperty* pTemplateWT = new CMFCPropertyGridFileProperty(_T("委托单"), TRUE, m_ordertemplate, _T("grf"), NULL, _T("grf Files(*.grf)|*.grf|All Files(*.*)|*.*||"), _T("选择grf文件"));
	CMFCPropertyGridFileProperty* pTemplateDT = new CMFCPropertyGridFileProperty(_T("检测结果"), TRUE, m_detresulttemplate, _T("grf"), NULL, _T("grf Files(*.grf)|*.grf|All Files(*.*)|*.*||"), _T("选择grf文件"));
	CMFCPropertyGridFileProperty* pTemplateDET = new CMFCPropertyGridFileProperty(_T("检定证书"), TRUE, m_detectiontemplate, _T("grf"), NULL, _T("grf Files(*.grf)|*.grf|All Files(*.*)|*.*||"), _T("选择grf文件"));
	pTemplateWT->Enable(false);
	pTemplateDT->Enable(false);
	pTemplateDET->Enable(false);
	pGroup2->AddSubItem(pTemplateWT);
	pGroup2->AddSubItem(pTemplateDT);
	pGroup2->AddSubItem(pTemplateDET);
	m_mfcprogridpro_config.push_back(pTemplateWT);
	m_mfcprogridpro_config.push_back(pTemplateDT);
	m_mfcprogridpro_config.push_back(pTemplateDET);

	m_proper_report.AddProperty(pGroup2);

	m_proper_comm.GetHeaderCtrl().SetItem(0, new HDITEM(item));
	CMFCPropertyGridProperty *pGroup3 = new CMFCPropertyGridProperty(_T("通信状态"));
	CMFCPropertyGridProperty* pPropCOMM_V = new CMFCPropertyGridProperty(_T("视觉模块"), _T("已连接"), _T(""));
	pPropCOMM_V->AddOption(_T("未连接"));
	pPropCOMM_V->Enable(false);
	pGroup3->AddSubItem(pPropCOMM_V);
	m_mfcprogridpro_config.push_back(pPropCOMM_V);

	CMFCPropertyGridProperty* pPropCOMM_P = new CMFCPropertyGridProperty(_T("PLC"), _T("已连接"), _T(""));
	pPropCOMM_P->AddOption(_T("未连接"));
	pPropCOMM_P->Enable(false);
	pGroup3->AddSubItem(pPropCOMM_P);
	m_mfcprogridpro_config.push_back(pPropCOMM_P);

	CMFCPropertyGridProperty *pPropCOMM_S = new CMFCPropertyGridProperty(_T("扫码枪"), 0, TRUE);
	pPropCOMM_S->Enable(false);
	CMFCPropertyGridProperty *pPropCOMM_S1 = new CMFCPropertyGridProperty(_T("录入处"), _T("已连接"), _T(""));
	pPropCOMM_S1->AddOption(_T("未连接"));
	pPropCOMM_S1->Enable(false);
	pPropCOMM_S->AddSubItem(pPropCOMM_S1);
	m_mfcprogridpro_config.push_back(pPropCOMM_S1);

	CMFCPropertyGridProperty *pPropCOMM_S2 = new CMFCPropertyGridProperty(_T("扫描处"), _T("已连接"), _T(""));
	pPropCOMM_S2->AddOption(_T("未连接"));
	pPropCOMM_S2->Enable(false);
	pPropCOMM_S->AddSubItem(pPropCOMM_S2);
	m_mfcprogridpro_config.push_back(pPropCOMM_S2);

	pPropCOMM_S->Expand();
	pGroup3->AddSubItem(pPropCOMM_S);
	pGroup3->Enable(false);
	m_mfcprogridpro_config.push_back(pGroup1);
	m_mfcprogridpro_config.push_back(pGroup2);
	m_mfcprogridpro_config.push_back(pGroup3);
	m_mfcprogridpro_config.push_back(pPropCOMM_S);

	m_proper_comm.AddProperty(pGroup3);

	//动态布局  
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		
		if (pdlmanager->Create(this)) {
			pdlmanager->AddItem(m_Config_ToolBar.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_FZX_CONFIG)->GetSafeHwnd(),CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_CONFIG_FGX)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(m_proper_config.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_CONFIG_FILEPATH)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_CONFIG_REPORT)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_proper_report.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));
			pdlmanager->AddItem(m_proper_comm.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 100));

		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CConfigDlg::OnSaveConfig()
{
	CString save_wtd = m_mfcprogridpro_config[0]->GetValue();
	CString save_jdzs = m_mfcprogridpro_config[1]->GetValue();
	CString template_wtd = m_mfcprogridpro_config[2]->GetValue();
	CString template_jdzs = m_mfcprogridpro_config[3]->GetValue();

	if (!PathIsDirectory(save_wtd)) {
		CString info;
		info.Format(_T("\"%s\" not exists"), save_wtd.GetBuffer());
		AfxMessageBox(info);
	}

	if (!PathIsDirectory(save_jdzs)) {
		CString info;
		info.Format(_T("\"%s\" not exists"), save_jdzs.GetBuffer());
		AfxMessageBox(info);
	}
	m_orderbase_dir = save_wtd;
	m_detection_dir = save_jdzs;
	m_ordertemplate = template_wtd;
	m_detectiontemplate = template_jdzs;
	AfxMessageBox(CString("Save successfully!"));
}

bool CConfigDlg::IsSave()
{
	CString save_wtd = m_mfcprogridpro_config[0]->GetValue();
	CString save_jdzs = m_mfcprogridpro_config[1]->GetValue();

	if (m_orderbase_dir != save_wtd || m_detection_dir != save_jdzs) {
		AfxMessageBox(CString("Please save!"));
		return false;
	}
	else {
		return true;
	}
}
