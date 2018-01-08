#include "stdafx.h"
#include "Path.h"


CProjectPath::~CProjectPath()
{

}
CProjectPath::CProjectPath()
{
	::GetModuleFileNameW(GetModuleHandle(NULL), wstrAppPath, MAX_PATH);
	::PathRemoveFileSpecW(wstrAppPath);
}
BOOL CProjectPath::Init()
{
	return TRUE;
}

CProjectPath* CProjectPath::GetInstance()
{
	static CProjectPath inst;
	return &inst;
}

CString CProjectPath::GetExePath()
{
	return wstrAppPath;
}