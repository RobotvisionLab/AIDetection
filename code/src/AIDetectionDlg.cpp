
// AIDetectionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AIDetection.h"
#include "AIDetectionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CAIDetectionDlg �Ի���



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


// CAIDetectionDlg ��Ϣ�������


BOOL CAIDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if(!m_dboperator.initDB())
	{
		EndDialog(IDCANCEL);
	}

	m_dboperator.getAllInfo();

	//��ʼ��������
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
	m_ToolBar.SetButtonText(0, _T("ע��"));
	m_ToolBar.SetButtonText(2, _T("¼��/��ѯ"));
	m_ToolBar.SetButtonText(3, _T("���/�춨"));
	m_ToolBar.SetButtonText(4, _T("����/����"));
	m_ToolBar.SetButtonText(6, _T("����/����"));
	m_ToolBar.SetButtonText(7, _T("����/����"));
	m_ToolBar.SetButtonText(9, _T("�˳�"));


	// ��ʾ��������״̬��
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	m_ToolBar.ShowWindow(SW_HIDE);

	//�����ӶԻ���λ��
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
	//��ȡ��������״̬����

	 
	//�˴��ÿؼ���̬���ֻᵼ�� ״̬�����Ե������ʹ���ֶ�����Ӧ����OnSize
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
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAIDetectionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	//δ�ı�
	if (newIndex == m_curtdlgIndex)
		return;

	//��ǰ��¼�����
	if (m_curtdlgIndex == 1) {
		//���ע����ť
		if (newIndex == 0) {
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
			m_inputDlg.ShowWindow(SW_HIDE);
		}
		//�����ⰴť
		else if (newIndex == 2) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//������鰴ť
		else if (newIndex == 3) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(false);
		}
		//������ð�ť
		else if (newIndex == 4) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_configDlg.ShowWindow(SW_SHOW);
		}
		//������ڰ�ť
		else if (newIndex == 5) {
			m_inputDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//��ǰ�ڼ�����
	else if (m_curtdlgIndex == 2) {
		//���ע����ť
		if (newIndex == 0) {
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.ShowWindow(SW_HIDE);
		}
		//���¼�밴ť
		else if (newIndex == 1) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//������鰴ť
		else if (newIndex == 3) {
			m_detectionDlg.switchMode(false);
		}
		//������ð�ť
		else if (newIndex == 4) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_configDlg.ShowWindow(SW_SHOW);
		}
		//������ڰ�ť
		else if (newIndex == 5) {
			m_detectionDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//��ǰ�ں������
	else if (m_curtdlgIndex == 3) {
			//���ע����ť
			if (newIndex == 0) {
				m_ToolBar.ShowWindow(SW_HIDE);
				m_loginDlg.ShowWindow(SW_SHOW);
				m_detectionDlg.ShowWindow(SW_HIDE);
			}
			//���¼�밴ť
			else if (newIndex == 1) {
				m_inputDlg.ShowWindow(SW_SHOW);
				m_detectionDlg.ShowWindow(SW_HIDE);
			}
			//������ť
			else if (newIndex == 2) {
				m_detectionDlg.switchMode(true);
			}
			//������ð�ť
			else if (newIndex == 4) {
				m_detectionDlg.ShowWindow(SW_HIDE);
				m_configDlg.ShowWindow(SW_SHOW);
			}
			//������ڰ�ť
			else if (newIndex == 5) {
				m_detectionDlg.ShowWindow(SW_HIDE);
				m_myaboutDlg.ShowWindow(SW_SHOW);
			}
		}
	//��ǰ�����ý���
	else if (m_curtdlgIndex == 4) {
		if (!m_configDlg.IsSave())
			return;
		//���ע����ť
		if (newIndex == 0) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
		}
		//���¼�밴ť
		else if (newIndex == 1) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//�����ⰴť
		else if (newIndex == 2) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//������鰴ť
		else if (newIndex == 3) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(false);
		}
		//������ڰ�ť
		else if (newIndex == 5) {
			m_configDlg.ShowWindow(SW_HIDE);
			m_myaboutDlg.ShowWindow(SW_SHOW);
		}
	}
	//��ǰ�ڹ��ڽ���
	else if (m_curtdlgIndex == 5) {
		//���ע����ť
		if (newIndex == 0) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_ToolBar.ShowWindow(SW_HIDE);
			m_loginDlg.ShowWindow(SW_SHOW);
		}
		//���¼�밴ť
		else if (newIndex == 1) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_inputDlg.ShowWindow(SW_SHOW);
		}
		//�����ⰴť
		else if (newIndex == 2) {
			m_myaboutDlg.ShowWindow(SW_HIDE);
			m_detectionDlg.ShowWindow(SW_SHOW);
			m_detectionDlg.switchMode(true);
		}
		//������鰴ť
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
	// TODO: �ڴ����ר�ô����/����û���
	// ����ESC��
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}


void CAIDetectionDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	// ����Enter��
	//CDialogEx::OnOK();
}


void CAIDetectionDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
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

				//״̬��
				//if (_tcsicmp(szClass, _T("msctls_statusbar32")) == 0) {
				//	m_StatusBar.MoveWindow(0, m_statusbarRect.top, m_statusbarRect.right, 20, TRUE);
				//}
				//������
				if (_tcsicmp(szClass, _T("ToolbarWindow32")) == 0) {
					;
				}
				else {
				//�ӶԻ���
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
