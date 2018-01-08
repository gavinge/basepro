
// dllGeneratorDlg.h : 头文件
//

#pragma once


// CdllGeneratorDlg 对话框
class CdllGeneratorDlg : public CDialogEx
{
// 构造
public:
	CdllGeneratorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DLLGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	//1.拷贝整个文件夹中文件
	//2.修改*.project属性
	//3.重命名新的工程

	WCHAR wstrAppPath[MAX_PATH];
	CString m_strNewProjName = L"";

	//..to generate new wtl proj
	BOOL  GenerateNiewWtlProj(CString strNameProjName);
	BOOL  GenerateNiewWtlProj2(CString strNameProjName);

	//..to copy module files to des proj
	BOOL Copy2DesDir(CString source, CString target);

	//..to update {base}.bcproj
	BOOL Modifyproj(CString strProjFile, CString strTargetProjFile);
	BOOL ModifyFie(CString strProjFile, CString strTargetProjFile);

	int GetDefulatLanguageCodePage();
	TCHAR* MultiByte2WideChar(const CHAR *apMultiByte, DWORD adwLen = -1);
	CHAR* UnicodeChar2MultiByte(const TCHAR *apszWideChar);
	const char* newGUID();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};
