#include <iostream>
using namespace std;

typedef union
{
	unsigned int A;
	struct
	{
		unsigned int AL1 : 1;
		unsigned int AL2 : 1;
		unsigned int AL3 : 1;
		unsigned int AL4 : 1;
		unsigned int AH : 4;
	};
	struct
	{
		unsigned int cA1 : 8;
		unsigned int cA2 : 8;
		unsigned int cA3 : 8;
		unsigned int cA4 : 8;
	};
}Example;

int main(int argc, char *argv[])
{
	Example EA;
	EA.A = 223;
	EA.AL2 = 0;
	std::cout << "AL1 : " << EA.AL1 << std::endl;
	std::cout << "AL2 : " << EA.AL2 << std::endl;
	std::cout << "AL3 : " << EA.AL3 << std::endl;
	std::cout << "AL4 : " << EA.AL4 << std::endl;
	std::cout << "AH : " << EA.AH << std::endl;
	std::cout << "cA1 : " << EA.cA1 << std::endl;
	std::cout << "cA2 : " << EA.cA2 << std::endl;
	std::cout << "cA3 : " << EA.cA3 << std::endl;
	std::cout << "cA4 : " << EA.cA4 << std::endl;


	system("pause");
	return 0;
}