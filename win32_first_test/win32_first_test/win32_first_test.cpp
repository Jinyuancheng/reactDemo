// win32_first_test.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "win32_first_test.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例		(HINSTANCE void*)
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本	(WCHAR 16位的unicode字符)
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名	(WCHAR 16位的unicode字符)

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);	/*\ 声明未引用的参数 \*/
    UNREFERENCED_PARAMETER(lpCmdLine);		/*\ 声明未引用的参数 \*/

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32FIRSTTEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
	/*\ 注册加速器表 \*/
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32FIRSTTEST));

    MSG msg;

    // 主消息循环:检索
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	/*\ 定义一个windows窗体对象 \*/
    WNDCLASSEXW wcex;
	/*\ 窗体的大小 \*/
    wcex.cbSize = sizeof(WNDCLASSEX);
	/*\ 窗体风格 后面两个枚举表示 移动宽度或者高度会自动重新绘制窗口 \*/
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
	/*\ 窗口消息处理函数 \*/
    wcex.lpfnWndProc    = WndProc;
	/*\ 额外的字节 \*/
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
	/*\ 包含该类的窗口过程的实例的句柄 \*/
    wcex.hInstance      = hInstance;
	/*\ 设置窗口图标 \*/
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32FIRSTTEST));
	/*\ 设置操作的鼠标图标 \*/
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	/*\ 设置背景色 \*/
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	/*\ 设置菜单 \*/
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32FIRSTTEST);
	/*\ 窗体的类的名称 \*/
    wcex.lpszClassName  = szWindowClass;
	/*\ 与窗口类关联的图标 \*/
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	/*\ 注册窗口 \*/
    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case IDM_LOGIN:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGIN), hWnd, About);
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
