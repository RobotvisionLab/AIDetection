// MyAbout.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AIDetection.h"
#include "MyAbout.h"
#include "afxdialogex.h"


// CMyAbout �Ի���

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


// CMyAbout ��Ϣ�������


BOOL CMyAbout::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//m_Icon_About = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//((CStatic*)GetDlgItem(IDC_STATIC_ABOUT_ICON))->SetIcon(m_Icon_About);

	HBITMAP hBitmap;
	hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_ABOUT));
	m_about_icon.SetBitmap(hBitmap);

	m_font.CreatePointFont(200, _T("΢���ź�"), NULL);
	m_static_about_title.SetFont(&m_font);

	//��̬����  
	EnableDynamicLayout();
	auto pdlmanager = GetDynamicLayout();
	if (pdlmanager) {
		if (pdlmanager->Create(this)) {
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_ABOUT_FGX)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
			pdlmanager->AddItem(GetDlgItem(IDC_STATIC_WHITE)->GetSafeHwnd(), CMFCDynamicLayout::MoveHorizontalAndVertical(0, 0), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CMyAbout::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	//��̬�ı��򱳾�͸��
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_ABOUT_TITLE)
	{
		//pDC->SetTextColor(RGB(0, 0, 0));//�����ı���������ɫ
		//pDC->SetBkMode(OPAQUE);
		pDC->SetBkColor(RGB(255, 255, 255));//�����ı�����Ϊ��ɫ
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));//��仰���ܵ�
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


