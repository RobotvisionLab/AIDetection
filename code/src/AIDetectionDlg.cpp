
// AIDetectionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "AIDetectionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAIDetectionDlg 对话框



CAIDetectionDlg::CAIDetectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AIDETECTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_curtdlgIndex = 1;
}

CAIDetectionDlg::~CAIDetectionDlg()
{
}

void CAIDetectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAIDetectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_COMMAND(ID_TOOLBAR_LOGIN, &OnLogin)
	ON_COMMAND(ID_TOOLBAR_INPUT, &OnInput)
	ON_COMMAND(ID_TOOLBAR_DETECTION, &OnDetection)
	ON_COMMAND(ID_TOOLBAR_APPROVAL, &OnApproval)
	ON_COMMAND(ID_TOOLBAR_SETTING, &OnConfig)
	ON_COMMAND(ID_TOOLBAR_ABOUT, &OnAbout)
	ON_COMMAND(ID_TOOLBAR_EXIT, &OnExit)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAIDetectionDlg 消息处理程序


BOOL CAIDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if(!m_dboperator.initDB())
	{
		EndDialog(IDCANCEL);
	}

	m_dboperator.getAllInfo();

	//初始化工具栏
	m_ImageList.Create(48, 48, ILC_COLOR24 | ILC_MASK, 0, 1);
	for (int i = 0; i < 7; i++)
	{
		m_ImageList.Add(AfxGetApp()->LoadIconW(IDI_ICON_LOGIN + i));
	}

	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR))
	{
		EndDialog(IDCANCEL);
	}

	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);
	m_ToolBar.ModifyStyle(0, BTNS_SHOWTEXT | TBSTYLE_EX_MIXEDBUTTONS | TBSTYLE_LIST);
	m_ToolBar.SetButtonText(0, _T("注销"));
	m_ToolBar.SetButtonText(2, _T("录入/查询"));
	m_ToolBar.SetButtonText(3, _T("检测/检定"));
	m_ToolBar.SetButtonText(4, _T("核验/审批"));
	m_ToolBar.SetButtonText(6, _T("配置/设置"));
	m_ToolBar.SetButtonText(7, _T("帮助/关于"));
	m_ToolBar.SetButtonText(9, _T("退出"));


	// 显示工具栏，状态栏
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	m_ToolBar.ShowWindow(SW_HIDE);

	//设置子对话框位置
	getRects();
	m_loginDlg.Create(IDD_LOGINDLG, this);
	m_inputDlg.Create(IDD_INPUTDLG, this);
	m_detectionDlg.Create(IDD_DETECTIONDLG, this);
	m_myaboutDlg.Create(IDD_MYABOUT, this);
	m_configDlg.Create(IDD_CONFIGDLG, this);

	m_loginDlg.MoveWindow(&m_mainRect);
	m_inputDlg.MoveWindow(&m_dlgRect);
	m_detectionDlg.MoveWindow(&m_dlgRect);
	m_myaboutDlg.MoveWindow(&m_dlgRect);
	m_configDlg.MoveWindow(&m_dlgRect);

	m_loginDlg.ShowWindow(SW_SHOW);
	//获取工具栏、状态栏等

	 
	//此处用控件动态布局会导致 状态栏被吃掉，因此使用手动自适应，键OnSize
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		if (pdlmanager->Create(this)) {
			//pdlmanager->AddItem(m_loginDlg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 100));
			//pdlmanager->AddItem(m_inputDlg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 100));
			//pdlmanager->AddItem(m_detectionDlg.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 100));
			//pdlmanager->AddItem(m_StatusBar.GetSafeHwnd(), CMFCDynamicLayout::MoveVertical(100), CMFCDynamicLayout::SizeHorizontal(100));
			pdlmanager->AddItem(m_ToolBar.GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontal(100));
		}
	}
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAIDetectionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAIDetectionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAIDetectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAIDetectionDlg::getRects()
{
	if (!m_ToolBar.m_hWnd || !m_ToolBar.m_hWnd)
		return;

	m_ToolBar.GetClientRect(&m_toolbarRect);
	GetClientRect(&m_mainRect);

	m_dlgRect.left = m_mainRect.left + 1;
	m_dlgRect.top = m_toolbarRect.bottom + 1;
	m_dlgRect.bottom = m_mainRect.bottom -1;
	m_dlgRect.right = m_mainRect.right - 1;

	m_statusbarRect.left = m_mainRect.left + 1;
	m_statusbarRect.top = m_dlgRect.bottom + 1;
	m_statusbarRect.bottom = m_mainRect.bottom;
	m_statusbarRect.right = m_mainRect.right - 1;
}

