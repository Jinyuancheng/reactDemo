
#include <stdio.h>  
#include <string.h>        
#include "iniFile.h"
 /****************************************!
 *@brief  �õ������ļ��е�ָ��key��Ӧ��ֵ
 *@author Jinzi
 *@date   2019/05/09 10:07:02
 *@param[in]  title �����ļ���һ�����ݵı�ʶ
			  key ����������ҩ������ֵ�ı�ʶ
			  filename Ҫ��ȡ���ļ�·��
			  buf �洢��keyֵ��Ӧ������
 *@param[out] 
 *@return     �ɹ�����0 ʧ�ܷ���-1
 ****************************************/
int GetIniKeyString(const char *title, const char *key, const char *filename, const char *buf)
{
	FILE *fp;
	int  flag = 0;
	char sTitle[64], *wTmp;
	char sLine[1024];
	sprintf(sTitle, "[%s]", title);

	if (NULL == (fp = fopen(filename, "r"))) {
		perror("fopen");
		return -1;
	}
	while (NULL != fgets(sLine, 1024, fp)) {
		// ����ע����  
		if (0 == strncmp("//", sLine, 2)) continue;
		if ('#' == sLine[0])              continue;
		wTmp = strchr(sLine, '=');
		if ((NULL != wTmp) && (1 == flag)) {
			if (0 == strncmp(key, sLine, strlen(key))) { // �������ļ���ȡ��Ϊ׼  
				sLine[strlen(sLine) - 1] = '\0';
				fclose(fp);
				while (*(wTmp + 1) == ' ') {
					wTmp++;
				}
				strcpy(buf, wTmp + 1);
				return 0;
			}
		}
		else {
			if (0 == strncmp(sTitle, sLine, strlen(sTitle))) { // �������ļ���ȡ��Ϊ׼  
				flag = 1; // �ҵ�����λ��  
			}
		}
	}
	fclose(fp);
	return -1;
}

 /****************************************!
 *@brief  �������ļ���д������
 *@author Jinzi
 *@date   2019/05/09 10:09:43
 *@param[in]  title �����ļ���һ�����ݵı�ʶ
			  key ���������е�key
			  val �޸ĺ��ֵ
			  filename �ļ�·��
 *@param[out] 
 *@return     ʧ�ܷ��� -1
 ****************************************/
int PutIniKeyString(const char *title, const char *key, const char *val, const char *filename)
{
	FILE *fpr, *fpw;
	int  flag = 0;
	char sLine[1024], sTitle[32], *wTmp;
	sprintf(sTitle, "[%s]", title);
	if (NULL == (fpr = fopen(filename, "r")))
		return -1;// ��ȡԭ�ļ�  
	sprintf(sLine, "%s.tmp", filename);
	if (NULL == (fpw = fopen(sLine, "w")))
		return -1;// д����ʱ�ļ�        
	while (NULL != fgets(sLine, 1024, fpr)) {
		if (2 != flag) { // ����ҵ�Ҫ�޸ĵ���һ�У��򲻻�ִ���ڲ��Ĳ���  
			wTmp = strchr(sLine, '=');
			if ((NULL != wTmp) && (1 == flag)) {
				if (0 == strncmp(key, sLine, strlen(key))) { // �������ļ���ȡ��Ϊ׼ 
					flag = 2;// ����ֵ������д���ļ�  
					sprintf(wTmp + 1, " %s\n", val);
				}
			}
			else {
				if (0 == strncmp(sTitle, sLine, strlen(sTitle))) { // �������ļ���ȡ��Ϊ׼
					flag = 1; // �ҵ�����λ��  
				}
			}
		}
		fputs(sLine, fpw); // д����ʱ�ļ� 
	}
	fclose(fpr);
	fclose(fpw);
	sprintf(sLine, "%s.tmp", filename);
	/*\ ɾ�����ϵ��ļ���ֹ���� \*/
	remove(filename);
	/*\ ��һ������ �ϵ��ļ���ַ �ڶ������� �µ��ļ���ַ \*/
	return rename(sLine, filename);// ����ʱ�ļ����µ�ԭ�ļ�  
}