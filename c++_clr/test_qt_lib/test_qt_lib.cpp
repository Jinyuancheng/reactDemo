#include "test_qt_lib.h"
#include <iostream>
#include <windows.h>
//#define _AFXDLL
typedef bool(*FuncReadPictureInfo)(const char*, std::string&);
test_qt_lib::test_qt_lib(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	std::string sSaveBuff;
	int* ipLen = nullptr;
	FuncReadPictureInfo ReadPictureInfo = nullptr;
	HMODULE pInstance = LoadLibraryA("./ReadPic.dll");
	if (pInstance != nullptr)
	{
		ReadPictureInfo = (FuncReadPictureInfo)GetProcAddress(pInstance, "ReadPictureInfo");
	}
	if (ReadPictureInfo("H:\\gif\\jinzi.jpg", sSaveBuff))
	{
		std::cout << "success" << std::endl;
		std::cout << sSaveBuff.c_str() << std::endl;
	}
	else
	{
		std::cout << "failed" << std::endl;
	}

}
