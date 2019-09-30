// activexoneCtrl.cpp : CactivexoneCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "activex-one.h"
#include "activexoneCtrl.h"
#include "activexonePropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CactivexoneCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CactivexoneCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CactivexoneCtrl, COleControl)
	DISP_FUNCTION_ID(CactivexoneCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CactivexoneCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CactivexoneCtrl, 1)
	PROPPAGEID(CactivexonePropPage::guid)
END_PROPPAGEIDS(CactivexoneCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CactivexoneCtrl, "MFCACTIVEXCONTRO.activexoneCtrl.1",
	0xfd510174,0x7005,0x4a4e,0xba,0xbe,0x04,0xf8,0x92,0xa1,0xc3,0x72)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CactivexoneCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_Dactivexone = {0xf7de0f19,0xc0f0,0x4e94,{0x92,0xc0,0x7b,0xdd,0x44,0x37,0xb7,0x9e}};
const IID IID_DactivexoneEvents = {0xca633a28,0x4a3d,0x45dd,{0x97,0x98,0x04,0xdb,0xcf,0x4e,0x88,0x09}};

// 控件类型信息

static const DWORD _dwactivexoneOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CactivexoneCtrl, IDS_ACTIVEXONE, _dwactivexoneOleMisc)

// CactivexoneCtrl::CactivexoneCtrlFactory::UpdateRegistry -
// 添加或移除 CactivexoneCtrl 的系统注册表项

BOOL CactivexoneCtrl::CactivexoneCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_ACTIVEXONE,
			IDB_ACTIVEXONE,
			afxRegApartmentThreading,
			_dwactivexoneOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CactivexoneCtrl::CactivexoneCtrl - 构造函数

CactivexoneCtrl::CactivexoneCtrl()
{
	InitializeIIDs(&IID_Dactivexone, &IID_DactivexoneEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CactivexoneCtrl::~CactivexoneCtrl - 析构函数

CactivexoneCtrl::~CactivexoneCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CactivexoneCtrl::OnDraw - 绘图函数

void CactivexoneCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CactivexoneCtrl::DoPropExchange - 持久性支持

void CactivexoneCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CactivexoneCtrl::OnResetState - 将控件重置为默认状态

void CactivexoneCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CactivexoneCtrl::AboutBox - 向用户显示“关于”框

void CactivexoneCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ACTIVEXONE);
	dlgAbout.DoModal();
}


// CactivexoneCtrl 消息处理程序
