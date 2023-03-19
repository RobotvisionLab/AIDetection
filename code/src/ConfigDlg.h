#pragma once
#include "afxpropertygridctrl.h"
#include <vector>
#include "MvCodeReaderCtrl.h"
#include "MvCodeReaderErrorDefine.h"
#include "MvCodeReaderParams.h"
#include "MvCodeReaderPixelType.h"
#include "turbojpeg.h"
#include "GdiPlus.h"
#include <map>
#include "afxwin.h"

#if _MSC_VER >= 1900
#pragma comment(lib, "legacy_stdio_definitions.lib")
#endif

#pragma comment(lib,"gdiplus.lib")
using namespace std;
using namespace Gdiplus;

#define BYTE_ALIGN              4                 // 4字节对齐
#define RUNNING_MODE            "RunningMode"
#define TRIGGER_MODE            "TriggerMode"
#define TRIGGER_SOURCE          "TriggerSource"
#define TRIGGER_SOFTWARE        "TriggerSoftware"
#define EXPOSURE_TIME           "ExposureTime"
#define GAIN                    "Gain"
#define ACQUISITION_FRAME_RATE  "AcquisitionFrameRate"

#define Camera_Width             "WidthMax"
#define Camera_Height            "HeightMax"
#define Camera_PayloadSize       "PayloadSize"
#define ImageExLen                4096

#define IMAGE_NAME_LEN          64

typedef struct _MV_CODEREADER_TJPG_PARAM_
{
	unsigned char*  pBufInput;
	unsigned int    nBufInputLen;

	unsigned int    nWidth;
	unsigned int    nHeight;

	unsigned int    nJpgQuality;

	unsigned char*  pBufOutput;
	unsigned int    nBufOutputLen;

}MV_CODEREADER_TJPG_PARAM;

typedef struct _MV_CODEREADER_DRAW_PARAM_
{
	HDC hDC;
	unsigned char *pData;

	int nImageWidth;
	int nImageHeight;

	int nWndRectWidth;
	int nWndRectHeight;
	int nDstX;
	int nDstY;

}MV_CODEREADER_DRAW_PARAM;


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

	static bool IsStrUTF8(const char* pBuffer, int size);
	static bool Char2Wchar(const char *pStr, wchar_t *pOutWStr, int nOutStrSize);
	static bool Wchar2char(wchar_t *pOutWStr, char *pStr);

	CToolBar  m_Config_ToolBar;
	CImageList m_Input_ImageList;

	vector<CMFCPropertyGridProperty*> m_mfcprogridpro_config;

public:
	bool IsSave();

private:
	//scanner
	int     GetCurrentConfigurationInformation();                   // 获取相机运行状态信息(运行模式以及触发模式)
	void	OnBnClickedGetParameterButton();
	int     InitResources();
	void    DeInitResources();

	MV_CODEREADER_DEVICE_INFO_LIST  m_stDeviceInfoList;             // 设备信息列表
	MV_CODEREADER_DEVICE_INFO       m_stDeviceInfo;                 // 设备信息
	MV_CODEREADER_DRAW_PARAM m_stParam;                             // 自己构建的结构体
	MV_CODEREADER_TJPG_PARAM m_pstParam;                            // 解压JPG图像输出结构体
	MV_CODEREADER_IMAGE_OUT_INFO_EX2*   m_pstImageInfoEx2;          // 图像信息
	unsigned char*          m_pcDataBuf;                            // 存储图像数据
	BITMAPINFO*             m_bBitmapInfo;
	HANDLE                  m_hProcessThread;                      // 取流线程
	static void*  __stdcall WINAPI ProcessThread(void* pUser);            // 图像显示线程
	int Display(void* hWnd, unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstDisplayImage);
	int MvJpgDecompress(IN OUT MV_CODEREADER_TJPG_PARAM* pstParam);
	int Draw(MV_CODEREADER_DRAW_PARAM* pstParam);
	unsigned int InnerDrawShape(Graphics* g, float x, float y, float w, float h, float fAngle);

	void*                   m_handle;                               // 设备句柄
	bool                    m_bConnect;                             // 是否设备已连接
	bool                    m_bIsSoftTrigger;                       // 是否勾选软触发控件
	bool                    m_bStartJob;                            // 是否工作线程已开启
	int                     m_MaxImageSize;                         // 图像最大尺寸
	void*                   m_hWndDisplay;                          // 显示窗口句柄


public:
	afx_msg void OnBnClickedButtonSearchScanner();
	CListBox m_list_scanner;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedRadioCont();
	afx_msg void OnBnClickedRadioExtern();
	afx_msg void OnBnClickedButtonStartGrab();
	afx_msg void OnBnClickedButtonStopGrab();
	afx_msg void OnBnClickedButtonTrigger();
};
