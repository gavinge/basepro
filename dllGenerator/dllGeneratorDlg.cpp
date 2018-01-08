
// dllGeneratorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dllGenerator.h"
#include "dllGeneratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdllGeneratorDlg �Ի���



CdllGeneratorDlg::CdllGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdllGeneratorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdllGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CdllGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CdllGeneratorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CdllGeneratorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CdllGeneratorDlg ��Ϣ�������

BOOL CdllGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CdllGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdllGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CdllGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



#include "Path.h"
BOOL CdllGeneratorDlg::GenerateNiewWtlProj(CString strNameProjName)
{
	CString strSrcProjectDir = L"";
	strSrcProjectDir.Format(L"%s\\dll_wtlbaseproj", CProjectPath::GetInstance()->GetExePath());

	CString strDesProjectDir = L"";
	strDesProjectDir.Format(L"%s\\%s", CProjectPath::GetInstance()->GetExePath(), strNameProjName);

	if (PathFileExists(strDesProjectDir))
	{
		AfxMessageBox(L"���󣺹���\"" + strNameProjName + L"\"�Ѵ���!!!!!");
		return FALSE;
	}

	//��ֱ�ӿ����ļ���
	Copy2DesDir(strSrcProjectDir, strDesProjectDir);

	//�޸ĵ����ļ����ݼ��ļ���

	//�޸��ļ�������

	AfxMessageBox(L"�¹���\"" + strNameProjName + L"\"���ɳɹ�!~~~~");
	return TRUE;
}
BOOL CdllGeneratorDlg::GenerateNiewWtlProj2(CString strNameProjName)
{
	CString strSrcProjectDir = L"";
	strSrcProjectDir.Format(L"%s\\dll_baseproj", CProjectPath::GetInstance()->GetExePath());

	CString strDesProjectDir = L"";
	strDesProjectDir.Format(L"%s\\%s", CProjectPath::GetInstance()->GetExePath(), strNameProjName);

	if (PathFileExists(strDesProjectDir))
	{
		AfxMessageBox(L"���󣺹���\"" + strNameProjName + L"\"�Ѵ���!!!!!");
		return FALSE;
	}

	//��ֱ�ӿ����ļ���
	Copy2DesDir(strSrcProjectDir, strDesProjectDir);

	//�޸ĵ����ļ����ݼ��ļ���

	//�޸��ļ�������

	AfxMessageBox(L"�¹���\"" + strNameProjName + L"\"���ɳɹ�!~~~~");
	return TRUE;
}
BOOL CdllGeneratorDlg::Copy2DesDir(CString source, CString target)
{
	CreateDirectory(target, NULL); //����Ŀ���ļ���  
	CFileFind finder;
	CString path = L"";
	path.Format(L"%s/*.*", source);
	//AfxMessageBox(path);
	bool bWorking = finder.FindFile(path);
	while (bWorking){
		bWorking = finder.FindNextFile();
		if (finder.IsDirectory() && !finder.IsDots()){ //���ļ��� ���� ���Ʋ��� . �� ..  

			CString targetPath = finder.GetFileName();
			targetPath.Replace(L"{base}", m_strNewProjName);

			BOOL bRet = Copy2DesDir(finder.GetFilePath(), target + "/" + targetPath); //�ݹ鴴���ļ���+"/"+finder.GetFileName()  
			if (bRet == FALSE) return FALSE;
		}
		else{

			CString targetfile = finder.GetFileName();;
			BOOL bRet = FALSE;

			targetfile.Replace(L"{base}", m_strNewProjName);
			targetfile = target + L"//" + targetfile;

			CTime tm = CTime::GetCurrentTime();
			CString str;
			str.Format(_T("%u"), tm.GetTime());
			CString targettmpfile;
			targettmpfile.Format(L"%s//%u.tmp",target,tm.GetTime());
			bRet = CopyFile(finder.GetFilePath(), targettmpfile, FALSE);
			if (bRet == TRUE)
			{
				ModifyFie(targettmpfile, targetfile);
			}
		}
	}
	return TRUE;
}


