
// wtlGeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wtlGenerator.h"
#include "wtlGeneratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CwtlGeneratorDlg dialog



CwtlGeneratorDlg::CwtlGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CwtlGeneratorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwtlGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CwtlGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CwtlGeneratorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CwtlGeneratorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CwtlGeneratorDlg message handlers

BOOL CwtlGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CwtlGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CwtlGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CwtlGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//动态生成新的WTL EXE工程
#include "Path.h"
void CwtlGeneratorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString strProjName = L"";
	GetDlgItemText(IDC_EDIT1_PROJ_NAME, strProjName);
	m_strNewProjName = strProjName;
	GenerateNiewWtlProj(strProjName, L"exe_wtlbaseproj");
}


BOOL CwtlGeneratorDlg::GenerateNiewWtlProj(CString strNameProjName, CString strBaseProjName)
{
	CString strSrcProjectDir = L"";
	strSrcProjectDir.Format(L"%s\\%s", CProjectPath::GetInstance()->GetExePath(), strBaseProjName);

	CString strDesProjectDir = L"";
	strDesProjectDir.Format(L"%s\\%s", CProjectPath::GetInstance()->GetExePath(), strNameProjName);

	if (PathFileExists(strDesProjectDir))
	{
		AfxMessageBox(L"错误：工程\"" + strNameProjName + L"\"已存在!!!!!");
		return FALSE;
	}

	Copy2DesDir(strSrcProjectDir, strDesProjectDir);
	AfxMessageBox(L"新工程\"" + strNameProjName + L"\"生成成功!~~~~");
	return TRUE;
}

BOOL CwtlGeneratorDlg::Copy2DesDir(CString source, CString target)
{
	CreateDirectory(target, NULL); //创建目标文件夹  
	CFileFind finder;
	CString path = L"";
	path.Format(L"%s/*.*", source);
	//AfxMessageBox(path);
	bool bWorking = finder.FindFile(path);
	while (bWorking){
		bWorking = finder.FindNextFile();
		//AfxMessageBox(finder.GetFileName());
		if (finder.IsDirectory() && !finder.IsDots()){ //是文件夹 而且 名称不含 . 或 ..  
			BOOL bRet = Copy2DesDir(finder.GetFilePath(), target + "/" + finder.GetFileName()); //递归创建文件夹+"/"+finder.GetFileName()  
			if (bRet == FALSE) return FALSE;
		}
		else{ 

			CString targetfile = L"";
			BOOL bRet = FALSE;

			if (finder.GetFileName().Compare(L"{base}.rc") == 0)
			{
				targetfile = target + L"//" + m_strNewProjName + L".rc";
				bRet = CopyFile(finder.GetFilePath(), targetfile, FALSE);
			}
			else if (finder.GetFileName().Compare(L"{base}.vcproj") == 0)
			{
				CString targettmpfile = target + L"//" + m_strNewProjName + L".vcproj_tmp";
				targetfile = target + L"//" + m_strNewProjName + L".vcproj";
				bRet = CopyFile(finder.GetFilePath(), targettmpfile, FALSE);
				if (bRet == TRUE)
				{
					//modify proj des file.
					Modifyproj(targettmpfile, targetfile);
				}
			}
			else
			{
				targetfile = target + L"//" + finder.GetFileName();
				bRet = CopyFile(finder.GetFilePath(), targetfile, FALSE);
			}
		}
	}
	return TRUE;
}


#define  CODE_PAGE_GBK1232 936
int CwtlGeneratorDlg::GetDefulatLanguageCodePage()
{
	static LCID lcid = GetSystemDefaultLCID();

	return (lcid == 0x804) ? CP_ACP : CODE_PAGE_GBK1232;
}

TCHAR* CwtlGeneratorDlg::MultiByte2WideChar(const CHAR *apMultiByte, DWORD adwLen/* = -1*/)
{
	int codepage = GetDefulatLanguageCodePage();
	int liUnicodeLen = MultiByteToWideChar(codepage/*CP_ACP*/, 0, apMultiByte, adwLen, NULL, 0);
	TCHAR *lpszUnicode = new TCHAR[liUnicodeLen + 1];
	memset(lpszUnicode, 0, sizeof(TCHAR) * (liUnicodeLen + 1));
	MultiByteToWideChar(codepage/*CP_ACP*/, 0, apMultiByte, adwLen, lpszUnicode, liUnicodeLen);
	return lpszUnicode;
}

CHAR* CwtlGeneratorDlg::UnicodeChar2MultiByte(const TCHAR *apszWideChar)
{
	int codepage = GetDefulatLanguageCodePage();
	int liMultiLen = WideCharToMultiByte(codepage/*CP_ACP*/, 0, apszWideChar, -1, 0, NULL, 0, NULL);
	CHAR *lpMultiByte = new CHAR[liMultiLen + 1];
	memset(lpMultiByte, 0, sizeof(CHAR) * (liMultiLen + 1));
	WideCharToMultiByte(codepage/*CP_ACP*/, 0, apszWideChar, -1, lpMultiByte, liMultiLen, NULL, NULL);
	return lpMultiByte;
}

const char* CwtlGeneratorDlg::newGUID()
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


BOOL CwtlGeneratorDlg::Modifyproj(CString strProjFile, CString strTargetProjFile)
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

	LPCTSTR lpsz = MultiByte2WideChar(strResult,-1);
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



//动态生成新的WTL DLL工程
void CwtlGeneratorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString strProjName = L"";
	GetDlgItemText(IDC_EDIT1_PROJ_NAME, strProjName);
	m_strNewProjName = strProjName;
	GenerateNiewWtlProj(strProjName,L"exe_wtlduibaseproj");
}
