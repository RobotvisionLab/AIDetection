#pragma once
//zzh
#include "..\thirdparty\GridReport_Utility\GridppReportEventImpl.h"
// CViewReportDlg 对话框
//add zzh
#include<iostream>
#include <string>
#include <vector>
#include "info.h"
#include "afxwin.h"
using namespace std;

enum REPORTTYPE
{
	WTD = 0,
	JCJG,
	JDZS
};

struct LZDINFO
{
	string index;
	string jlqj;
	string zqddj;
	string clfw;
	string xhgg;
	string zzc;
	string ccbh;//
	string sl;
	string fj;
	string qjlx;
	string jlqjyt;
	string fwfs;
	string fwlx;
	string jbjcf;
	string bz;//
	string qjsj;
	string qjdd;
	string lzdh;
	string lqr;
};

struct WTDINFO
{
	string title;
	string wtdh;
	string wtdwqc;
	string htbh;
	string sjdwqc;//
	string lxr;
	string sj;
	string lxdh;
	string sjdwdz;
	string sjdwlx;//
	string sjdwzzdm;
	LZDINFO lzdinfo;
	string khyq;
	string slry;
	string slrq;
};

class CViewReportDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewReportDlg)

public:
	CViewReportDlg(CWnd* pParent = NULL);   // 标准构造函数

	virtual ~CViewReportDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWREPORTDLG };
#endif

private:
	//add zzh
	IGridppReportPtr m_pGridppReportNew;
	CGridppReportEventImpl *m_pReportEvents;
	IGRPrintViewerPtr m_pPrintViewer;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	friend class CReportEvent;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	static REPORTTYPE m_currentType;
	static OrderbaseInfo m_orderbaseinfo;
	static DetectionInfo m_detinfo;
	static DetailResult m_detailinfo;

	//static OrderBase m_wtdinfo;
	//static Detrst m_detinfo;
	//static Sampleinfo m_sampleinfo;
	//static vector<Circulation> m_lzdinfo;
	//static Circulation m_cirinfo;
	static string m_template_FileName;
	static string m_save_FileName;
	DECLARE_EVENTSINK_MAP()
	void ClickGrprintviewer();
	CButton m_export_button;
};

