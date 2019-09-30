// ActiveXPropPage.cpp : CActiveXPropPage 属性页类的实现。

#include "pch.h"
#include "framework.h"
#include "ActiveX.h"
#include "ActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CActiveXPropPage, "MFCACTIVEXCONT.ActiveXPropPage.1",
	0x96ef62d7,0xb26d,0x4594,0x86,0x51,0x36,0x49,0x8c,0xce,0xd3,0x08)

// CActiveXPropPage::CActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CActiveXPropPage 的系统注册表项

BOOL CActiveXPropPage::CActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CActiveXPropPage::CActiveXPropPage - 构造函数

CActiveXPropPage::CActiveXPropPage() :
	COlePropertyPage(IDD, IDS_ACTIVEX_PPG_CAPTION)
{
}

// CActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CActiveXPropPage 消息处理程序