void CAIDetectionDlg::changeVisible(int newIndex)
{
	//未改变
	if (newIndex == m_curtdlgIndex)
		return;

	//当前在录入界面
	if (m_curtdlgIndex == 1) {
		//点击注销按钮
		if (newIndex == 0) {
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
			m_inputDlg.ShowWindow(SW_HIDE);
		}
		//点击检测按钮
		else if (newIndex == 2) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//点击核验按钮
		else if (newIndex == 3) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(false);
		}
		//点击设置按钮
		else if (newIndex == 4) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_configDlg.ShowWindow(SW_SHOW);
		}
		//点击关于按钮
		else if (newIndex == 5) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//当前在检测界面
	else if (m_curtdlgIndex == 2) {
		//点击注销按钮
		if (newIndex == 0) {
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.ShowWindow(SW_HIDE);
		}
		//点击录入按钮
		else if (newIndex == 1) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//点击核验按钮
		else if (newIndex == 3) {
			m_detectionDlg.switchMode(false);
		}
		//点击设置按钮
		else if (newIndex == 4) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_configDlg.ShowWindow(SW_SHOW);
		}
		//点击关于按钮
		else if (newIndex == 5) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//当前在核验界面
	else if (m_curtdlgIndex == 3) {
			//点击注销按钮
			if (newIndex == 0) {
				m_ToolBar.ShowWindow(SW_HIDE);
				m_loginDlg.ShowWindow(SW_SHOW);
				m_detectionDlg.ShowWindow(SW_HIDE);
			}
			//点击录入按钮
			else if (newIndex == 1) {
				m_inputDlg.ShowWindow(SW_SHOW);
				m_detectionDlg.ShowWindow(SW_HIDE);
			}
			//点击检测钮
			else if (newIndex == 2) {
				m_detectionDlg.switchMode(true);
			}
			//点击设置按钮
			else if (newIndex == 4) {
				m_detectionDlg.ShowWindow(SW_HIDE);
				m_configDlg.ShowWindow(SW_SHOW);
			}
			//点击关于按钮
			else if (newIndex == 5) {
				m_detectionDlg.ShowWindow(SW_HIDE);
				m_myaboutDlg.ShowWindow(SW_SHOW);
			}
		}
	//当前在设置界面
	else if (m_curtdlgIndex == 4) {
		if (!m_configDlg.IsSave())
			return;
		//点击注销按钮
		if (newIndex == 0) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
		}
		//点击录入按钮
		else if (newIndex == 1) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//点击检测按钮
		else if (newIndex == 2) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//点击核验按钮
		else if (newIndex == 3) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(false);
		}
		//点击关于按钮
		else if (newIndex == 5) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//当前在关于界面
	else if (m_curtdlgIndex == 5) {
		//点击注销按钮
		if (newIndex == 0) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
		}
		//点击录入按钮
		else if (newIndex == 1) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//点击检测按钮
		else if (newIndex == 2) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//点击核验按钮
		else if (newIndex == 3) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(false);
		}
		else if (newIndex == 4) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_configDlg.ShowWindow(SW_SHOW);
		}
	}
	m_curtdlgIndex = newIndex;
}


void CAIDetectionDlg::OnLogin()
{
	for (int i = 0; i < 3; i++) {
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_INPUT + i, true);
	}
	changeVisible(0);
}

void CAIDetectionDlg::OnInput()
{
	changeVisible(1);
}

void CAIDetectionDlg::OnDetection()
{
	changeVisible(2);
}

void CAIDetectionDlg::OnApproval()
{
	changeVisible(3);
}

void CAIDetectionDlg::OnConfig()
{
	changeVisible(4);
}

void CAIDetectionDlg::OnAbout()
{
	changeVisible(5);
}

void CAIDetectionDlg::OnExit()
{
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}


void CAIDetectionDlg::loginSuccess(int role_id)
{
	m_loginDlg.ShowWindow(SW_HIDE);
	m_ToolBar.ShowWindow(SW_SHOW);
	m_inputDlg.MoveWindow(&m_dlgRect);
	m_inputDlg.ShowWindow(SW_SHOW);
	m_curtdlgIndex = 1;
	currentUser = (ROLE)role_id;

	if (currentUser == INPUTOR) {
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_DETECTION, false);
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_APPROVAL, false);
	}
	else if (currentUser == DETECTIOR) {
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_INPUT, false);
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_APPROVAL, false);
		this->OnDetection();
	}
	else if (currentUser == VERIFIER || currentUser == APPROVIOR) {
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_INPUT, false);
		m_ToolBar.GetToolBarCtrl().EnableButton(ID_TOOLBAR_DETECTION, false);
		this->OnApproval();
	}
	else if (currentUser == ROOT) {
		;
	}
	m_detectionDlg.setRole(currentUser);
}

BOOL CAIDetectionDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	// 屏蔽ESC键
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}


void CAIDetectionDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	// 屏蔽Enter键
	//CDialogEx::OnOK();
}


void CAIDetectionDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码
	//CRect test;
	//GetClientRect(&test);
	//char s[64] = { 0 };
	//sprintf_s(s, "MainDlg top: %d left: %d bottom: %d right: %d \n", test.top, test.left, test.bottom, test.right);
	//OutputDebugString(CString(s).GetBuffer());
	if (nType != SIZE_MINIMIZED)
	{
		getRects();
		CWnd *pWnd = GetWindow(GW_CHILD);
		while (pWnd)
		{
			if (pWnd != NULL)
			{
				TCHAR szClass[65] = { 0 };
				GetClassName(pWnd->m_hWnd, szClass, 64);

				OutputDebugString(szClass);
				OutputDebugString(CString("\n"));

				//状态栏
				//if (_tcsicmp(szClass, _T("msctls_statusbar32")) == 0) {
				//	m_StatusBar.MoveWindow(0, m_statusbarRect.top, m_statusbarRect.right, 20, TRUE);
				//}
				//工具栏
				if (_tcsicmp(szClass, _T("ToolbarWindow32")) == 0) {
					;
				}
				else {
				//子对话框
					m_loginDlg.MoveWindow(&m_mainRect);
					m_inputDlg.MoveWindow(&m_dlgRect);
					m_detectionDlg.MoveWindow(&m_dlgRect);
					m_myaboutDlg.MoveWindow(&m_dlgRect);
					m_configDlg.MoveWindow(&m_dlgRect);
				}
			}
			pWnd = pWnd->GetNextWindow();
		}
	}
}
