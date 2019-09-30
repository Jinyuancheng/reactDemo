#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int add(int a, int b)
{
	return a + b;
}

int main(int argc,char* argv[])
{
	pid_t iPID;
	iPID = fork();
	if (iPID < 0)
	{
		printf("Create Chiled Proccess Error\n");
	}
	else
	{
		printf("Create Pid Is %d\n",iPID);
	}
	return 0;
}