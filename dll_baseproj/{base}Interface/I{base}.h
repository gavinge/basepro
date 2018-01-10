/***********************************************************************
* @file    *.h
* @brief   导出去给第外面用的准接口定义
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
/*****************************以下为一些回调上的约定***************************************/
#ifndef MIN
#define MIN(x,y) (x)<(y)?(x) : (y) 
#endif


//普通构造函数(结构体,类都可试用)
#ifndef DECLARE_DEFAULT_CONSTRUCTOR
#define DECLARE_DEFAULT_CONSTRUCTOR(ClassName)\
	ClassName()\
{\
	RtlZeroMemory(this,sizeof(ClassName));\
	this->dwSize = sizeof(ClassName);\
}
#endif


//拷贝构造函数(结构体,类都可试用)
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

//回调函数指针集合
typedef struct {base}_CALLBACKFUNC_PTR_SET
{
	DECLARE_DEFAULT_CONSTRUCTOR({base}_CALLBACKFUNC_PTR_SET);
	DECLARE_COPY_CONSTRUCTOR({base}_CALLBACKFUNC_PTR_SET);
	DECLARE_OPERATOR_EQUAL({base}_CALLBACKFUNC_PTR_SET);

	DWORD dwSize;                           //CALLBACKFUNC 结构大小
	///!!这里函数指针描述，请按照顺序描述(加了就站位，不要换顺序或者删除)。否则会出现新老版本函数地址错乱的问题。
	//LPFunCallBackDemo lpFunCallBackDemo;
}{base}_CALLBACKFUNC_PTR_SET, *LP{base}_CALLBACKFUNC_PTR_SET;


/**************************************************************************************************/
/*****************************以下为一些业务上用到的约定***************************************/

///接口内部版本号控制(每次发正式版dll出去该值都应该变化)
#define  MAX_{base}_VERSION  1       //接口版本(高)
#define  MIN_{base}_VERSION  0       //接口版本(低)



///对外的公共接口（自定义+公共Base接口）
class DEF_NO_VTABLE I{base}
{
public:

	///@brief  当前接口版本号
	///@param1 dwMaxVersion 高版本
	///@param2 dwMaxVersion 低版本
	///@return int 成功>0
	STDMETHOD_(int, QueryVerSion)(DWORD & dwMaxVersion, DWORD & dwMinVersion) PURE;

	///@brief 初始化函数,这里如果没有要回调的函数直接当Init函数用就行
	///@param 相关回调函数地址(struct连续地址描述). 
	///@return int 成功>0
	STDMETHOD_(int, InitCallBack)(const {base}_CALLBACKFUNC_PTR_SET & callback_ptr_set) PURE;

	///@brief这是一个类似于com接口的扩展,目的是可以用函数名称完成所有的执行体的扩展执行.
	///!!!请之后维护dll的人员将扩展的函数标记做详细说明。
	///@param1  LPCWSTR   函数标记
	///@param2  VARIANT*  参数地址
	///@param3  int       参数个数
	///@param4  VARIANT*  返回结果参数
	///@return  HRESULT   成功返回S_OK，失败返回S_FALSE
	STDMETHOD_(HRESULT, InVokeN)(const LPCWSTR, VARIANT*, int, VARIANT*) PURE;

	///@brief  是否本接口中所有的信息(内存)
	///@param  无
	///@return 无
	STDMETHOD_(void,   Release)() PURE;   
	
	///!!!在这里添加自己需要扩展的接口
};

///dll统一导出接个接口.
//EXTERN_API BOOL API_CALLTYPE CreateInstance(I{base}**);

#endif // 