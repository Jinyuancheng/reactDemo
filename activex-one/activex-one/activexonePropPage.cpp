// activexonePropPage.cpp : CactivexonePropPage 属性页类的实现。

#include "stdafx.h"
#include "activex-one.h"
#include "activexonePropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CactivexonePropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CactivexonePropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CactivexonePropPage, "MFCACTIVEXCONT.activexonePropPage.1",
	0xf4d87ccc,0xe295,0x4f21,0x8a,0x18,0x6a,0x45,0x7a,0xc1,0x2d,0x3e)

// CactivexonePropPage::CactivexonePropPageFactory::UpdateRegistry -
// 添加或移除 CactivexonePropPage 的系统注册表项

BOOL CactivexonePropPage::CactivexonePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACTIVEXONE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CactivexonePropPage::CactivexonePropPage - 构造函数

CactivexonePropPage::CactivexonePropPage() :
	COlePropertyPage(IDD, IDS_ACTIVEXONE_PPG_CAPTION)
{
}

// CactivexonePropPage::DoDataExchange - 在页和属性间移动数据

void CactivexonePropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CactivexonePropPage 消息处理程序
