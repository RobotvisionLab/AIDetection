#pragma once


// CInnerDateTimeCtrl

class CInnerDateTimeCtrl : public CDateTimeCtrl
{
	DECLARE_DYNAMIC(CInnerDateTimeCtrl)

public:
	CInnerDateTimeCtrl(CMFCPropertyGridProperty *editWnd, BOOL isDate = FALSE);
	virtual ~CInnerDateTimeCtrl();

private:
	CMFCPropertyGridProperty *m_editWnd;
	BOOL m_isDate;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnNcDestroy();
};


