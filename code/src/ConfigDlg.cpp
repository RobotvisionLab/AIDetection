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
	, m_bConnect(0)
	, m_bIsSoftTrigger(0)
	, m_bStartJob(0)
	, m_pcDataBuf(NULL)
	, m_bBitmapInfo(NULL)
	, m_hProcessThread(NULL)
{
	m_MaxImageSize = 0;
	m_handle = NULL;
	m_hWndDisplay = NULL;

	memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));
	memset(&m_stDeviceInfo, 0, sizeof(m_stDeviceInfo));
	memset(&m_stParam, 0, sizeof(MV_CODEREADER_DRAW_PARAM));
	memset(&m_pstParam, 0, sizeof(MV_CODEREADER_TJPG_PARAM));

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
	DDX_Control(pDX, IDC_LIST_SCANS, m_list_scanner);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_COMMAND(ID_BUTTON_SAVE_CONFIG, &OnSaveConfig)

	ON_BN_CLICKED(IDC_BUTTON_SEARCH_SCANNER, &CConfigDlg::OnBnClickedButtonSearchScanner)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT2, &CConfigDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_RADIO_CONT, &CConfigDlg::OnBnClickedRadioCont)
	ON_BN_CLICKED(IDC_RADIO_EXTERN, &CConfigDlg::OnBnClickedRadioExtern)
	ON_BN_CLICKED(IDC_BUTTON_STARTGRAB, &CConfigDlg::OnBnClickedButtonStartGrab)
	ON_BN_CLICKED(IDC_BUTTON_STOPGRAB, &CConfigDlg::OnBnClickedButtonStopGrab)
	ON_BN_CLICKED(IDC_BUTTON_TRIGGER, &CConfigDlg::OnBnClickedButtonTrigger)
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
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_SCANSEARCH)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(0, 0));

		}
	}

	// 创建窗口句柄
	CWnd *pWnd = GetDlgItem(IDC_STATIC_SCANNER_1);
	if (NULL == pWnd)
	{
		return MV_CODEREADER_E_RESOURCE;
	}
	m_hWndDisplay = pWnd->GetSafeHwnd();
	if (NULL == m_hWndDisplay)
	{
		return MV_CODEREADER_E_RESOURCE;
	}


	//初始化GDI+
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(FALSE);

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

bool CConfigDlg::IsStrUTF8(const char * pBuffer, int size)
{
	if (size < 0)
	{
		return false;
	}

	bool IsUTF8 = true;
	unsigned char* start = (unsigned char*)pBuffer;
	unsigned char* end = (unsigned char*)pBuffer + size;
	if (NULL == start ||
		NULL == end)
	{
		return false;
	}
	while (start < end)
	{
		if (*start < 0x80) // ch:(10000000): 值小于0x80的为ASCII字符 | en:(10000000): if the value is smaller than 0x80, it is the ASCII character
		{
			start++;
		}
		else if (*start < (0xC0)) // ch:(11000000): 值介于0x80与0xC0之间的为无效UTF-8字符 | en:(11000000): if the value is between 0x80 and 0xC0, it is the invalid UTF-8 character
		{
			IsUTF8 = false;
			break;
		}
		else if (*start < (0xE0)) // ch:(11100000): 此范围内为2字节UTF-8字符  | en: (11100000): if the value is between 0xc0 and 0xE0, it is the 2-byte UTF-8 character
		{
			if (start >= end - 1)
			{
				break;
			}

			if ((start[1] & (0xC0)) != 0x80)
			{
				IsUTF8 = false;
				break;
			}

			start += 2;
		}
		else if (*start < (0xF0)) // ch:(11110000): 此范围内为3字节UTF-8字符 | en: (11110000): if the value is between 0xE0 and 0xF0, it is the 3-byte UTF-8 character 
		{
			if (start >= end - 2)
			{
				break;
			}

			if ((start[1] & (0xC0)) != 0x80 || (start[2] & (0xC0)) != 0x80)
			{
				IsUTF8 = false;
				break;
			}

			start += 3;
		}
		else
		{
			IsUTF8 = false;
			break;
		}
	}

	return IsUTF8;
}

