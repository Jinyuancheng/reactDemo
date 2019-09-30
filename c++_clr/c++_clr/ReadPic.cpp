
#include "ReadPic.h"
//#include <afx.h>

typedef void*(*FuncReadPicInfo)(const char*);

/****************************************!
*@brief  读取图片信息到内存中
*@author Jinzi
*@date   2019/09/19 17:22:55
*@param[in]
   _cchpPicPath	:	图片路径
   _chpSavePicInfo	:	传递过来的地址 用来存储数据
   _ipPicInfoLen	:	数据的长度
*@param[out]
*@return
****************************************/
bool ReadPictureInfo(const char* _cchpPicPath, std::string& _sSavePicInfo)
{
	/*bool bIsSucc = false;
	if (_cchpPicPath == nullptr)
	{
		return bIsSucc;
	}
	CReadPic^ pReadPic = gcnew CReadPic();
	System::String^ filePath = gcnew System::String(_cchpPicPath);
	CString csReadPicInfo;
	csReadPicInfo = pReadPic->ReadPicInfo(filePath);
	if (!csReadPicInfo.IsEmpty())
	{
		bIsSucc = true;
		std::string sPicInfo(csReadPicInfo.GetBuffer());
		_sSavePicInfo = sPicInfo;
	}
	return bIsSucc;*/

	bool bIsSucc = false;
	FuncReadPicInfo func;
	if (_cchpPicPath == nullptr)
	{
		return bIsSucc;
	}
	CReadPic^ pReadPic = gcnew CReadPic();
	System::String^ filePath = gcnew System::String(_cchpPicPath);
	/*array<unsigned char>^ sReadPicInfo = gcnew System::String("");

*/
	array<System::Byte>^ woqu;
	woqu = pReadPic->ReadPicInfo(filePath);
	char* data = (char*)func(_cchpPicPath);

	/*const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sReadPicInfo)).ToPointer();
	std::string cs = chars;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	if (cs.length() != 0)
	{
		_sSavePicInfo = cs;
		bIsSucc = true;
	}*/
	return bIsSucc;
}