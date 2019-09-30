// ActiveXCtrl.cpp : CActiveXCtrl ActiveX 控件类的实现。

#include "pch.h"
#include "framework.h"
#include "ActiveX.h"
#include "ActiveXCtrl.h"
#include "ActiveXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CActiveXCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CActiveXCtrl, 1)
	PROPPAGEID(CActiveXPropPage::guid)
END_PROPPAGEIDS(CActiveXCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CActiveXCtrl, "MFCACTIVEXCONTRO.ActiveXCtrl.1",
	0xd1ce14d7,0x1052,0x4a82,0x92,0x48,0xd9,0x35,0xd2,0xc5,0x71,0x01)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DActiveX = {0x4330cc94,0xf458,0x4899,{0xaf,0xef,0x73,0xe9,0xa2,0xb3,0xcf,0x77}};
const IID IID_DActiveXEvents = {0xbfc4769d,0x8080,0x4eb6,{0x9a,0x9a,0xf6,0x83,0xdd,0xbe,0xf3,0x38}};

// 控件类型信息

static const DWORD _dwActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CActiveXCtrl, IDS_ACTIVEX, _dwActiveXOleMisc)

// CActiveXCtrl::CActiveXCtrlFactory::UpdateRegistry -
// 添加或移除 CActiveXCtrl 的系统注册表项

BOOL CActiveXCtrl::CActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ACTIVEX,
			IDB_ACTIVEX,
			afxRegApartmentThreading,
			_dwActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CActiveXCtrl::CActiveXCtrl - 构造函数

CActiveXCtrl::CActiveXCtrl()
{
	InitializeIIDs(&IID_DActiveX, &IID_DActiveXEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CActiveXCtrl::~CActiveXCtrl - 析构函数

CActiveXCtrl::~CActiveXCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CActiveXCtrl::OnDraw - 绘图函数

void CActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CActiveXCtrl::DoPropExchange - 持久性支持

void CActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CActiveXCtrl::OnResetState - 将控件重置为默认状态

void CActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CActiveXCtrl::AboutBox - 向用户显示“关于”框

void CActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ACTIVEX);
	dlgAbout.DoModal();
}


// CActiveXCtrl 消息处理程序