bool CConfigDlg::Char2Wchar(const char * pStr, wchar_t * pOutWStr, int nOutStrSize)
{
	if (!pStr || !pOutWStr)
	{
		return false;
	}

	bool bIsUTF = IsStrUTF8(pStr, strlen(pStr));
	UINT nChgType = bIsUTF ? CP_UTF8 : CP_ACP;
	int iLen = MultiByteToWideChar(nChgType, 0, (LPCSTR)pStr, -1, NULL, 0);

	memset(pOutWStr, 0, sizeof(wchar_t) * nOutStrSize);
	if (iLen >= nOutStrSize)
	{
		iLen = nOutStrSize - 1;
	}

	MultiByteToWideChar(nChgType, 0, (LPCSTR)pStr, -1, pOutWStr, iLen);
	pOutWStr[iLen] = 0;
	return true;
}

bool CConfigDlg::Wchar2char(wchar_t * pOutWStr, char * pStr)
{
	if (!pStr || !pOutWStr)
	{
		return false;
	}

	int nLen = WideCharToMultiByte(CP_ACP, 0, pOutWStr, wcslen(pOutWStr), NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, pOutWStr, wcslen(pOutWStr), pStr, nLen, NULL, NULL);
	pStr[nLen] = '\0';
	return true;
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

int CConfigDlg::GetCurrentConfigurationInformation()
{
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 获取触发模式
	unsigned int nTriggerMode = 0;
	MV_CODEREADER_ENUMVALUE stParam;
	memset(&stParam, 0, sizeof(MV_CODEREADER_ENUMVALUE));
	nRet = MV_CODEREADER_GetEnumValue(m_handle, TRIGGER_MODE, &stParam);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Get trigger mode failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return nRet;
	}
	nTriggerMode = stParam.nCurValue;

	if (MV_CODEREADER_TRIGGER_MODE_ON == nTriggerMode)
	{
		((CButton *)GetDlgItem(IDC_RADIO_CONT))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_EXTERN))->SetCheck(TRUE);
	}
	else if (MV_CODEREADER_TRIGGER_MODE_OFF == nTriggerMode)
	{
		((CButton *)GetDlgItem(IDC_RADIO_CONT))->SetCheck(TRUE);
		((CButton *)GetDlgItem(IDC_RADIO_EXTERN))->SetCheck(FALSE);
	}
	else
	{
		return MV_CODEREADER_E_PARAMETER;
	}

	// 获取触发源,前置条件为已设为触发模式
	if (MV_CODEREADER_TRIGGER_MODE_OFF == nTriggerMode)
	{
		return nRet;
	}

	unsigned int nTriggerSource = 0;
	memset(&stParam, 0, sizeof(MV_CODEREADER_ENUMVALUE));
	nRet = MV_CODEREADER_GetEnumValue(m_handle, TRIGGER_SOURCE, &stParam);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Get trigger source failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return nRet;
	}

	nTriggerSource = stParam.nCurValue;
	if (MV_CODEREADER_TRIGGER_SOURCE_SOFTWARE == nTriggerSource)
	{
		m_bIsSoftTrigger = 1;
		GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(TRUE);
	}
	else
	{
		m_bIsSoftTrigger = 0;
	}
	
	return MV_CODEREADER_OK;
}

void CConfigDlg::OnBnClickedGetParameterButton()
{
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 获取曝光时间
	float fExposureTime = 0.0f;
	MV_CODEREADER_FLOATVALUE stParam;
	memset(&stParam, 0, sizeof(MV_CODEREADER_FLOATVALUE));
	nRet = MV_CODEREADER_GetFloatValue(m_handle, EXPOSURE_TIME, &stParam);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Set exposure time failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
	}
	else
	{
		fExposureTime = stParam.fCurValue;
		cstrInfo.Format(_T("%0.2f"), fExposureTime);
		OutputDebugStringW(cstrInfo);
	}

	// 获取增益
	float fGain = 0.0f;
	memset(&stParam, 0, sizeof(MV_CODEREADER_FLOATVALUE));
	nRet = MV_CODEREADER_GetFloatValue(m_handle, GAIN, &stParam);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Get gain failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
	}
	else
	{
		fGain = stParam.fCurValue;
		cstrInfo.Format(_T("%0.2f"), fGain);
		OutputDebugStringW(cstrInfo);
	}

	// 获取帧率
	float fFrameRate = 0.0f;
	memset(&stParam, 0, sizeof(MV_CODEREADER_FLOATVALUE));
	nRet = MV_CODEREADER_GetFloatValue(m_handle, ACQUISITION_FRAME_RATE, &stParam);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Get acquisition rate failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
	}
	else
	{
		fFrameRate = stParam.fCurValue;
		cstrInfo.Format(_T("%0.2f"), fFrameRate);
		OutputDebugStringW(cstrInfo);
	}

	UpdateData(FALSE);
}


