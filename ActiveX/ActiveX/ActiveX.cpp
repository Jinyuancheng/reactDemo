// ActiveX.cpp: CActiveXApp 和 DLL 注册的实现。

#include "pch.h"
#include "framework.h"
#include "ActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CActiveXApp theApp;

const GUID CDECL _tlid = {0x305c741e,0x0033,0x46c9,{0xb4,0x6d,0x74,0x97,0x9e,0xdc,0xe6,0x1a}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CActiveXApp::InitInstance - DLL 初始化

BOOL CActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CActiveXApp::ExitInstance - DLL 终止

int CActiveXApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
