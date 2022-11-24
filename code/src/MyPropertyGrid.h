//MyPropertyGrid.h
//����һ����CMFCPropertyGridDateTimeProperty���̳���CMFCPropertyGridProperty

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
	virtual BOOL OnClickValue(UINT uiMsg, CPoint point);	//����������б�ֵ�������򴥷��˺���
	CInnerDateTimeCtrl *m_dtCtrl;	//�Զ���CDateTimeCtrl��

protected:
	BOOL    m_bIsDate;				//TRUE: ��������; FALSE: ʱ������

};
