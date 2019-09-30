#include <iostream>
#include <queue>
using namespace std;

typedef enum
{
	UNKNOW = 0,			//ÎÞÀàÐÍ
	TRANSFER_ACCOUNT,	//×ªÕË
}eOptType;

class CUser
{
public:
	CUser(std::string _User, std::string _Pass, float _Money)
		:Money(_Money), UserName(_User), PassWord(_Pass) {
		bIsLogin = false;
	}
public:
	bool Login(std::string _User, std::string _Pass)
	{
		if (_User == UserName && _Pass == PassWord)
		{
			bIsLogin = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	void ChangePass(std::string _Pass) { if (bIsLogin) { this->PassWord = _Pass; } else { std::cout << "ÇëµÇÂ¼" << std::endl; } }
	void AddMoney(float _Money) { if (bIsLogin) { this->Money += _Money; } else { std::cout << "ÇëµÇÂ¼" << std::endl; } }
	void ReduceMoney(float _Money) { if (bIsLogin) { this->Money -= _Money; } else { std::cout << "ÇëµÇÂ¼" << std::endl; } }
	void Print() { std::cout << "this->Money = " << this->Money << std::endl; }
	bool GetIsLogin() { return bIsLogin; }
	void SendMsg(eOptType _MsgType) { this->queMsg.push(_MsgType); }
private:
	float Money;
	std::string UserName;
	std::string PassWord;
	bool bIsLogin;
	std::queue<eOptType> queMsg;
};

class CBank
{
public:
	CBank() {};
public:
	//×ªÕË
	void AddMoney(CUser& UserA, CUser& UserB, float Money)
	{
		if (UserA.GetIsLogin() && UserB.GetIsLogin())
		{
			UserA.ReduceMoney(Money);
			UserB.AddMoney(Money);
			std::cout << "×ªÕË³É¹¦" << std::endl;
		}
		else
		{
			std::cout << "×ªÕËÊ§°Ü" << std::endl;
		}
	}
private:
	eOptType m_OptType;
};

int main1(int argc, char *argv[])
{
	CUser* UserA = new CUser("admin", "admin", 1000);
	CUser* UserB = new CUser("jinzi", "jinzi", 1000);
	CBank* Bank = new CBank();

	UserA->Login("admin", "admin");
	UserB->Login("jinzi", "jinzi");

	Bank->AddMoney(*UserA, *UserB, 500);
	UserA->Print();
	UserB->Print();

	system("pause");
	return 0;
}