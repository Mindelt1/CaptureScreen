// CaptureScreenDoc.h : interface of the CCaptureScreenDoc class
//


#pragma once
#include "ScreenImage.h"
//#include "ScreenWnd.h"

class CCaptureScreenDoc : public CDocument
{
protected: // create from serialization only
	CCaptureScreenDoc();
	DECLARE_DYNCREATE(CCaptureScreenDoc)

// Attributes
protected:
   CScreenImage m_image;

// Operations
public:
   CScreenImage& GetImage() {return m_image;};

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CCaptureScreenDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnCaptureScreen();
   afx_msg void OnCaptureForegroundwindow();
   afx_msg void OnCaptureRectangle();
};