void CConfigDlg::OnBnClickedButtonSearchScanner()
{
	// TODO: Add your control notification handler code here
	CString strMsg;

	// 清空设备列表框中的信息
	int Count = m_list_scanner.GetCount();
	for (int i = 0; i <= Count; i++)
	{
		m_list_scanner.DeleteString(i);
	}

	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 查找设备
	memset(&m_stDeviceInfoList, 0, sizeof(MV_CODEREADER_DEVICE_INFO_LIST));
	nRet = MV_CODEREADER_EnumDevices(&m_stDeviceInfoList, MV_CODEREADER_GIGE_DEVICE);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Enum Device failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}

	if (0 == m_stDeviceInfoList.nDeviceNum)
	{
		CString errorMsg;
		errorMsg.Format(_T("None Device"));
		MessageBox(errorMsg, TEXT("device"), MB_OK | MB_ICONWARNING);
		return;
	}

	// 显示查找到的设备信息
	for (unsigned int i = 0; i < m_stDeviceInfoList.nDeviceNum; i++)
	{
		unsigned char nIp1 = m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff;
		unsigned char nIp2 = (m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff00) >> 8;
		unsigned char nIp3 = (m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff0000) >> 16;
		unsigned char nIp4 = (m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24;

		// 中文字体显示
		wchar_t strWchar[16] = { 0 };
		Char2Wchar((char*)m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chUserDefinedName, strWchar, 16);
		Wchar2char(strWchar, (char*)m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chUserDefinedName);

		cstrInfo.Format(_T("[%d] %s: %s (%d.%d.%d.%d)"), i,
			CStringW(m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chUserDefinedName),
			CStringW(m_stDeviceInfoList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chManufacturerName),
			nIp4,
			nIp3,
			nIp2,
			nIp1);
		m_list_scanner.AddString(cstrInfo);
	}

	UpdateData(FALSE);
}

void CConfigDlg::DeInitResources()
{
	m_bStartJob = false;
	// 销毁取流线程
	if (NULL != m_hProcessThread)
	{
		//等待线程结束，关闭释放线程
		WaitForSingleObject(m_hProcessThread, 1000);
		CloseHandle(m_hProcessThread);
		m_hProcessThread = NULL;
	}

	if (NULL != m_pstParam.pBufOutput)
	{
		free(m_pstParam.pBufOutput);
		m_pstParam.pBufOutput = NULL;
	}

	if (NULL != m_stParam.pData)
	{
		free(m_stParam.pData);
		m_stParam.pData = NULL;
	}

	if (NULL != m_pcDataBuf)
	{
		free(m_pcDataBuf);
		m_pcDataBuf = NULL;
	}

	if (NULL != m_pstImageInfoEx2)
	{
		free(m_pstImageInfoEx2);
		m_pstImageInfoEx2 = NULL;
	}

}

// jpg解码
int CConfigDlg::MvJpgDecompress(IN OUT MV_CODEREADER_TJPG_PARAM* pstParam)
{
	if (NULL == pstParam)
	{
		return MV_CODEREADER_E_PARAMETER;
	}

	int nRet = MV_CODEREADER_OK;
	int nWidth = 0;
	int nHeight = 0;
	int nSubsample = 0;
	int nColorspace = 0;
	int nPixelfmt = 0;      //TJPF_RGB;

	tjhandle handle = NULL;;
	handle = tjInitDecompress();
	if (NULL == handle)
	{
		return MV_CODEREADER_E_RESOURCE;
	}

	try
	{
		nRet = tjDecompressHeader3(handle, pstParam->pBufInput, pstParam->nBufInputLen, &nWidth, &nHeight,
			&nSubsample, &nColorspace);
		if (nRet == -1)
		{
			nRet = MV_CODEREADER_E_PARAMETER;
			throw nRet;
		}

		if (TJSAMP_GRAY == nSubsample || TJSAMP_420 == nSubsample)
		{
			nPixelfmt = TJPF_GRAY;
		}

		nRet = tjDecompress2(handle, pstParam->pBufInput, pstParam->nBufInputLen, pstParam->pBufOutput, nWidth, 0,
			nHeight, nPixelfmt, 0);
		if (nRet == -1)
		{
			nRet = MV_CODEREADER_E_PARAMETER;
			throw nRet;
		}

		pstParam->nWidth = nWidth;
		pstParam->nHeight = nHeight;

		if (TJSAMP_GRAY == nSubsample || TJSAMP_420 == nSubsample)
		{
			pstParam->nBufOutputLen = pstParam->nWidth * pstParam->nHeight;
		}
		else
		{
			pstParam->nBufOutputLen = pstParam->nWidth * pstParam->nHeight * 3;
		}
	}
	catch (...)
	{
		if (handle)
		{
			tjDestroy(handle);
		}
		return nRet;
	}

	if (handle)
	{
		tjDestroy(handle);
	}

	return MV_CODEREADER_OK;
}

