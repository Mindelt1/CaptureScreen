// CaptureScreen.h : main header file for the CaptureScreen application
//
#pragma once

#include "resource.h" 


// CCaptureScreenApp:
// See CaptureScreen.cpp for the implementation of this class
//

class CCaptureScreenApp : public CWinApp
{
public:
	CCaptureScreenApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCaptureScreenApp theApp;