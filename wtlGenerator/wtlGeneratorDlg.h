
// wtlGeneratorDlg.h : header file
//

#pragma once


// CwtlGeneratorDlg dialog
class CwtlGeneratorDlg : public CDialogEx
{
// Construction
public:
	CwtlGeneratorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WTLGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:
	//1.拷贝整个文件夹中文件
	//2.修改*.project属性
	//3.重命名新的工程

	WCHAR wstrAppPath[MAX_PATH];
	CString m_strNewProjName = L"";

	//..to generate new wtl proj
	BOOL  GenerateNiewWtlProj(CString strNameProjName,CString strBaseProjName);

	//..to copy module files to des proj
	BOOL Copy2DesDir(CString source, CString target);

	//..to update {base}.bcproj
	BOOL Modifyproj(CString strProjFile,CString strTargetProjFile);


	int GetDefulatLanguageCodePage();
	TCHAR* MultiByte2WideChar(const CHAR *apMultiByte, DWORD adwLen  = -1);
	CHAR* UnicodeChar2MultiByte(const TCHAR *apszWideChar);
	const char* newGUID();
public:
	afx_msg void OnBnClickedButton1();
};
