// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#pragma warning(disable:4995)
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#include <atlbase.h>
#include <atlstr.h>
#include <atlapp.h>
extern CAppModule _Module;
#include <atlcom.h>
#include <atlhost.h>
#include <atlwin.h>
#define _WTL_NO_CSTRING
#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlx.h>
#include <atlmisc.h>
#include <atlcrack.h>
#include <time.h>

#include <vector>
#include <map>
using namespace std;

#include <strsafe.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "version.lib")
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

#pragma warning(disable : 4996)

//������Դ�ļ�
#include "resource.h"
