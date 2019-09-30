#include <iostream>
#include <windows.h>
#include <functional>
#include <string>
using namespace std;

typedef bool(*FuncReadPictureInfo)(const char*, std::string&);

void StrToHex(const char lpSrcStr[], unsigned char lpRetBytes[], size_t *lpRetSize)
{
	if (lpSrcStr != NULL && lpRetBytes != NULL && lpRetSize != NULL) {
		size_t uiLength = strlen(lpSrcStr);
		if (uiLength % 2 == 0) {
			size_t i = 0;
			size_t n = 0;
			while (*lpSrcStr != 0 && (n = ((i++) >> 1)) < *lpRetSize) {
				lpRetBytes[n] <<= 4;
				if (*lpSrcStr >= TEXT('0') && *lpSrcStr <= TEXT('9')) {
					lpRetBytes[n] |= *lpSrcStr - '0';
				}
				else if (*lpSrcStr >= TEXT('a') && *lpSrcStr <= TEXT('f')) {
					lpRetBytes[n] |= *lpSrcStr - 'a' + 10;
				}
				else if (*lpSrcStr >= TEXT('A') && *lpSrcStr <= TEXT('F')) {
					lpRetBytes[n] |= *lpSrcStr - 'A' + 10;
				}
				lpSrcStr++;
			}
			*lpRetSize = n;
		}
	}
}

int main(int argc,char *argv[])
{
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
	system("pause");
	return 0;
}