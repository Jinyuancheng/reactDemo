#include <iostream>
using namespace std;
int main()
{
	int x, y, n;
	for (x = 1, n = 0; n < 9; y = (x + 1) * 2, x = y, n++);
	cout << "第一天共摘的桃子数量为 " << x << endl;
	system("pause");
	return 0;
}