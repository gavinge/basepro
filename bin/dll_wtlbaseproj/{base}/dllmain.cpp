// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
HMODULE _Module;
I{base} * pModule = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{		
	case DLL_PROCESS_ATTACH:
		{
			_Module = hModule;
			DisableThreadLibraryCalls(hModule);
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		{
		}
		break;
	}
	return TRUE;
}


BOOL API_CALLTYPE CreateInstance(I{base}** pp)
{
	{
		if (!pModule)
		{
			pModule = new C{base}Imp();
		}
		*pp = pModule;
		return pModule != NULL;
	}
}
