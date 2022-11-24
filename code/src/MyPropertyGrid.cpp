// MyPropertyGrid.cpp
//

#include "stdafx.h"
#include "MyPropertyGrid.h"

////////////////////////////////////////////////////////////////////////////
// CMFCPropertyGridDateTimeProperty object
IMPLEMENT_DYNAMIC(CMFCPropertyGridDateTimeProperty, CMFCPropertyGridProperty)
CMFCPropertyGridDateTimeProperty::CMFCPropertyGridDateTimeProperty(const CString& strName, const CString& strDateTime,
	LPCTSTR lpszDescr, BOOL isDate) : CMFCPropertyGridProperty(strName, COleVariant(strDateTime), lpszDescr)
{
	m_bIsDate = isDate;
	m_dtCtrl = NULL;
}


CMFCPropertyGridDateTimeProperty::~CMFCPropertyGridDateTimeProperty(void)
{
}

BOOL CMFCPropertyGridDateTimeProperty::OnClickValue(UINT uiMsg, CPoint point)
{
	ASSERT_VALID(this);
	// m_pWndInPlace�Ǹ����������б��ϵı༭��
	ASSERT_VALID(m_pWndInPlace);
	ASSERT(::IsWindow(m_pWndInPlace->GetSafeHwnd()));

	CString str;
	m_pWndInPlace->GetWindowText(str);

	COleDateTime oleTime;
	CString timeStr;
	if (!m_bIsDate)
		timeStr.Format(_T("2016-1-1 %s"), str);
	else
		timeStr.Format(_T("%s 0:0:0"), str);
	oleTime.ParseDateTime(timeStr);

	// m_pWndInPlace�ĸ�������CMFCPropertyGridCtrl
	CWnd *pPropertyCtl = (CWnd*)(m_pWndInPlace->GetParent());

	// ��Ҫ����CMFCPropertyGridProperty��ָ�봫�ݸ�DateTimeCtrl�ؼ�
	m_dtCtrl = new CInnerDateTimeCtrl(this, m_bIsDate);

	CRect rect;
	m_pWndInPlace->GetWindowRect(rect);
	pPropertyCtl->ScreenToClient(rect);

	// ��ԭ�༭�����أ�����m_dtCtrl������ȷ��ʾ
	m_pWndInPlace->ShowWindow(SW_HIDE);

	// ����m_dtCtrl����ʾλ��
	rect.top -= 3;
	rect.bottom += 5;
	rect.left -= 4;
	// ����CDateTimeCtrl����ʾ����
	DWORD dtsStyle = WS_VISIBLE | WS_CHILD | WS_BORDER;
	if (!m_bIsDate)
		dtsStyle |= DTS_TIMEFORMAT;		//ʱ������
	else
		dtsStyle |= DTS_SHORTDATEFORMAT | DTS_UPDOWN;		//��������
	m_dtCtrl->Create(dtsStyle, rect, pPropertyCtl, 1001);
	::SetWindowPos(m_dtCtrl->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	m_dtCtrl->SetTime(oleTime);

	// �����ڿؼ���ý���
	m_dtCtrl->SetFocus();
	return TRUE;
}

