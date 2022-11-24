// InnerDateTimeCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AIDetection.h"
#include "InnerDateTimeCtrl.h"


// CInnerDateTimeCtrl

IMPLEMENT_DYNAMIC(CInnerDateTimeCtrl, CDateTimeCtrl)


CInnerDateTimeCtrl::CInnerDateTimeCtrl(CMFCPropertyGridProperty * editWnd, BOOL isDate)
{
	m_editWnd = editWnd;
	m_isDate = isDate;
}

CInnerDateTimeCtrl::~CInnerDateTimeCtrl()
{
}


BEGIN_MESSAGE_MAP(CInnerDateTimeCtrl, CDateTimeCtrl)
	ON_WM_KILLFOCUS()
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()



// CInnerDateTimeCtrl ��Ϣ�������




void CInnerDateTimeCtrl::OnKillFocus(CWnd* pNewWnd)
{
	CDateTimeCtrl::OnKillFocus(pNewWnd);

	// TODO: �ڴ˴������Ϣ����������
	COleDateTime oleTime;
	GetTime(oleTime);

	CString str = _T("");
	if (m_isDate)
		str = oleTime.Format(_T("%Y-%m-%d"));
	else
		str = oleTime.Format(_T("%H:%M:%S"));

	// �޸������б��ֵ
	m_editWnd->SetValue(str);

	// ��������
	DestroyWindow();
}


void CInnerDateTimeCtrl::OnNcDestroy()
{
	CDateTimeCtrl::OnNcDestroy();

	// TODO: �ڴ˴������Ϣ����������
	// �ͷ��ڴ�
	delete this;
}
