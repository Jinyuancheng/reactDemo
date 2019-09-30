#ifndef _JINZI_UTILS_H_
#include "./jinzi_utils.h"
#endif // !_JINZI_UTILS_H_
/****************************************!
*@brief  ���ַ�����ɾ��ָ�����ַ�
*@author Jinzi
*@date   2019/05/20 10:11:35
*@param[in]  _DesStrData Դ�ַ���
			 _DelStr Ҫɾ�����ַ�
*@param[out]
*@return     ����ɾ��ָ���ַ�����ַ���
****************************************/
char* DelStrInChar(char* _DesStrData, char _DelStr)
{
	int i, j;
	char data[4096] = { 0 };
	strcpy(data, _DesStrData);
	for (i = 0, j = 0; data[i] != '\0'; i++) {
		if (data[i] != _DelStr)
		{
			data[j++] = data[i];
		}
	}
	data[j] = '\0';
	return data;
}
/****************************************!
*@brief  �ж��ַ������Ƿ����ĳ���ַ�
*@author Jinzi
*@date   2019/05/20 12:42:11
*@param[in]  _DesStrData Դ�ַ���
			 _DelStr Ҫɾ�����ַ�
*@param[out]
*@return     ���ڷ���true �����ڷ���false
****************************************/
int JuageStrinCharExit(char* _DesStrData, char _DelStr)
{
	while (*_DesStrData != '\0')
	{
		if (*_DesStrData == _DelStr)
		{
			return true;
		}
	}
	return false;
}
/****************************************!
*@brief  ����ָ���ַ������ַ������и�
*@author Jinzi
*@date   2019/05/20 15:17:44
*@param[in] _DesStrData Ҫ�����и���ַ���
			_DelStr ���ݸ��ַ������и�
			_SaveStr �洢�и�������
*@param[out]
*@return     �����и�������
****************************************/
char* Split(char* _DesStrData, const char* _DelStr, char** _SaveStr)
{
	char * pch;
	//printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(_DesStrData, _DelStr);
	while (pch != NULL)
	{
		*_SaveStr = pch;
		_SaveStr++;
		pch = strtok(NULL, _DelStr);
	}
}
