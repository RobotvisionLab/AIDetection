#pragma once
#include "afxcmn.h"
#include "afxpropertygridctrl.h"
#include "afxvslistbox.h"
#include "afxwin.h"

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
	CMFCPropertyGridCtrl m_proper_jdjg;
	CListCtrl m_list_jdjg;
	CStatic m_static_d_ypxx;
	CMFCPropertyGridCtrl m_list_d_ypxx;
	CStatic m_static_d_jcsj;
	CStatic m_static_cam;
	CStatic m_static_sshm;
	CStatic m_static_jcjg;
	CStatic m_static_jdjg;

	void setRole(ROLE role);
	void initYP();

private:
	ROLE m_role;
	CToolBar  m_Detection_ToolBar;
	CImageList m_Detection_ImageList;
	TreeNodeData m_currntinfo;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_yp;
	std::vector<CMFCPropertyGridProperty*> m_mfcprogridpro_jcjg;

	void expandTree(HTREEITEM hTreeItem);
	void insertTreeItem(HTREEITEM item, map<int, string> info);
	void initYP_P();

public:
	TreeNodeData m_currentInfo;
	void switchMode(bool isDetection);

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CStatic m_static_hysp;
	CMFCPropertyGridCtrl m_proper_hysp;
	CTreeCtrl m_list_d_yp;


	afx_msg void OnNMClickTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeDetYp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSubmit();
};
