#pragma once

// activexonePropPage.h: CactivexonePropPage 属性页类的声明。


// CactivexonePropPage : 请参阅 activexonePropPage.cpp 了解实现。

class CactivexonePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CactivexonePropPage)
	DECLARE_OLECREATE_EX(CactivexonePropPage)

// 构造函数
public:
	CactivexonePropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_ACTIVEXONE };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

