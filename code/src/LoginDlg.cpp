// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AIDetection.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "AIDetectionDlg.h"
extern CAIDetectionDlg *g_dlg;

// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�޸ľ�̬�ı�����
	//m_font_title, m_font Ҫ��Ϊȫ�ֲ���Ч
	CWnd* pWnd = GetDlgItem(IDC_STATIC_TITLE);
	pWnd->SetWindowText(_T("ѹ�������ܼ춨ϵͳ"));
	m_font_title.CreatePointFont(320, _T("΢���ź�"), NULL);
	pWnd->SetFont(&m_font_title);

	m_font.CreatePointFont(150, _T("����"), NULL);
	GetDlgItem(IDC_STATIC_USER)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC_PWD)->SetFont(&m_font);
	GetDlgItem(IDOK)->SetFont(&m_font);
	GetDlgItem(IDCANCEL)->SetFont(&m_font);

	m_edit_user.SetWindowTextW(CString("root"));
	m_edit_pwd.SetWindowTextW(CString("123456"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
					   //������ͼ
					   // ��������DC
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(&dc);

	// ����λͼ
	CBitmap bmpLead;
	bmpLead.LoadBitmap(IDB_BITMAP_LOGIN);

	// ��ȡλͼ��Ϣ
	BITMAP bmpInfo;
	bmpLead.GetBitmap(&bmpInfo);

	// ��λͼ�����ڴ棬���ؾ�ֵ
	CBitmap *pOldBitmap = dcMemory.SelectObject(&bmpLead);
	CRect rect;
	//����Ӧ��С
	GetClientRect(&rect);
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMemory, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	// �����ֵ
	dcMemory.SelectObject(pOldBitmap);
	DeleteObject(bmpLead);
}




HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	//��̬�ı��򱳾�͸��
	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TITLE || pWnd->GetDlgCtrlID() == IDC_STATIC_USER || pWnd->GetDlgCtrlID() == IDC_STATIC_PWD)
	{
		pDC->SetTextColor(RGB(255, 255, 255));//�����ı���������ɫ
		pDC->SetBkMode(TRANSPARENT);//��͸��
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));//��仰���ܵ�
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}



void CLoginDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	GetParent()->DestroyWindow();
}


void CLoginDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	// ��ֹ����ͼƬ�ص�ʧ��
	Invalidate(FALSE);
}
