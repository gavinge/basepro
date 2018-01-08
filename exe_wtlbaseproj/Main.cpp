#include "stdafx.h"
#include "Main.h"


/***********************************************************************
* @file    Main.cpp
* @brief   公共的WTL工程生成基工程
* @author  Gavin geshan@hotmail.com
* @time：   2016-04-19
* @comment:   
//**********************************************************************/

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpstrCmdLine, int nCmdShow)
{
	//Initial (Global Variables etc.)
	ProjectRunUtility::ProjectInitial(hInstance);

	//Parse CmdLine.
	if (!ProjectRunUtility::ParseCmdLine(lpstrCmdLine))
	{
		return FALSE;
	}	

	//Need to Run?
	if (!ProjectRunUtility::InitialAppRun(lpstrCmdLine))
	{
		return FALSE;
	}	

	//Prepare for Run.
	if (!ProjectRunUtility::BeginRun(hInstance))
	{
		return FALSE;
	}

	//Run.
	ProjectRunUtility::Run(lpstrCmdLine,nCmdShow);

	//Term Run.
	ProjectRunUtility::TermRun();
	return 0;
}