#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InvertUint8(unsigned char *DesBuf, unsigned char *SrcBuf)
{
	int i;
	unsigned char temp = 0;

	for (i = 0; i < 8; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (7 - i);
		}
	}
	DesBuf[0] = temp;
}

void InvertUint16(unsigned short *DesBuf, unsigned short *SrcBuf)
{
	int i;
	unsigned short temp = 0;

	for (i = 0; i < 16; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (15 - i);
		}
	}
	DesBuf[0] = temp;
}

int main(int argc,char* argv[])
{
	unsigned short a = 10;
	unsigned short b = 0;
	unsigned char c = 1;
	unsigned char d = 0;
	InvertUint16(&b, &a);
	InvertUint8(&d, &c);
	printf("a = %d, sizeof(a) = %d\n", a, sizeof(a));
	printf("b = %d, sizeof(b) = %d\n", b, sizeof(b));
	printf("c = %d, sizeof(c) = %d\n", c, sizeof(c));
	printf("d = %d, sizeof(d) = %d\n", d, sizeof(d));
	system("pause");
	return 0;
}