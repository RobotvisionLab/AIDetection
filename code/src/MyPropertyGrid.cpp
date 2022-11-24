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
	// m_pWndInPlace是浮动在属性列表上的编辑框
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

	// m_pWndInPlace的父窗口是CMFCPropertyGridCtrl
	CWnd *pPropertyCtl = (CWnd*)(m_pWndInPlace->GetParent());

	// 需要将本CMFCPropertyGridProperty的指针传递给DateTimeCtrl控件
	m_dtCtrl = new CInnerDateTimeCtrl(this, m_bIsDate);

	CRect rect;
	m_pWndInPlace->GetWindowRect(rect);
	pPropertyCtl->ScreenToClient(rect);

	// 将原编辑框隐藏，否则m_dtCtrl不能正确显示
	m_pWndInPlace->ShowWindow(SW_HIDE);

	// 调整m_dtCtrl的显示位置
	rect.top -= 3;
	rect.bottom += 5;
	rect.left -= 4;
	// 设置CDateTimeCtrl的显示类型
	DWORD dtsStyle = WS_VISIBLE | WS_CHILD | WS_BORDER;
	if (!m_bIsDate)
		dtsStyle |= DTS_TIMEFORMAT;		//时间类型
	else
		dtsStyle |= DTS_SHORTDATEFORMAT | DTS_UPDOWN;		//日期类型
	m_dtCtrl->Create(dtsStyle, rect, pPropertyCtl, 1001);
	::SetWindowPos(m_dtCtrl->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	m_dtCtrl->SetTime(oleTime);

	// 让日期控件获得焦点
	m_dtCtrl->SetFocus();
	return TRUE;
}

