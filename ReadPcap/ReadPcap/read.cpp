#include "read.h"


int main(int argc, char* argv[])
{
	FILE* rfd;
	char* pchBuf = NULL;
	wfd = fopen("./jinzi.jpg","wb");
	if (wfd == NULL)
	{
		printf("error\n");
	}
	const char* FileName = "./hik.pcap"; 
	ReadPcap(FileName);
	fclose(wfd);
	return 0;
}
