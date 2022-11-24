#pragma once
#include "afxwin.h"


// CMyAbout 对话框

class CMyAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CMyAbout)

public:
	CMyAbout(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyAbout();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYABOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic     m_about_icon;
	HICON   m_Icon_About;
	CFont m_font;
	virtual BOOL OnInitDialog();
	CStatic m_static_about_title;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
