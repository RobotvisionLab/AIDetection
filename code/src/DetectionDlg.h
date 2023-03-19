#pragma once
#include "afxcmn.h"
#include "afxpropertygridctrl.h"
#include "afxvslistbox.h"
#include "afxwin.h"
#include "ShowInfo.h"
#include <string>
#include <map>
using namespace std;

enum ROLE;
struct TreeNodeData;

// CDetectionDlg 对话框
class CDetectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectionDlg)

public:
	CDetectionDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetectionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DETECTIONDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_jcjg;
	virtual BOOL OnInitDialog();
	CListCtrl m_list_jdjg;
	CStatic m_static_d_ypxx;
	CMFCPropertyGridCtrl m_proper_jdjg;
	CMFCPropertyGridCtrl m_list_d_ypxx;
	CMFCPropertyGridCtrl m_proper_hysp;

	CStatic m_static_d_jcsj;
	CStatic m_static_cam;
	CStatic m_static_sshm;
	CStatic m_static_jcjg;
	CStatic m_static_jdjg;

	void setRole(ROLE role);
	void initYP();
	void expandAllTreeItems();

private:
	ROLE m_role;
	CToolBar  m_Detection_ToolBar;
	CImageList m_Detection_ImageList;
	TreeNodeData m_currntinfo;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_yp;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_jcjg;

	void expandTree(HTREEITEM hTreeItem, int expand = TVE_EXPAND);
	void insertTreeItem(HTREEITEM item, map<int, string> info);
	void initYP_P();

	vector<HTREEITEM> m_list_hitems;

public:
	TreeNodeData m_currentInfo;
	void switchMode(bool isDetection);

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CStatic m_static_hysp;
	CTreeCtrl m_list_d_yp;

	void showInfo(int mode, CString info);

	afx_msg void OnNMClickTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNoDetected();
	afx_msg void OnNoInSpected();
	afx_msg void OnNoVerified();
	afx_msg void OnNoApproved();
	afx_msg void OnCAM();
	afx_msg void OnDetBasis();
	afx_msg void OnMeasureSTD();
	afx_msg void OnMeasureIST();
	afx_msg void OnMeasureBasis();
	afx_msg void OnLast();
	afx_msg void OnNext();
	afx_msg void OnDetRst();
	afx_msg void OnInspectRst();
	afx_msg void OnSave();
	afx_msg void OnSubmit();

};
