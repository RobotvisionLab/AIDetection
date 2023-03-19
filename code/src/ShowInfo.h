#pragma once
#include "afxcmn.h"

// ShowInfo dialog

class ShowInfo : public CDialog
{
	DECLARE_DYNAMIC(ShowInfo)

public:
	ShowInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~ShowInfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list_info;
	void setMode(int mode);
	void AdjustColumnWidth();

private:
	int m_mode;

public:
	afx_msg void OnBnClickedView();
	afx_msg void OnBnClickedOk();
};
