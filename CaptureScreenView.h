// CaptureScreenView.h : interface of the CCaptureScreenView class
//


#pragma once


class CCaptureScreenView : public CScrollView
{
protected: // create from serialization only
	CCaptureScreenView();
	DECLARE_DYNCREATE(CCaptureScreenView)

// Attributes
public:
	CCaptureScreenDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CCaptureScreenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
   virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in CaptureScreenView.cpp
inline CCaptureScreenDoc* CCaptureScreenView::GetDocument() const
   { return reinterpret_cast<CCaptureScreenDoc*>(m_pDocument); }
#endif

