// InnerDateTimeCtrl.cpp : 实现文件
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



// CInnerDateTimeCtrl 消息处理程序




void CInnerDateTimeCtrl::OnKillFocus(CWnd* pNewWnd)
{
	CDateTimeCtrl::OnKillFocus(pNewWnd);

	// TODO: 在此处添加消息处理程序代码
	COleDateTime oleTime;
	GetTime(oleTime);

	CString str = _T("");
	if (m_isDate)
		str = oleTime.Format(_T("%Y-%m-%d"));
	else
		str = oleTime.Format(_T("%H:%M:%S"));

	// 修改属性列表的值
	m_editWnd->SetValue(str);

	// 自我销毁
	DestroyWindow();
}


void CInnerDateTimeCtrl::OnNcDestroy()
{
	CDateTimeCtrl::OnNcDestroy();

	// TODO: 在此处添加消息处理程序代码
	// 释放内存
	delete this;
}
