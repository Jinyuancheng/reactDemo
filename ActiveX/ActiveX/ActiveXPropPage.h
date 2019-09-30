#pragma once

// ActiveXPropPage.h: CActiveXPropPage 属性页类的声明。


// CActiveXPropPage : 请参阅 ActiveXPropPage.cpp 了解实现。

class CActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CActiveXPropPage)
	DECLARE_OLECREATE_EX(CActiveXPropPage)

// 构造函数
public:
	CActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_ACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

