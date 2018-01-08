
// dllGeneratorDlg.h : ͷ�ļ�
//

#pragma once


// CdllGeneratorDlg �Ի���
class CdllGeneratorDlg : public CDialogEx
{
// ����
public:
	CdllGeneratorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLLGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	//1.���������ļ������ļ�
	//2.�޸�*.project����
	//3.�������µĹ���

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
