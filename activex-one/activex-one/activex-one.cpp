// activex-one.cpp: CactivexoneApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "activex-one.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CactivexoneApp theApp;

const GUID CDECL _tlid = {0x99a3ca47,0x1f5c,0x41fb,{0x81,0x2c,0x91,0x4a,0x94,0x99,0xab,0xbd}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CactivexoneApp::InitInstance - DLL 初始化

BOOL CactivexoneApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CactivexoneApp::ExitInstance - DLL 终止

int CactivexoneApp::ExitInstance()
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
