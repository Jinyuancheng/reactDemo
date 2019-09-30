#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int VarA = 10;
	int* pVarA = nullptr;
	int** ppVarA = nullptr;
	int*** pppVarA = nullptr;
	pVarA = &VarA;
	ppVarA = &pVarA;
	pppVarA = &ppVarA;

	*pVarA = 20;
	std::cout << "pVarA Change = " << *pVarA << std::endl;

	**ppVarA = 30;
	std::cout << "ppVarA Change = " << **ppVarA << std::endl;
	
	***pppVarA = 40;
	std::cout << "pppVarA Change = " << ***pppVarA << std::endl;

	system("pause");
	return 0;
}