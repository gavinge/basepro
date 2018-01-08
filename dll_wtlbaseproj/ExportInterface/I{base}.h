/***********************************************************************
* @file    *.h
* @brief   ����ȥ���������õ�׼�ӿڶ���
* @author  Gavin geshan@
*/

#ifndef C{base}_INTERFACE_H
#define C{base}_INTERFACE_H
#ifdef _WIN32
#pragma once
#endif


#ifdef API_EXPORTS
#define EXTERN_API extern "C" __declspec(dllexport)
#else
#define EXTERN_API extern "C" __declspec(dllimport)
#endif

#define API_CALLTYPE	  __stdcall
#define NO_VTABLE __declspec(novtable)



/**************************************************************************************************/
/*****************************����ΪһЩ�ص��ϵ�Լ��***************************************/
#ifndef MIN
#define MIN(x,y) (x)<(y)?(x) : (y) 
#endif


//��ͨ���캯��(�ṹ��,�඼������)
#ifndef DECLARE_DEFAULT_CONSTRUCTOR
#define DECLARE_DEFAULT_CONSTRUCTOR(ClassName)\
	ClassName()\
{\
	RtlZeroMemory(this,sizeof(ClassName));\
	this->dwSize = sizeof(ClassName);\
}
#endif


//�������캯��(�ṹ��,�඼������)
#ifndef DECLARE_COPY_CONSTRUCTOR
#define DECLARE_COPY_CONSTRUCTOR(ClassName)\
	ClassName(const ClassName & ref)\
{\
	DWORD dwSize    = sizeof(ClassName);\
	DWORD dwSizeOld = this->dwSize;\
	DWORD nMinSize  = MIN(dwSizeOld,ref.dwSize);\
	RtlZeroMemory(this,dwSize);\
	RtlCopyMemory(this,&ref,nMinSize);\
	this->dwSize    = dwSizeOld;\
}
#endif

#ifndef DECLARE_OPERATOR_EQUAL
#define DECLARE_OPERATOR_EQUAL(ClassName)\
	ClassName & operator = (const ClassName &ref)\
{\
	if (this == &ref){return *this;}\
	DWORD dwSize    = sizeof(ClassName);\
	DWORD dwSizeOld = this->dwSize;\
	DWORD nMinSize  = MIN(dwSizeOld,ref.dwSize);\
	RtlZeroMemory(this,dwSize);\
	RtlCopyMemory(this,&ref,nMinSize);\
	this->dwSize    = dwSizeOld;\
	return *this;\
}
#endif

#ifndef DEF_NO_VTABLE
#define DEF_NO_VTABLE __declspec(novtable)
#endif

//typedef int (__stdcall *LPFunCallBackDemo)(int uID,HWND& hParentWnd,const DWORD dwContext);

//�ص�����ָ�뼯��
typedef struct {base}_CALLBACKFUNC_PTR_SET
{
	DECLARE_DEFAULT_CONSTRUCTOR({base}_CALLBACKFUNC_PTR_SET);
	DECLARE_COPY_CONSTRUCTOR({base}_CALLBACKFUNC_PTR_SET);
	DECLARE_OPERATOR_EQUAL({base}_CALLBACKFUNC_PTR_SET);

	DWORD dwSize;                           //CALLBACKFUNC �ṹ��С
	///!!���ﺯ��ָ���������밴��˳������(���˾�վλ����Ҫ��˳�����ɾ��)�������������ϰ汾������ַ���ҵ����⡣
	//LPFunCallBackDemo lpFunCallBackDemo;
}{base}_CALLBACKFUNC_PTR_SET, *LP{base}_CALLBACKFUNC_PTR_SET;


/**************************************************************************************************/
/*****************************����ΪһЩҵ�����õ���Լ��***************************************/

///�ӿ��ڲ��汾�ſ���(ÿ�η���ʽ��dll��ȥ��ֵ��Ӧ�ñ仯)
#define  MAX_{base}_VERSION  1       //�ӿڰ汾(��)
#define  MIN_{base}_VERSION  0       //�ӿڰ汾(��)



///����Ĺ����ӿڣ��Զ���+����Base�ӿڣ�
class DEF_NO_VTABLE I{base}
{
public:

	///@brief  ��ǰ�ӿڰ汾��
	///@param1 dwMaxVersion �߰汾
	///@param2 dwMaxVersion �Ͱ汾
	///@return int �ɹ�>0
	STDMETHOD_(int, QueryVerSion)(DWORD & dwMaxVersion, DWORD & dwMinVersion) PURE;

	///@brief ��ʼ������,�������û��Ҫ�ص��ĺ���ֱ�ӵ�Init�����þ���
	///@param ��ػص�������ַ(struct������ַ����). 
	///@return int �ɹ�>0
	STDMETHOD_(int, InitCallBack)(const {base}_CALLBACKFUNC_PTR_SET & callback_ptr_set) PURE;

	///@brief����һ��������com�ӿڵ���չ,Ŀ���ǿ����ú�������������е�ִ�������չִ��.
	///!!!��֮��ά��dll����Ա����չ�ĺ����������ϸ˵����
	///@param1  LPCWSTR   �������
	///@param2  VARIANT*  ������ַ
	///@param3  int       ��������
	///@param4  VARIANT*  ���ؽ������
	///@return  HRESULT   �ɹ�����S_OK��ʧ�ܷ���S_FALSE
	STDMETHOD_(HRESULT, InVokeN)(const LPCWSTR, VARIANT*, int, VARIANT*) PURE;

	///@brief  �Ƿ񱾽ӿ������е���Ϣ(�ڴ�)
	///@param  ��
	///@return ��
	STDMETHOD_(void,   Release)() PURE;   
	
	///!!!����������Լ���Ҫ��չ�Ľӿ�
};

///dllͳһ�����Ӹ��ӿ�.
//EXTERN_API BOOL API_CALLTYPE CreateInstance(I{base}**);

#endif // 