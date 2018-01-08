#pragma once

/***********************************************************************
* @file    Path.h
* @brief   全局路径管理类
* @author  Gavin geshan@hotmail.com
* @time：   2016-04-19
* @comment:   
//**********************************************************************/

//路径相关帮助类
class CProjectPath
{
public:
	~CProjectPath();
	BOOL Init();
	static CProjectPath* GetInstance();
	CString GetExePath();
protected:
	CProjectPath();
	CProjectPath(const CProjectPath& ref);
private:

	//exe当前路径
	WCHAR wstrAppPath[MAX_PATH];

	//动态添加,然后再构造中初始化即可.
};