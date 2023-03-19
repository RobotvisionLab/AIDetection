
// AIDetectionDlg.h : ͷ�ļ�
//

#pragma once
#include "afxpropertygridctrl.h"
#include "LoginDlg.h"
#include "InputDlg.h"
#include "DetectionDlg.h"
#include "MyAbout.h"
#include "ConfigDlg.h"
#include "DBOperator.h"

enum ROLE
{
	INPUTOR=1,
	DETECTIOR,
	VERIFIER,
	APPROVIOR,
	ROOT
};



// CAIDetectionDlg �Ի���
class CAIDetectionDlg : public CDialogEx
{
// ����
public:
	CAIDetectionDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CAIDetectionDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AIDETECTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	ROLE currentUser;

	CToolBar    m_ToolBar;
	CStatusBar  m_StatusBar;
	CImageList  m_ImageList;

	CLoginDlg m_loginDlg;
	CInputDlg m_inputDlg;
	CDetectionDlg m_detectionDlg;
	CMyAbout m_myaboutDlg;
	CConfigDlg m_configDlg;

	CRect m_mainRect;
	CRect m_toolbarRect;
	CRect m_statusbarRect;
	CRect m_dlgRect;
	void getRects();

	int m_curtdlgIndex;
	void changeVisible(int newIndex);


private:
	afx_msg void OnLogin();
	afx_msg void OnInput();
	afx_msg void OnDetection();
	afx_msg void OnApproval();
	afx_msg void OnConfig();
	afx_msg void OnAbout();
	afx_msg void OnExit();

public:
	CDBOperator m_dboperator;
	void loginSuccess(int role_id);

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
