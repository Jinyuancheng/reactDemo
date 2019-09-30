#pragma once

// activexoneCtrl.h : CactivexoneCtrl ActiveX 控件类的声明。


// CactivexoneCtrl : 请参阅 activexoneCtrl.cpp 了解实现。

class CactivexoneCtrl : public COleControl
{
	DECLARE_DYNCREATE(CactivexoneCtrl)

// 构造函数
public:
	CactivexoneCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CactivexoneCtrl();

	DECLARE_OLECREATE_EX(CactivexoneCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CactivexoneCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CactivexoneCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CactivexoneCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
};

