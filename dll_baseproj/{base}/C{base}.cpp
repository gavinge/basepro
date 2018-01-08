#include "stdafx.h"
#include <time.h>
#include "C{base}.h"


C{base}Imp::C{base}Imp()
{
}
C{base}Imp::~C{base}Imp()
{
}

int C{base}Imp::QueryVerSion(DWORD & dwMaxVersion, DWORD & dwMinVersion)
{
	dwMaxVersion = MAX_{base}_VERSION;
	dwMinVersion = MIN_{base}_VERSION;
	return 0;
}

int C{base}Imp::InitCallBack(const {base}_CALLBACKFUNC_PTR_SET & callback_ptr_set)
{
	return 0;
}

void C{base}Imp::Release()
{
	delete this;
	pModule = NULL;
}

HRESULT C{base}Imp::InVokeN(const LPCWSTR lpszName, VARIANT* pvarParams, int nParams, VARIANT* pvarRet)
{
	return FALSE;
}

