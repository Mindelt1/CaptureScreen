// CaptureScreenView.cpp : implementation of the CCaptureScreenView class
//

#include "stdafx.h"
#include "CaptureScreen.h"

#include "CaptureScreenDoc.h"
#include "CaptureScreenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCaptureScreenView

IMPLEMENT_DYNCREATE(CCaptureScreenView, CScrollView)

BEGIN_MESSAGE_MAP(CCaptureScreenView, CScrollView)
END_MESSAGE_MAP()

// CCaptureScreenView construction/destruction

CCaptureScreenView::CCaptureScreenView()
{

}

CCaptureScreenView::~CCaptureScreenView()
{
}

BOOL CCaptureScreenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CCaptureScreenView drawing

void CCaptureScreenView::OnDraw(CDC* pDC)
{
   CCaptureScreenDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   if (!pDoc)
      return;


   CScreenImage& image = pDoc->GetImage();
   if(!image.IsNull())
   {
      CBrush brush(::GetSysColor(COLOR_APPWORKSPACE));
      image.Draw(pDC->GetSafeHdc(), 0, 0);
      FillOutsideRect(pDC, &brush);
   }
   else
   {
      CRect rect;
      pDC->GetClipBox(rect);
      pDC->FillSolidRect(rect, ::GetSysColor(COLOR_APPWORKSPACE));
   }



}

void CCaptureScreenView::OnInitialUpdate()
{
	CSize size(100, 100);
	SetScrollSizes(MM_TEXT, size);
   
}


// CCaptureScreenView diagnostics

#ifdef _DEBUG
void CCaptureScreenView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCaptureScreenView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCaptureScreenDoc* CCaptureScreenView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCaptureScreenDoc)));
	return (CCaptureScreenDoc*)m_pDocument;
}
#endif //_DEBUG


// CCaptureScreenView message handlers

void CCaptureScreenView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
   CCaptureScreenDoc* pDoc = GetDocument();
   CScreenImage& image = pDoc->GetImage();

   if(!image.IsNull())
   {
      CSize size(image.GetWidth(), image.GetHeight());
      SetScrollSizes(MM_TEXT, size);
      ResizeParentToFit();
   }
}