int  CConfigDlg::Draw(MV_CODEREADER_DRAW_PARAM* pstParam)
{
	if (NULL == pstParam)
	{
		return MV_CODEREADER_E_PARAMETER;
	}

	int nImageWidth = pstParam->nImageWidth;
	int nImageHeight = pstParam->nImageHeight;
	int nDstWidth = (int)(pstParam->nWndRectWidth);
	int nDstHeight = (int)(pstParam->nWndRectHeight);
	int nSrcX = 0;
	int nSrcY = 0;
	int nSrcWidth = (int)(nImageWidth);
	int nSrcHeight = (int)(nImageHeight);

	if (NULL == m_bBitmapInfo)
	{
		m_bBitmapInfo = (PBITMAPINFO)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
		memset(m_bBitmapInfo, 0, sizeof(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD)));
	}
	// 位图信息头
	m_bBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);             // BITMAPINFOHEADER结构长度
	m_bBitmapInfo->bmiHeader.biWidth = nImageWidth;                         // 图像宽度
	m_bBitmapInfo->bmiHeader.biPlanes = 1;                                  // 位面数
	m_bBitmapInfo->bmiHeader.biBitCount = 8;                                // 比特数/像素的颜色深度,2^8=256
	m_bBitmapInfo->bmiHeader.biCompression = BI_RGB;                        // 图像数据压缩类型,BI_RGB表示不压缩
	m_bBitmapInfo->bmiHeader.biSizeImage = nImageWidth * nImageHeight;      // 图像大小
	m_bBitmapInfo->bmiHeader.biHeight = -nImageHeight;                     // 图像高度

	for (int i = 0; i < 256; i++)
	{
		m_bBitmapInfo->bmiColors[i].rgbBlue = m_bBitmapInfo->bmiColors[i].rgbRed = m_bBitmapInfo->bmiColors[i].rgbGreen = i;
		m_bBitmapInfo->bmiColors[i].rgbReserved = 0;
	}

	int nRet = StretchDIBits(pstParam->hDC,
		pstParam->nDstX, pstParam->nDstY, nDstWidth, nDstHeight,
		nSrcX, nSrcY, nSrcWidth, nSrcHeight, pstParam->pData, m_bBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

	return MV_CODEREADER_OK;
}

unsigned int CConfigDlg::InnerDrawShape(Graphics* g, float x, float y, float w, float h, float fAngle)
{
	/* 路径初始化 */
	Status nGdiStatus = Status::Ok;
	GraphicsPath m_stShapePath;    ///< 图形路径，内部变量 
	nGdiStatus = m_stShapePath.Reset();
	if (Status::Ok != nGdiStatus)
	{
		return 1;
	}

	float fGdiAngle = fAngle;
	if (fGdiAngle < 0)
	{
		fGdiAngle += 360;
	}

	/* 添加当前矩形至路径 */
	nGdiStatus = m_stShapePath.AddRectangle(RectF(x - w * 0.5, y - h*0.5, w, h));
	if (Status::Ok != nGdiStatus)
	{
		return 1;
	}
	/* 根据角度旋转路径 */
	//Matrix* stRotateM = new Matrix();
	Matrix stRotateM;
	PointF stCenPoint(x, y);
	stRotateM.RotateAt(fAngle, stCenPoint);
	nGdiStatus = m_stShapePath.Transform(&stRotateM);

	if (Status::Ok != nGdiStatus)
	{
		return 1;
	}

	/* 根据是否选中用不同画笔绘制图形 */
	Pen pen2(Color(255, 255, 0), 3);

	nGdiStatus = g->DrawPath(&pen2, &m_stShapePath);
	if (Status::Ok != nGdiStatus)
	{
		return 1;
	}

	return 0;
}

