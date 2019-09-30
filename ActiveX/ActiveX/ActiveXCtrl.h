#pragma once

// ActiveXCtrl.h : CActiveXCtrl ActiveX 控件类的声明。


// CActiveXCtrl : 请参阅 ActiveXCtrl.cpp 了解实现。

class CActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CActiveXCtrl)

// 构造函数
public:
	CActiveXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CActiveXCtrl();

	DECLARE_OLECREATE_EX(CActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CActiveXCtrl)		// 类型名称和杂项状态

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

