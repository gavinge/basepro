// {base}Sample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C{base}SampleApp:
// �йش����ʵ�֣������ {base}Sample.cpp
//

class C{base}SampleApp : public CWinApp
{
public:
	C{base}SampleApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C{base}SampleApp theApp;