int CConfigDlg::Display(void* hWnd, unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstDisplayImage)
{
	int nRet = MV_CODEREADER_OK;

	if ((NULL == pData) || (NULL == pstDisplayImage))
	{
		return MV_CODEREADER_E_PARAMETER;
	}

	if (pstDisplayImage->nWidth == 0 || pstDisplayImage->nHeight == 0 || NULL == hWnd)
	{
		return MV_CODEREADER_E_PARAMETER;
	}

	memcpy(m_pstImageInfoEx2, pstDisplayImage, sizeof(MV_CODEREADER_IMAGE_OUT_INFO_EX2));

	// 显示图像
	HDC hDC = ::GetDC((HWND)hWnd);
	SetStretchBltMode(hDC, COLORONCOLOR);
	RECT wndRect;
	::GetClientRect((HWND)hWnd, &wndRect);

	int nWndRectWidth = wndRect.right - wndRect.left;
	int nWndRectHeight = wndRect.bottom - wndRect.top;
	int nDstWidth = (int)(nWndRectWidth);
	int nDstHeight = (int)(nWndRectHeight);
	int nDstX = wndRect.left;
	int nDstY = wndRect.top;

	int nImageWidth = pstDisplayImage->nWidth;
	int nImageHeight = pstDisplayImage->nHeight;
	int nSrcX = 0;
	int nSrcY = 0;
	int nSrcWidth = (int)(nImageWidth);
	int nSrcHeight = (int)(nImageHeight);

	// 给结构体赋值
	m_stParam.hDC = hDC;
	m_stParam.nDstX = nDstX;
	m_stParam.nDstY = nDstY;
	m_stParam.nImageHeight = nImageHeight;
	m_stParam.nImageWidth = nImageWidth;
	m_stParam.nWndRectHeight = nWndRectHeight;
	m_stParam.nWndRectWidth = nWndRectWidth;

	// 将图像数据赋值给m_pcDataBuf，用于保存图像信息 
	memcpy(m_pcDataBuf, pData, m_pstImageInfoEx2->nFrameLen);

	if (PixelType_CodeReader_Gvsp_Jpeg == pstDisplayImage->enPixelType)
	{
		memset(m_pstParam.pBufOutput, 0, nImageWidth * nImageHeight);

		m_pstParam.pBufInput = pData;
		m_pstParam.nBufInputLen = nImageWidth * nImageHeight;
		nRet = MvJpgDecompress(&m_pstParam);
		if (MV_CODEREADER_OK == nRet)
		{
			// 将Jpeg数据格式解压的数据封装为结构体，赋值作为参数传入，进行渲染
			memcpy(m_stParam.pData, m_pstParam.pBufOutput, m_pstParam.nBufOutputLen);
			nRet = Draw(&m_stParam);
			if (MV_CODEREADER_OK != nRet)
			{
				return nRet = MV_CODEREADER_E_PARAMETER;
			}
		}
		else
		{
			// 解压失败
		}

	}
	else // 除Jpeg格式外的相机数据渲染
	{
		memset(m_stParam.pData, 0, nImageWidth * nImageHeight);
		// 相机获取的数据直接渲染
		memcpy(m_stParam.pData, pData, nImageWidth * nImageHeight);
		nRet = Draw(&m_stParam);
		if (MV_CODEREADER_OK != nRet)
		{
			return MV_CODEREADER_E_PARAMETER;
		}
	}

	// 识别到的条码进行画框
	Graphics gCode((HWND)hWnd);
	Status nGdiStatus = Status::Ok;
	Pen pen(Color(0, 0, 255), 3);

	float fWidthProportion = (float)nWndRectWidth / nImageWidth;
	float fHeightProportion = (float)nWndRectHeight / nImageHeight;

	MV_CODEREADER_RESULT_BCR_EX* stBcrResult = (MV_CODEREADER_RESULT_BCR_EX*)pstDisplayImage->pstCodeListEx;

	for (int i = 0; i < stBcrResult->nCodeNum; i++)
	{
		PointF point1((stBcrResult->stBcrInfoEx[i].pt[0].x * fWidthProportion), (stBcrResult->stBcrInfoEx[i].pt[0].y * fHeightProportion));
		PointF point2((stBcrResult->stBcrInfoEx[i].pt[1].x * fWidthProportion), (stBcrResult->stBcrInfoEx[i].pt[1].y * fHeightProportion));
		PointF point3((stBcrResult->stBcrInfoEx[i].pt[2].x * fWidthProportion), (stBcrResult->stBcrInfoEx[i].pt[2].y * fHeightProportion));
		PointF point4((stBcrResult->stBcrInfoEx[i].pt[3].x * fWidthProportion), (stBcrResult->stBcrInfoEx[i].pt[3].y * fHeightProportion));
		PointF points[4] = { point1, point2, point3, point4 };
		PointF* pPoints = points;
		gCode.DrawPolygon(&pen, pPoints, 4);
	}

	Pen pen1(Color(255, 255, 0), 3);
	MV_CODEREADER_WAYBILL_LIST* pstWaybillList = (MV_CODEREADER_WAYBILL_LIST*)pstDisplayImage->pstWaybillList;
	for (int i = 0; i < pstWaybillList->nWaybillNum; i++)
	{
		int x = pstWaybillList->stWaybillInfo[i].fCenterX * fWidthProportion;
		int y = pstWaybillList->stWaybillInfo[i].fCenterY * fHeightProportion;
		int w = pstWaybillList->stWaybillInfo[i].fWidth * fWidthProportion;
		int h = pstWaybillList->stWaybillInfo[i].fHeight * fHeightProportion;
		InnerDrawShape(&gCode, x, y, w, h, pstWaybillList->stWaybillInfo[i].fAngle);
	}

	MV_CODEREADER_OCR_INFO_LIST* pOcrList = (MV_CODEREADER_OCR_INFO_LIST*)pstDisplayImage->UnparsedOcrList.pstOcrList;
	for (int i = 0; i < pOcrList->nOCRAllNum; i++)
	{
		int x = pOcrList->stOcrRowInfo[i].nOcrRowCenterX * fWidthProportion;
		int y = pOcrList->stOcrRowInfo[i].nOcrRowCenterY * fHeightProportion;
		int w = pOcrList->stOcrRowInfo[i].nOcrRowWidth * fWidthProportion;
		int h = pOcrList->stOcrRowInfo[i].nOcrRowHeight * fHeightProportion;

		InnerDrawShape(&gCode, x, y, w, h, pOcrList->stOcrRowInfo[i].fOcrRowAngle);
	}

	::ReleaseDC((HWND)hWnd, hDC);
	return nRet;
}

