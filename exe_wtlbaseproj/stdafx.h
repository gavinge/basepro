// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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

//包含资源文件
#include "resource.h"
