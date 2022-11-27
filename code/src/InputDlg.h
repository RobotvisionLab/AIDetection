#pragma once
#include "afxcmn.h"
#include "afxvslistbox.h"
#include "afxpropertygridctrl.h"
#include "afxwin.h"
#include <iostream>
#include <string>
#include <vector>
#include "ViewReportDlg.h"
#include "WebBrowser2.h"

 struct TreeNodeData {
	std::string wtdbh;
	std::string lzdh;
	int ypbh_id;
};

 enum BUTTONSTATE {
	 NEW_WTD = 0,
	 MODIFY_WTD,
	 DEL_WTD,
	 NEW_LZD,
	 MODIFY_LZD,
	 DEL_LZD,
	 NEW_YP,
	 MODIFY_YP,
	 DEL_YP,
	 VIEW
 };

// CInputDlg 对话框

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

private:
	CToolBar  m_Input_ToolBar;
	CImageList m_Input_ImageList;
	TreeNodeData m_currentInfo;
	BUTTONSTATE m_current_button_state;
	HTREEITEM m_current_tree_item;

	void initWTLZ(vector<OrderBase> odb);
	void initYP(bool isupdate=false);

	void initYP_P();
	void initLZD_P();
	void initWTD_P();
	void canNotMod_P(int index);

	void expandTree(HTREEITEM hTreeItem);
	void current_WTD_JDZS_paths(CString& wtdPath, CString& jdzsPath);
	void viewPDF(CString pdfDir);

	void showYP_info(int id);
	void showLZD_info();
	void showWTD_info();

	int saveModifyornot();
	void resetValue();

	void newLZD();

	void OnMenuSearch(int mode = 0);

public:
	virtual BOOL OnInitDialog();
	CTreeCtrl m_tree_wtd;
	CMFCPropertyGridCtrl m_proper_yp;
	CMFCPropertyGridCtrl m_proper_lzd;
	CMFCPropertyGridCtrl m_proper_wtd;

	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_yp;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_lzd;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_wtd;

	CStatic m_static_fgx;
	CStatic m_static_ypxi;
	CStatic m_static_lzxx;
	CStatic m_static_wtxx;
	CStatic m_static_yp;
	CStatic m_static_wtlz;
	CEdit m_edit_search;
	CSplitButton m_splitbotton_search;
	afx_msg void OnMenuSearchWtd();
	afx_msg void OnMenuSearchLzd();
	afx_msg void OnMenuSearchWtgs();
	afx_msg void OnMenuSearchSjdw();
	afx_msg void OnDblclkTreeWtd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickTreeWtd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSelchangedTreeWtd(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listctrl_yp;
	afx_msg void OnNMClickListYp(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNewWTD();
	afx_msg void OnModWTD();
	afx_msg void OnDelWTD();
	afx_msg void OnNewLZD();
	afx_msg void OnModLZD();
	afx_msg void OnDelLZD();
	afx_msg void OnNewSample();
	afx_msg void OnModSample();
	afx_msg void OnDelSample();
	afx_msg void OnLastSample();
	afx_msg void OnNextSample();
	afx_msg void OnSaveSampleInfo();
	afx_msg void OnExportWTD();
	afx_msg void OnViewDetResult();
	afx_msg void OnViewWTD();
	afx_msg void OnViewJDZS();

	afx_msg void OnBnClickedSplitSearch();
};
