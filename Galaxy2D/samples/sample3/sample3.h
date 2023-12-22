// sample3.h : sample3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h” 
#endif

#include "resource.h"       // 主符号


// Csample3App:
// 有关此类的实现，请参阅 sample3.cpp
//

class Csample3App : public CWinApp
{
public:
	Csample3App();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Csample3App theApp;
