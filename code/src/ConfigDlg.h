#pragma once
#include "afxpropertygridctrl.h"
#include <vector>
using namespace std;

// CConfigDlg 对话框
struct MOUDLE_STATE 
{
	bool vision;
	bool plc;
	bool scan_first;
	bool scan_second;
};

class CConfigDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONFIGDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCPropertyGridCtrl m_proper_config;
	virtual BOOL OnInitDialog();
	CMFCPropertyGridCtrl m_proper_report;
	CMFCPropertyGridCtrl m_proper_comm;
	afx_msg void OnSaveConfig();
public:
	CString m_orderbase_dir;
	CString m_detection_dir;
	CString m_detresult_dir;

	CString m_ordertemplate;
	CString m_detectiontemplate;
	CString m_detresulttemplate;

	MOUDLE_STATE m_module_state;

	CToolBar  m_Config_ToolBar;
	CImageList m_Input_ImageList;

	vector<CMFCPropertyGridProperty*> m_mfcprogridpro_config;

public:
	bool IsSave();
};
