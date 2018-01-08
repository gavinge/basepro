#include "stdafx.h"
#include "CmdLine.h"


ProjectCmdLine::ProjectCmdLine()
{

}
ProjectCmdLine::~ProjectCmdLine()
{

}

ProjectCmdLine* ProjectCmdLine::GetInstance()
{
	static ProjectCmdLine inst;
	return &inst;
}

CString ProjectCmdLine::LookUpValue(_tagEnCmdLine enCmdLine)
{
	int nIndex = mapParams.FindKey(enCmdLine);
	if (nIndex == -1)
	{
		return L"";
	}
	return mapParams.GetValueAt(nIndex);
}

BOOL ProjectCmdLine::Init(LPCWSTR lwCmdLine)
{
	wchar_t* pszContext = NULL;
	LPWSTR token = wcstok_s((LPWSTR)lwCmdLine, L"|", &pszContext);					
	while (token != NULL)
	{
		CString strToken(token),strKey(token);
		if (strToken.Find(L"=")+1 < strToken.GetLength())
		{
			strKey   = strKey.Mid(0,strKey.Find(L"="));
			strToken = strToken.Mid(strToken.Find(L"=")+1);

			for(int i=0; i<ARRAYSIZE(CmdLineKeys); ++i)
			{
				if (lstrcmpiW(CmdLineKeys[i].wstrCmdKey,strKey) == 0)
				{
					mapParams.Add(CmdLineKeys[i].enumCmdType,strToken);
					break;
				}
			}
		}
		token = wcstok_s(NULL, L"|", &pszContext);
	}
	return TRUE;
}