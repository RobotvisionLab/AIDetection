
// AIDetection.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAIDetectionApp: 
// �йش����ʵ�֣������ AIDetection.cpp
//

class CAIDetectionApp : public CWinApp
{
public:
	CAIDetectionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuSearchLzd();
	afx_msg void OnMenuSearchWtgs();
	afx_msg void OnMenuSearchSjdw();
	virtual int ExitInstance();
};

extern CAIDetectionApp theApp;