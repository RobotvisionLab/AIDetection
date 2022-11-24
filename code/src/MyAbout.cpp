// MyAbout.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "MyAbout.h"
#include "afxdialogex.h"


// CMyAbout 对话框

IMPLEMENT_DYNAMIC(CMyAbout, CDialogEx)

CMyAbout::CMyAbout(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYABOUT, pParent)
{

}

CMyAbout::~CMyAbout()
{
}

void CMyAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ABOUT_ICON, m_about_icon);
	DDX_Control(pDX, IDC_STATIC_ABOUT_TITLE, m_static_about_title);
}


BEGIN_MESSAGE_MAP(CMyAbout, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMyAbout 消息处理程序


BOOL CMyAbout::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//m_Icon_About = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//((CStatic*)GetDlgItem(IDC_STATIC_ABOUT_ICON))->SetIcon(m_Icon_About);

	HBITMAP hBitmap;
	hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_ABOUT));
	m_about_icon.SetBitmap(hBitmap);

	m_font.CreatePointFont(200, _T("微软雅黑"), NULL);
	m_static_about_title.SetFont(&m_font);

	//动态布局  
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		if (pdlmanager->Create(this)) {
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_ABOUT_FGX)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_WHITE)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CMyAbout::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	//静态文本框背景透明
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_ABOUT_TITLE)
	{
		//pDC->SetTextColor(RGB(0, 0, 0));//设置文本框字体颜色
		//pDC->SetBkMode(OPAQUE);
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景为白色
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));//这句话不能掉
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


