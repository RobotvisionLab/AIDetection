// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AIDetection.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "AIDetectionDlg.h"
extern CAIDetectionDlg *g_dlg;

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGINDLG, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USER, m_edit_user);
	DDX_Control(pDX, IDC_EDIT_PWD, m_edit_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//修改静态文本字体
	//m_font_title, m_font 要设为全局才有效
	CWnd* pWnd = GetDlgItem(IDC_STATIC_TITLE);
	pWnd->SetWindowText(_T("压力表智能检定系统"));
	m_font_title.CreatePointFont(320, _T("微软雅黑"), NULL);
	pWnd->SetFont(&m_font_title);

	m_font.CreatePointFont(150, _T("宋体"), NULL);
	GetDlgItem(IDC_STATIC_USER)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC_PWD)->SetFont(&m_font);
	GetDlgItem(IDOK)->SetFont(&m_font);
	GetDlgItem(IDCANCEL)->SetFont(&m_font);

	m_edit_user.SetWindowTextW(CString("root"));
	m_edit_pwd.SetWindowTextW(CString("123456"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
					   //背景贴图
					   // 创建兼容DC
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(&dc);

	// 载入位图
	CBitmap bmpLead;
	bmpLead.LoadBitmap(IDB_BITMAP_LOGIN);

	// 获取位图信息
	BITMAP bmpInfo;
	bmpLead.GetBitmap(&bmpInfo);

	// 将位图载入内存，返回旧值
	CBitmap *pOldBitmap = dcMemory.SelectObject(&bmpLead);
	CRect rect;
	//自适应大小
	GetClientRect(&rect);
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMemory, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	// 载入旧值
	dcMemory.SelectObject(pOldBitmap);
	DeleteObject(bmpLead);
}




HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	//静态文本框背景透明
	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TITLE || pWnd->GetDlgCtrlID() == IDC_STATIC_USER || pWnd->GetDlgCtrlID() == IDC_STATIC_PWD)
	{
		pDC->SetTextColor(RGB(255, 255, 255));//设置文本框字体颜色
		pDC->SetBkMode(TRANSPARENT);//设透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));//这句话不能掉
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}



void CLoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strName, strPass;
	m_edit_user.GetWindowTextW(strName);
	m_edit_pwd.GetWindowTextW(strPass);

	if (strName.IsEmpty() || strPass.IsEmpty()) {
		AfxMessageBox(CString("Empty"));
	}

	for (int i = 0; i < g_dlg->m_dboperator.m_Userinfo.size(); i++) {
		if (CStringW(g_dlg->m_dboperator.m_Userinfo[i].xm.c_str()) == strName) {
			if (CStringW(g_dlg->m_dboperator.m_Userinfo[i].mm.c_str()) == strPass) {
				CAIDetectionDlg *pMaindlg = (CAIDetectionDlg*)GetParent();
				pMaindlg->loginSuccess(g_dlg->m_dboperator.m_Userinfo[i].js);
				return;
			}
			else {
				AfxMessageBox(CString("Password Error"));
				m_edit_pwd.SetWindowTextW(CString(""));
				m_edit_pwd.SetFocus();
				return;
			}
		}
	}

	AfxMessageBox(CString("No User"));
	m_edit_user.SetWindowTextW(CString(""));
	m_edit_pwd.SetWindowTextW(CString(""));
	m_edit_user.SetFocus();
	return;
	//if (strName == "root" && strPass == "123456") {
	//	CAIDetectionDlg *pMaindlg = (CAIDetectionDlg*)GetParent();
	//	pMaindlg->loginSuccess();
	//}
	//else {
	//	AfxMessageBox(CString("Error"));
	//	m_edit_user.SetWindowTextW(CString(""));
	//	m_edit_pwd.SetWindowTextW(CString(""));
	//	m_edit_user.SetFocus();
	//}
	//CDialogEx::OnOK();
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	GetParent()->DestroyWindow();
}


void CLoginDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	// 防止背景图片重叠失真
	Invalidate(FALSE);
}
