// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#pragma warning(disable:4995)
#pragma warning(disable:4996)

#define _CSTDIO_
#define _CSTRING_
#define _CWCHAR_ 


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <atlstr.h>
#include "I{base}.h"
using namespace std;
extern HMODULE _Module;
extern I{base} *pModule;
#include "C{base}.h"