void * CConfigDlg::ProcessThread(void * pUser)
{
	int nRet = MV_CODEREADER_OK;

	CConfigDlg* pThis = (CConfigDlg*)pUser;
	if (NULL == pThis)
	{
		return NULL;
	}

	MV_CODEREADER_IMAGE_OUT_INFO_EX2 stImageInfo = { 0 };
	unsigned char * pData = NULL;
	while (pThis->m_bStartJob)
	{
		// 获取图像数据
		nRet = MV_CODEREADER_GetOneFrameTimeoutEx2(pThis->m_handle, &pData, &stImageInfo, 1000);
		// 通过帧号判别是条码是历史的还是最新的
		if (stImageInfo.pstCodeListEx != NULL) {
			CString strMsg;
			strMsg.Format(_T("已识别 %d 个对象："), stImageInfo.pstCodeListEx->nCodeNum);
			for (int i = 0; i < stImageInfo.pstCodeListEx->nCodeNum; ++i)
			{
				wchar_t strWchar[MV_CODEREADER_MAX_BCR_CODE_LEN] = { 0 };
				Char2Wchar((char*)stImageInfo.pstCodeListEx->stBcrInfoEx[i].chCode, strWchar, MV_CODEREADER_MAX_BCR_CODE_LEN);
				strMsg.Format(_T("第%d个：[%s], 码类型[%d], 帧号[%d]"), i + 1,
					strWchar,
					(unsigned int)stImageInfo.pstCodeListEx->stBcrInfoEx[i].nBarType,
					stImageInfo.nFrameNum);
				OutputDebugStringW(strMsg);
			}

			/*CString debuginfo;
			debuginfo.Format(_T("code num: %d %d %s"), stImageInfo.pstCodeListEx->nCodeNum,
			stImageInfo.pstCodeListEx->stBcrInfoEx->nID,
			stImageInfo.pstCodeListEx->stBcrInfoEx->chCode);
			OutputDebugStringW(debuginfo);*/
		}
		if (nRet == MV_CODEREADER_OK)
		{
			if (NULL != pData)
			{
				//输出图像结果
				nRet = pThis->Display(pThis->m_hWndDisplay, pData, &stImageInfo);
				if (MV_CODEREADER_OK != nRet)
				{
					continue;
				}
			}

		}
		else
		{
			continue;
		}
	}
}

