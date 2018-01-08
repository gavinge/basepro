#pragma once

/***********************************************************************
* @file    CmdLine.h
* @brief   ��������ع�����
* @author  Gavin geshan@hotmail.com
* @time��   2016-05-03
* @comment: ʹ�÷��� 
            ��������ɲ����磺 AK=x|HW=2345
			ProjectCmdLine::GetInstance()->Init(lpsrCmdLine);
			if (ProjectCmdLine::GetInstance()->LookUpValue(enCmdLineAppKey))
			{
			}
//**********************************************************************/

//��������ذ�����
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
	{enCmdLineAppKey,L"AK"},   //����AppKey eg��AK=x
	{enCmdLineHostWnd,L"HW"},  //����HostWnd eg��HW=2343
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