#pragma once

/***********************************************************************
* @file    Main.h
* @brief   管理工程启动的一个统一管理的组件.
* @author  Gavin geshan@hotmail.com
* @time：   2016-04-19
* @comment:   
//**********************************************************************/

#include "Path.h"
#include "CmdLine.h"

CAppModule _Module;
namespace ProjectRunUtility
{
	//Initial Project TRUE:ok  FALSE:stop run
	BOOL ProjectInitial(HINSTANCE hInstance);

	//mutex judge. TRUE:ok  FALSE:stop run
	BOOL InstanceIsExist(LPCTSTR lpInstanceName, HANDLE & hMutex);

	//initial and judge if the app need run. TRUE:ok  FALSE:stop run
	BOOL InitialAppRun(LPTSTR lpsrCmdLine);

	//Parse CmdLineString which passed in Module.  TRUE:ok  FALSE:stop run.
	BOOL ParseCmdLine(LPTSTR lpsrCmdLind);

	//begin run. TRUE:ok  FALSE:stop run
	BOOL BeginRun(HINSTANCE hInstance);

	//run(maindlg).
	int Run(LPTSTR lpstrCmdLine, int nCmdShow = SW_SHOWDEFAULT);

	//Term run.
	BOOL TermRun();	

	//run as administrator judge  TRUE:ok  FALSE:stop run
	BOOL JudgeAsAdministratorAndRun(LPTSTR lpsrCmdLine);
};


#include "Path.h"
BOOL ProjectRunUtility::ProjectInitial(HINSTANCE hInstance)
{
	CString str = CProjectPath::GetInstance()->GetExePath();
	return TRUE;
}

BOOL ProjectRunUtility::JudgeAsAdministratorAndRun(LPTSTR lpsrCmdLind)
{
	return TRUE;
}

BOOL ProjectRunUtility::InstanceIsExist(LPCTSTR lpInstanceName, HANDLE & hMutex)
{		
	return TRUE;
}

BOOL ProjectRunUtility::InitialAppRun(LPTSTR lpsrCmdLine)
{
	//Judge if Need Administrator & Run.
	if (!ProjectRunUtility::JudgeAsAdministratorAndRun(lpsrCmdLine))
	{
		//Run As Administrator.
		return FALSE;
	}
	return TRUE;
}


BOOL ProjectRunUtility::ParseCmdLine(LPTSTR lpsrCmdLine)
{
	ProjectCmdLine::GetInstance()->Init(lpsrCmdLine);

	CString strParam1 = ProjectCmdLine::GetInstance()->LookUpValue(enCmdLineAppKey);
	CString strParam2 = ProjectCmdLine::GetInstance()->LookUpValue(enCmdLineHostWnd);
	
	return TRUE;
}	


BOOL ProjectRunUtility::BeginRun(HINSTANCE hInstance)
{
	HRESULT hRes = ::CoInitialize(NULL);
	ATLASSERT(SUCCEEDED(hRes));
	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);
	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);	// add flags to support other controls
	hRes = _Module.Init(NULL, hInstance);
	if (FAILED(hRes))
	{
		return FALSE;
	}
	return TRUE;
}


BOOL ProjectRunUtility::TermRun()
{
	//后续处理.
	_Module.Term();
	::CoUninitialize();
	return TRUE;
}


#include "MainWnd.h"
int ProjectRunUtility::Run(LPTSTR lpstrCmdLine, int nCmdShow)
{			
	//GdiHelp::GdiPlusInitial();//初始化GdiPlus

	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);
	CMainDlg dlgMain;

	if(dlgMain.Create(NULL) == NULL)
	{
		ATLTRACE(_T("Main dialog creation failed!\n"));
		return 0;
	}	
	dlgMain.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();

	////GdiHelp::GdiPlusRelease();//释放GdiPlus
	return nRet;
}