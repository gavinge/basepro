#pragma once

/***********************************************************************
* @file    CmdLine.h
* @brief   命令行相关管理类
* @author  Gavin geshan@hotmail.com
* @time：   2016-05-03
* @comment: 使用方法 
            命令行组成参数如： AK=x|HW=2345
			ProjectCmdLine::GetInstance()->Init(lpsrCmdLine);
			if (ProjectCmdLine::GetInstance()->LookUpValue(enCmdLineAppKey))
			{
			}
//**********************************************************************/

//命令行相关帮助类
typedef enum _tagEnCmdLine
{
	enCmdLineAppKey = 0,  
	enCmdLineHostWnd,     
};

struct _tagCmdLineKey
{
	_tagEnCmdLine enumCmdType;
	LPCWSTR       wstrCmdKey;
};

static _tagCmdLineKey CmdLineKeys[] =
{
	{enCmdLineAppKey,L"AK"},   //参数AppKey eg：AK=x
	{enCmdLineHostWnd,L"HW"},  //参数HostWnd eg：HW=2343
};

class ProjectCmdLine
{
public:
	~ProjectCmdLine();		
public:		
	BOOL Init(LPCWSTR lwCmdLine);
	static ProjectCmdLine* GetInstance();
	CString LookUpValue(_tagEnCmdLine enCmdLine);
protected:		
	ProjectCmdLine();			
	ProjectCmdLine(const ProjectCmdLine& ref);		
	CSimpleArray<CString> params;
	CSimpleMap<_tagEnCmdLine,CString> mapParams;   
};