#define  CODE_PAGE_GBK1232 936
int CdllGeneratorDlg::GetDefulatLanguageCodePage()
{
	static LCID lcid = GetSystemDefaultLCID();

	return (lcid == 0x804) ? CP_ACP : CODE_PAGE_GBK1232;
}

TCHAR* CdllGeneratorDlg::MultiByte2WideChar(const CHAR *apMultiByte, DWORD adwLen/* = -1*/)
{
	int codepage = GetDefulatLanguageCodePage();
	int liUnicodeLen = MultiByteToWideChar(codepage/*CP_ACP*/, 0, apMultiByte, adwLen, NULL, 0);
	TCHAR *lpszUnicode = new TCHAR[liUnicodeLen + 1];
	memset(lpszUnicode, 0, sizeof(TCHAR) * (liUnicodeLen + 1));
	MultiByteToWideChar(codepage/*CP_ACP*/, 0, apMultiByte, adwLen, lpszUnicode, liUnicodeLen);
	return lpszUnicode;
}

CHAR* CdllGeneratorDlg::UnicodeChar2MultiByte(const TCHAR *apszWideChar)
{
	int codepage = GetDefulatLanguageCodePage();
	int liMultiLen = WideCharToMultiByte(codepage/*CP_ACP*/, 0, apszWideChar, -1, 0, NULL, 0, NULL);
	CHAR *lpMultiByte = new CHAR[liMultiLen + 1];
	memset(lpMultiByte, 0, sizeof(CHAR) * (liMultiLen + 1));
	WideCharToMultiByte(codepage/*CP_ACP*/, 0, apszWideChar, -1, lpMultiByte, liMultiLen, NULL, NULL);
	return lpMultiByte;
}

const char* CdllGeneratorDlg::newGUID()
{
	static char buf[64] = { 0 };
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid))
	{
		_snprintf_s(buf, sizeof(buf)
			, "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
			, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
			, guid.Data4[6], guid.Data4[7]
			);
	}
	return (const char*)buf;
}


BOOL CdllGeneratorDlg::ModifyFie(CString strProjFile, CString strTargetProjFile)
{
	/*Name = "{name}"
	ProjectGUID = "{projectguid}"
	RootNamespace = "{prorootnamespace}"
	RelativePath=".\{rscbase}.rc"
	*/

	if (!PathFileExists(strProjFile))
	{
		return FALSE;
	}

	if (PathFileExists(strTargetProjFile))
	{
		::DeleteFile(strTargetProjFile);
	}

	HANDLE hFile = ::CreateFile(strProjFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		return FALSE;
	}

	BOOL bRetCode = FALSE;
	LPBYTE lpBuffer = NULL;
	CHAR *strResult = NULL; DWORD dwAllocLength = 0;

	DWORD dwHeightSize = 0;
	DWORD dwFileSize = ::GetFileSize(hFile, &dwHeightSize);

	dwAllocLength = dwFileSize + 1;
	strResult = new CHAR[dwAllocLength];
	ZeroMemory(strResult, dwAllocLength);

	if (!::ReadFile(hFile, strResult, dwFileSize, &dwFileSize, NULL))
	{
		return FALSE;
	}
	CloseHandle(hFile);
	hFile = NULL;

	LPCTSTR lpsz = MultiByte2WideChar(strResult, -1);
	CString strValue(lpsz);


	LPCTSTR lpsz2 = MultiByte2WideChar(newGUID(), -1);
	LPCTSTR lpsz3 = MultiByte2WideChar(newGUID(), -1);
	LPCTSTR lpsz4 = MultiByte2WideChar(newGUID(), -1);

	CString strGuidValue(lpsz2);
	CString strGuidValue2(lpsz3);
	CString strGuidValue3(lpsz4);

	/*strValue.Replace(L"{name}", m_strNewProjName);
	strValue.Replace(L"{projectguid}", strGuidValue);
	strValue.Replace(L"{prorootnamespace}", m_strNewProjName);
	strValue.Replace(L"{rscbase}", m_strNewProjName);*/
	strValue.Replace(L"{base}", m_strNewProjName);

	strValue.Replace(L"{projectguid}", strGuidValue); //base
	strValue.Replace(L"{projectguid2}", strGuidValue2);//baseSample
	strValue.Replace(L"{projectguid3}", strGuidValue3);//sln

	/*int pos = strValue.Find(L"{base}");
	while ((pos = strValue.Find(L"{base}"))>0)
	{
	strValue.Replace(L"{base}", m_strNewProjName);
	}*/

	CStringA strSaveData = UnicodeChar2MultiByte(strValue.GetBuffer());
	strValue.ReleaseBuffer();

	hFile = ::CreateFile(strTargetProjFile,
		GENERIC_ALL,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dWriteRet = 0;
		::WriteFile(hFile, (LPVOID)strSaveData.GetBuffer(), sizeof(strSaveData[0])*strSaveData.GetLength(), (LPDWORD)&dWriteRet, NULL);
		::CloseHandle(hFile);
	}
	::DeleteFile(strProjFile);
	return TRUE;
}