int CConfigDlg::InitResources()
{
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	try
	{
		int nSensorWidth = 0;
		int nSensorHight = 0;

		// 获取Camera_PayloadSize
		MV_CODEREADER_INTVALUE_EX stParam;
		memset(&stParam, 0, sizeof(MV_CODEREADER_INTVALUE_EX));
		nRet = MV_CODEREADER_GetIntValue(m_handle, Camera_PayloadSize, &stParam);
		if (MV_CODEREADER_OK != nRet)
		{
			// 无该节点则适用最大宽高为payloadSize
			memset(&stParam, 0, sizeof(MV_CODEREADER_INTVALUE_EX));
			nRet = MV_CODEREADER_GetIntValue(m_handle, Camera_Width, &stParam);
			if (MV_CODEREADER_OK != nRet)
			{
				cstrInfo.Format(_T("Get width failed! err code:%#x"), nRet);
				MessageBox(cstrInfo);
				throw nRet;
			}
			nSensorWidth = stParam.nCurValue;

			memset(&stParam, 0, sizeof(MV_CODEREADER_INTVALUE_EX));
			nRet = MV_CODEREADER_GetIntValue(m_handle, Camera_Height, &stParam);
			if (MV_CODEREADER_OK != nRet)
			{
				cstrInfo.Format(_T("Get hight failed! err code:%#x"), nRet);
				MessageBox(cstrInfo);
				throw nRet;
			}
			nSensorHight = stParam.nCurValue;

			m_MaxImageSize = nSensorWidth * nSensorHight + ImageExLen;
		}
		else
		{
			// 获取payloadSize成功
			m_MaxImageSize = stParam.nCurValue + ImageExLen;
		}

		m_pstParam.pBufOutput = (unsigned char*)malloc(m_MaxImageSize);
		if (NULL == m_pstParam.pBufOutput)
		{
			nRet = MV_CODEREADER_E_RESOURCE;
			throw nRet;
		}
		memset(m_pstParam.pBufOutput, 0, m_MaxImageSize);

		m_stParam.pData = (unsigned char*)malloc(m_MaxImageSize);
		if (NULL == m_stParam.pData)
		{
			nRet = MV_CODEREADER_E_RESOURCE;
			throw nRet;
		}
		memset(m_stParam.pData, 0, m_MaxImageSize);

		CString cstrInfo;
		m_pcDataBuf = (unsigned char*)malloc(m_MaxImageSize);
		if (NULL == m_pcDataBuf)
		{
			nRet = MV_CODEREADER_E_RESOURCE;
			throw nRet;
		}
		memset(m_pcDataBuf, 0, m_MaxImageSize);

		// 存储图像信息
		m_pstImageInfoEx2 = (MV_CODEREADER_IMAGE_OUT_INFO_EX2*)malloc(sizeof(MV_CODEREADER_IMAGE_OUT_INFO_EX2));
		if (NULL == m_pstImageInfoEx2)
		{
			nRet = MV_CODEREADER_E_RESOURCE;
			throw nRet;
		}
		memset(m_pstImageInfoEx2, 0, sizeof(MV_CODEREADER_IMAGE_OUT_INFO_EX2));

	}
	catch (...)
	{
		DeInitResources();
		return nRet;
	}

	return nRet;
}

