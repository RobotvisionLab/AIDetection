//MyPropertyGrid.h
//创建一个类CMFCPropertyGridDateTimeProperty，继承自CMFCPropertyGridProperty

#include "InnerDateTimeCtrl.h"

class CMFCPropertyGridDateTimeProperty : public CMFCPropertyGridProperty
{
	DECLARE_DYNAMIC(CMFCPropertyGridDateTimeProperty)

	// Construction
public:
	CMFCPropertyGridDateTimeProperty(const CString& strName, const CString& dtDateTime, LPCTSTR lpszDescr = _T(""), BOOL isDate = TRUE);
	virtual ~CMFCPropertyGridDateTimeProperty();

	// Overrides
public:
	virtual BOOL OnClickValue(UINT uiMsg, CPoint point);	//鼠标点击属性列表“值”的区域触发此函数
	CInnerDateTimeCtrl *m_dtCtrl;	//自定义CDateTimeCtrl类

protected:
	BOOL    m_bIsDate;				//TRUE: 日期类型; FALSE: 时间类型

};
