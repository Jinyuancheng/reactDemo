
// mfc_second_testView.cpp: CmfcsecondtestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mfc_second_test.h"
#endif

#include "mfc_second_testDoc.h"
#include "mfc_second_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcsecondtestView

IMPLEMENT_DYNCREATE(CmfcsecondtestView, CView)

BEGIN_MESSAGE_MAP(CmfcsecondtestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmfcsecondtestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmfcsecondtestView 构造/析构

CmfcsecondtestView::CmfcsecondtestView() noexcept
{
	// TODO: 在此处添加构造代码

}

CmfcsecondtestView::~CmfcsecondtestView()
{
}

BOOL CmfcsecondtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmfcsecondtestView 绘图

void CmfcsecondtestView::OnDraw(CDC* /*pDC*/)
{
	CmfcsecondtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CmfcsecondtestView 打印


void CmfcsecondtestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmfcsecondtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmfcsecondtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmfcsecondtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CmfcsecondtestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmfcsecondtestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmfcsecondtestView 诊断

#ifdef _DEBUG
void CmfcsecondtestView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcsecondtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcsecondtestDoc* CmfcsecondtestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcsecondtestDoc)));
	return (CmfcsecondtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcsecondtestView 消息处理程序
