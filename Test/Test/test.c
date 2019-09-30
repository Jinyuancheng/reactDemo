#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Split(char* _DesStrData, const char* _DelStr, char** _SaveStr)
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
void DelStrInChar(char* _DesStrData, char _DelStr, char* _HandleStr)
{
	int i, j;
	strcpy(_HandleStr, _DesStrData);
	for (i = 0, j = 0; _HandleStr[i] != '\0'; i++) {
		if (_HandleStr[i] != _DelStr)
		{
			_HandleStr[j++] = _HandleStr[i];
		}
	}
	_HandleStr[j] = '\0';
}
int main1(int argc,char* argv[])
{
	char A[] = "192.168.1.22";
	char woqu[120] = { 0 };
	const char* dian = ".";
	DelStrInChar(A, '.', woqu);
	printf("%s\n",woqu);
	system("pause");

	return 0;
}