// ShowInfo.cpp : implementation file
//

#include "stdafx.h"
#include "AIDetection.h"
#include "ShowInfo.h"
#include "afxdialogex.h"
#include "AIDetectionDlg.h"
#include "DetectionDlg.h"

extern CAIDetectionDlg *g_dlg;
extern CDetectionDlg *pCDetectionDlg;

// ShowInfo dialog

struct REF {
	std::string ref;
};

IMPLEMENT_DYNAMIC(ShowInfo, CDialog)

ShowInfo::ShowInfo(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWINFO, pParent)
{

}

ShowInfo::~ShowInfo()
{
}

void ShowInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INFO, m_list_info);
}


BEGIN_MESSAGE_MAP(ShowInfo, CDialog)
	ON_BN_CLICKED(IDVIEW, &ShowInfo::OnBnClickedView)
	ON_BN_CLICKED(IDOK, &ShowInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowInfo message handlers


BOOL ShowInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	DWORD dwStyle = m_list_info.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list_info.SetExtendedStyle(dwStyle);

	if (m_mode == 0) {
		SetWindowText(_T("检定依据"));
		m_list_info.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 50);
		m_list_info.InsertColumn(1, _T("名称"), LVCFMT_CENTER, 120);
		int id = 0;
		for each (auto item in g_dlg->m_dboperator.m_VerifyBasis)
		{
			CString ids;
			ids.Format(_T("%d"), id+1);
			m_list_info.InsertItem(id, ids);
			m_list_info.SetItemText(id, 1, CStringW(item.jdyj.c_str()));
			REF *ref_stru = new REF{ item.ref };
			m_list_info.SetItemData(id, (DWORD_PTR)ref_stru);
			id += 1;
		}
	}
	else if (m_mode == 1) {
		SetWindowText(_T("计量标准"));
		m_list_info.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 50);
		m_list_info.InsertColumn(1, _T("名称"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(2, _T("测量范围"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(3, _T("准确度等级"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(4, _T("证书编号"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(5, _T("有效期限"), LVCFMT_CENTER, 60);

		int id = 0;
		for each (auto item in g_dlg->m_dboperator.m_Measurestd)
		{
			CString ids;
			ids.Format(_T("%d"), id + 1);
			m_list_info.InsertItem(id, ids);
			m_list_info.SetItemText(id, 1, CStringW(item.mc.c_str()));
			m_list_info.SetItemText(id, 2, CStringW(item.clfw.c_str()));
			m_list_info.SetItemText(id, 3, CStringW(item.zqddj.c_str()));
			m_list_info.SetItemText(id, 4, CStringW(item.zsbh.c_str()));
			CString qjsj_c;
			qjsj_c.Format(_T("%04d-%02d-%02d"), item.yxqx.year, item.yxqx.mouth, item.yxqx.day);
			m_list_info.SetItemText(id, 5, qjsj_c);

			id += 1;
		}
	}
	else {
		SetWindowText(_T("计量器具"));
		m_list_info.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 50);
		m_list_info.InsertColumn(1, _T("名称"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(2, _T("型号规格"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(3, _T("编号"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(4, _T("测量范围"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(5, _T("准确度等级"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(6, _T("证书编号"), LVCFMT_CENTER, 60);
		m_list_info.InsertColumn(7, _T("有效期限"), LVCFMT_CENTER, 60);

		int id = 0;
		for each (auto item in g_dlg->m_dboperator.m_Measureist)
		{
			CString ids;
			ids.Format(_T("%d"), id + 1);
			m_list_info.InsertItem(id, ids);
			m_list_info.SetItemText(id, 1, CStringW(item.mc.c_str()));
			m_list_info.SetItemText(id, 2, CStringW(item.xhgg.c_str()));
			m_list_info.SetItemText(id, 3, CStringW(item.bh.c_str()));
			m_list_info.SetItemText(id, 4, CStringW(item.clfw.c_str()));
			m_list_info.SetItemText(id, 5, CStringW(item.zqddj.c_str()));
			m_list_info.SetItemText(id, 6, CStringW(item.zsbh.c_str()));

			CString yxqx_c;
			yxqx_c.Format(_T("%04d-%02d-%02d"), item.yxqx.year, item.yxqx.mouth, item.yxqx.day);
			m_list_info.SetItemText(id, 7, yxqx_c);

			id += 1;
		}

	}

	AdjustColumnWidth();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void ShowInfo::setMode(int mode)
{
	m_mode = mode;
}

void ShowInfo::AdjustColumnWidth()
{
	SetRedraw(FALSE);
	//m_listCtrl为我自己定义的ListCtrl控件关联的变量名
	int nColumnCount = m_list_info.GetHeaderCtrl()->GetItemCount();//获取列数
	for (int i = 0; i < nColumnCount; i++)
	{
		m_list_info.SetColumnWidth(i, LVSCW_AUTOSIZE);
		int nColumnWidth = m_list_info.GetColumnWidth(i);
		m_list_info.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
		int nHeaderWidth = m_list_info.GetColumnWidth(i);

		//最后显示该列中宽度值最大的宽度
		m_list_info.SetColumnWidth(i, max(nColumnWidth, nHeaderWidth));
	}
	SetRedraw(TRUE);
}

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t) *(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	return wcstring;
}

void ShowInfo::OnBnClickedView()
{
	// TODO: Add your control notification handler code here
	int nIndex = m_list_info.GetSelectionMark();
	if (nIndex < 0)
		return;
	REF *pRef = (REF*)m_list_info.GetItemData(nIndex);
	if (!pRef)
		return;
	string ref = pRef->ref;
	ShellExecute(NULL, _T("open"), stringToLPCWSTR(ref), NULL, NULL, SW_SHOWNORMAL);
}


void ShowInfo::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int row = m_list_info.GetSelectionMark();
	if (row < 0) {
		AfxMessageBox(CString("No selected!"));
	}
	else {
		CString info;
		switch (m_mode)
		{
		case 0:
		{
			info = m_list_info.GetItemText(row, 1);
			break;
		}
		case 1:
		{
			info = m_list_info.GetItemText(row, 1) + CString('-') + m_list_info.GetItemText(row, 4);
			break;
		}
		case 2:
		{
			info = m_list_info.GetItemText(row, 1);
			break;
		}
		default:
			break;
		}

		pCDetectionDlg->showInfo(m_mode, info);
		CDialog::OnOK();
	}
}