void CConfigDlg::OnBnClickedButtonConnect()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	UpdateData(TRUE);

	if (true == m_bConnect)
	{
		cstrInfo.Format(_T("The camera is already connect"));
		MessageBox(cstrInfo);
		return;
	}

	if (0 == m_stDeviceInfoList.nDeviceNum)
	{
		cstrInfo.Format(_T("Please discovery device first"));
		MessageBox(cstrInfo);
		return;
	}

	if (m_handle)
	{
		MV_CODEREADER_DestroyHandle(m_handle);
		m_handle = NULL;
	}

	// 获取当前选择的设备信息
	int nIndex = m_list_scanner.GetCurSel();
	if (nIndex < 0) {
		cstrInfo.Format(_T("请选中设备！"));
		MessageBox(cstrInfo);
		return;
	}
	memcpy(&m_stDeviceInfo, &m_stDeviceInfoList.pDeviceInfo[nIndex], sizeof(m_stDeviceInfoList.pDeviceInfo[nIndex]));

	// 创建设备句柄
	nRet = MV_CODEREADER_CreateHandle(&m_handle, m_stDeviceInfoList.pDeviceInfo[nIndex]);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Create handle failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}

	// 打开设备
	nRet = MV_CODEREADER_OpenDevice(m_handle);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Open device failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		MV_CODEREADER_DestroyHandle(m_handle);
		m_handle = NULL;
		return;
	}

	// 获取运行模式以及触发模式
	nRet = GetCurrentConfigurationInformation();
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Get param failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}

	// 获取参数
	OnBnClickedGetParameterButton();
	m_bConnect = true;

	// 初始化必要的资源
	InitResources();
	((CButton *)GetDlgItem(IDC_BUTTON_TRIGGER))->SetCheck(FALSE);
}


void CConfigDlg::OnBnClickedRadioCont()
{
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 设置触发模式
	nRet = MV_CODEREADER_SetEnumValue(m_handle, TRIGGER_MODE, MV_CODEREADER_TRIGGER_MODE_OFF);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Set Trigger off Mode failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);

		((CButton *)GetDlgItem(IDC_RADIO_CONT))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_EXTERN))->SetCheck(TRUE);
		return;
	}
	GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CConfigDlg::OnBnClickedRadioExtern()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 设置触发模式
	nRet = MV_CODEREADER_SetEnumValue(m_handle, TRIGGER_MODE, MV_CODEREADER_TRIGGER_MODE_ON);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Set Trigger on Mode failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		((CButton *)GetDlgItem(IDC_RADIO_CONT))->SetCheck(TRUE);
		((CButton *)GetDlgItem(IDC_RADIO_EXTERN))->SetCheck(FALSE);
		return;
	}

	// 设置软触发
	nRet = MV_CODEREADER_SetEnumValue(m_handle, TRIGGER_SOURCE, MV_CODEREADER_TRIGGER_SOURCE_SOFTWARE);   // 选择软触发
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Set Software Mode fialed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}
	else
	{
		m_bIsSoftTrigger = true;
		GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(TRUE);
	}

	if (m_bIsSoftTrigger && m_bStartJob)
	{
		GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(FALSE);
	}

	UpdateData(FALSE);
}

void CConfigDlg::OnBnClickedButtonStartGrab()
{
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;
	m_bStartJob = true;

	// 开始工作流程
	nRet = MV_CODEREADER_StartGrabbing(m_handle);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Start grabbing failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}

	// 创建接收 处理线程
	m_hProcessThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ProcessThread, this, 0, NULL);
	if (NULL == m_hProcessThread)
	{
		cstrInfo.Format(_T("Create proccess Thread failed! "));
		MessageBox(cstrInfo);
		return;
	}

	GetDlgItem(IDC_RADIO_CONT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_EXTERN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_START_GRAB)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_STOP_GRAB)->EnableWindow(TRUE);
}


void CConfigDlg::OnBnClickedButtonStopGrab()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	m_bStartJob = false;
	// 销毁取流线程
	if (NULL != m_hProcessThread)
	{
		//等待线程结束，关闭释放线程
		WaitForSingleObject(m_hProcessThread, 1000);
		CloseHandle(m_hProcessThread);
		m_hProcessThread = NULL;
	}

	// 停止工作流程
	nRet = MV_CODEREADER_StopGrabbing(m_handle);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Stop grabbing failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		m_bStartJob = false;
		return;
	}


	GetDlgItem(IDC_RADIO_CONT)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_EXTERN)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_START_GRAB)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_STOP_GRAB)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_TRIGGER)->EnableWindow(FALSE);
}



void CConfigDlg::OnBnClickedButtonTrigger()
{
	// TODO: Add your control notification handler code here
	int nRet = MV_CODEREADER_OK;
	CString cstrInfo;

	// 软触发
	nRet = MV_CODEREADER_SetCommandValue(m_handle, TRIGGER_SOFTWARE);
	if (MV_CODEREADER_OK != nRet)
	{
		cstrInfo.Format(_T("Set Software Once failed! err code:%#x"), nRet);
		MessageBox(cstrInfo);
		return;
	}
}
