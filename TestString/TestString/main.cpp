
#include<iostream>
#include<string>
using namespace std;

//void clean_string()

int main()
{

	std::string s = "    test\n\n ";
	cout << "first S = " << s << endl;
	size_t n = s.find_last_not_of(" \r\n\t");
	if (n != string::npos) {
		s.erase(n + 1, s.size() - n);
	}
	n = s.find_first_not_of(" \r\n\t");
	if (n != string::npos) {
		s.erase(0, n);
	}
	cout << "last S = " << s << "After" << endl;
	system("pause");
}