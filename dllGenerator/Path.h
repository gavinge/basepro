#pragma once

/***********************************************************************
* @file    Path.h
* @brief   ȫ��·��������
* @author  Gavin geshan@hotmail.com
* @time��   2016-04-19
* @comment:   
//**********************************************************************/

//·����ذ�����
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

	//exe��ǰ·��
	WCHAR wstrAppPath[MAX_PATH];

	//��̬���,Ȼ���ٹ����г�ʼ������.
};