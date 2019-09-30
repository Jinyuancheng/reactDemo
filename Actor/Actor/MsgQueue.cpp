#include <iostream>
#include <queue>
using namespace std;

class CUser
{
public:
	CUser(std::string _sUser, std::string _sPass, int _dbMoney)
		:m_sUser(_sUser), m_sPass(_sPass), m_dbMoney(_dbMoney) {
		m_bIsLogin = false;
		m_bIsCloseAccount = false;
	}
public:
	bool Login(std::string _sUser, std::string _sPass)
	{
		if (!m_bIsCloseAccount)
		{
			if (_sUser == m_sUser && _sPass == m_sPass)
			{
				m_bIsLogin = true;
				std::cout << m_sUser.c_str() << " : Login Success" << std::endl;
				return true;
			}
			else
			{
				std::cout << m_sUser.c_str() << " : Pass Error" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << m_sUser.c_str() << " : Account Is Close" << std::endl;
			return false;
		}
	}
	void LoginOut()
	{
		if (m_bIsLogin)
		{
			m_bIsLogin = false;
		}
	}
	void CloseAccount()
	{
		if (!m_bIsCloseAccount)
		{
			m_bIsCloseAccount = true;
			std::cout << m_sUser.c_str() << " : Close Account Success" << std::endl;
		}
	}
	void unCloseAccount()
	{
		if (m_bIsCloseAccount)
		{
			m_bIsCloseAccount = false;
			std::cout << m_sUser.c_str() << " : unClose Account Success";
		}
	}
	void AddMoney(int _dbMoney)
	{
		if (!m_bIsCloseAccount && m_bIsLogin)
		{
			this->m_dbMoney += _dbMoney;
		}
	}
	void ReduceMoney(int _dbMoney)
	{
		if (m_bIsLogin && !m_bIsCloseAccount)
		{
			this->m_dbMoney -= _dbMoney;
		}
	}
	void ChangePass(std::string _sPass)
	{
		if (!m_bIsCloseAccount && m_bIsLogin)
		{
			this->m_sPass = _sPass;
		}
	}
	void Print()
	{
		std::cout << m_sUser.c_str() << " : this->Money = " << this->m_dbMoney << std::endl;
	}
private:
	std::string m_sUser;
	std::string m_sPass;
	bool		m_bIsLogin;
	bool		m_bIsCloseAccount;
	int			m_dbMoney;
};

class CBank
{
public:
	CBank() {};
public:
	void TransferAccount(CUser& _oUserA, CUser& _oUserB, int _dbMoney)
	{
		_oUserA.ReduceMoney(_dbMoney);
		_oUserB.AddMoney(_dbMoney);
		_oUserA.Print();
		_oUserB.Print();
	}
};

int main(int argc, char *argv[])
{
	CUser* oUserA = new CUser("admin", "admin", 10000);
	CUser* oUserB = new CUser("jinzi", "jinzi", 10000);
	CBank* oBank = new CBank();

	oUserA->Login("admin", "admin");
	oUserB->Login("jinzi", "jinzi");

	oBank->TransferAccount(*oUserA, *oUserB, 500);

	system("pause");
	return 0;
}