BOOL CdllGeneratorDlg::Modifyproj(CString strProjFile, CString strTargetProjFile)
{
	/*Name = "{name}"
	ProjectGUID = "{projectguid}"
	RootNamespace = "{prorootnamespace}"
	RelativePath=".\{rscbase}.rc"
	*/

	if (!PathFileExists(strProjFile))
	{
		return FALSE;
	}

	if (PathFileExists(strTargetProjFile))
	{
		::DeleteFile(strTargetProjFile);
	}

	HANDLE hFile = ::CreateFile(strProjFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		return FALSE;
	}

	BOOL bRetCode = FALSE;
	LPBYTE lpBuffer = NULL;
	CHAR *strResult = NULL; DWORD dwAllocLength = 0;

	DWORD dwHeightSize = 0;
	DWORD dwFileSize = ::GetFileSize(hFile, &dwHeightSize);

	dwAllocLength = dwFileSize + 1;
	strResult = new CHAR[dwAllocLength];
	ZeroMemory(strResult, dwAllocLength);

	if (!::ReadFile(hFile, strResult, dwFileSize, &dwFileSize, NULL))
	{
		return FALSE;
	}
	CloseHandle(hFile);
	hFile = NULL;

	LPCTSTR lpsz = MultiByte2WideChar(strResult, -1);
	CString strValue(lpsz);


	LPCTSTR lpsz2 = MultiByte2WideChar(newGUID(), -1);
	CString strGuidValue(lpsz2);

	strValue.Replace(L"{name}", m_strNewProjName);
	strValue.Replace(L"{projectguid}", strGuidValue);
	strValue.Replace(L"{prorootnamespace}", m_strNewProjName);
	strValue.Replace(L"{rscbase}", m_strNewProjName);


	CStringA strSaveData = UnicodeChar2MultiByte(strValue.GetBuffer());
	strValue.ReleaseBuffer();

	hFile = ::CreateFile(strTargetProjFile,
		GENERIC_ALL,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dWriteRet = 0;
		::WriteFile(hFile, (LPVOID)strSaveData.GetBuffer(), sizeof(strSaveData[0])*strSaveData.GetLength(), (LPDWORD)&dWriteRet, NULL);
		::CloseHandle(hFile);
	}
	::DeleteFile(strProjFile);
	return TRUE;
}

void CdllGeneratorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString strProjName = L"";
	GetDlgItemText(IDC_EDIT1, strProjName);
	m_strNewProjName = strProjName;
	GenerateNiewWtlProj2(strProjName);
}


void CdllGeneratorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString strProjName = L"";
	GetDlgItemText(IDC_EDIT1, strProjName);
	m_strNewProjName = strProjName;
	GenerateNiewWtlProj(strProjName);
}
