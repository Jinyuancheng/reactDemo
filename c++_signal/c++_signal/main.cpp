#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";
}

int main1()
{
	int i = 0;
	// ע���ź� SIGINT ���źŴ������
	signal(SIGINT, signalHandler);

	while (++i) {
		cout << "Going to sleep...." << endl;
		if (i == 3) {
			raise(SIGINT);
		}
		Sleep(1000);
	}

	return 0;
}