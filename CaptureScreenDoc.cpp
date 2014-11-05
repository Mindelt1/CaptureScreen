// CaptureScreenDoc.cpp : implementation of the CCaptureScreenDoc class
//

#include "stdafx.h"
#include "CaptureScreen.h"

#include "CaptureScreenDoc.h"
#include "ScreenSelectionDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCaptureScreenDoc

IMPLEMENT_DYNCREATE(CCaptureScreenDoc, CDocument)

BEGIN_MESSAGE_MAP(CCaptureScreenDoc, CDocument)
   ON_COMMAND(ID_CAPTURE_SCREEN, &CCaptureScreenDoc::OnCaptureScreen)
   ON_COMMAND(ID_CAPTURE_FOREGROUNDWINDOW, &CCaptureScreenDoc::OnCaptureForegroundwindow)
   ON_COMMAND(ID_CAPTURE_RECTANGLE, &CCaptureScreenDoc::OnCaptureRectangle)
END_MESSAGE_MAP()

// CCaptureScreenDoc construction/destruction

CCaptureScreenDoc::CCaptureScreenDoc()
{
	// TODO: add one-time construction code here

}

CCaptureScreenDoc::~CCaptureScreenDoc()
{
}


BOOL CCaptureScreenDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}


// CCaptureScreenDoc serialization
void CCaptureScreenDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{

	}
	else
	{
		// TODO: add loading code here
	}
}


// CCaptureScreenDoc diagnostics

#ifdef _DEBUG
void CCaptureScreenDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCaptureScreenDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCaptureScreenDoc commands

void CCaptureScreenDoc::OnCaptureScreen()
{
    CWnd* pWnd = AfxGetMainWnd();
    pWnd->ShowWindow(SW_HIDE);
    ::Sleep(333);

    m_image.CaptureScreen();

    pWnd->ShowWindow(SW_SHOW);
    UpdateAllViews(NULL);
}

void CCaptureScreenDoc::OnCaptureForegroundwindow()
{
    CWnd* pWnd = AfxGetMainWnd();
    pWnd->ShowWindow(SW_HIDE);
    ::Sleep(111);

    HWND hWnd = ::GetForegroundWindow();
    m_image.CaptureWindow(hWnd);

    pWnd->ShowWindow(SW_SHOW);
    UpdateAllViews(NULL);
}

void CCaptureScreenDoc::OnCaptureRectangle()
{
   CRect rect;
   CScreenSelectionDialog dlg(rect);
   dlg.DoModal();
   
   m_image.CaptureRect(rect);

   AfxGetMainWnd()->ShowWindow(SW_SHOW);
   UpdateAllViews(NULL);

}
