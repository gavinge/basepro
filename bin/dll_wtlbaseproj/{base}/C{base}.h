#pragma once
#include "stdafx.h"
#include "I{base}.h"

class C{base}Imp :
	public I{base}
{
public:
	C{base}Imp();
	~C{base}Imp();

public:	
	STDMETHOD_(void,  Release)();

	STDMETHOD_(int,   QueryVerSion)(DWORD & dwMaxVersion, DWORD & dwMinVersion);

	STDMETHOD_(int, InitCallBack)(const {base}_CALLBACKFUNC_PTR_SET & callback_ptr_set);

	STDMETHOD_(HRESULT,InVokeN)(const LPCWSTR lpszName, VARIANT* pvarParams, int nParams, VARIANT* pvarRet = NULL);
};


