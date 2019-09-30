/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/26 13:24		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 用来测试连接mysql数据库				  
***************************************************************/
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

int main(int argc,char *argv[])
{
	cout << endl;
	cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
		/* Connect to the MySQL test database */
		con->setSchema("jbl_shop");
		stmt = con->createStatement();
		res = stmt->executeQuery("select * from user_manage");
		while (res->next()) {
			cout << "\t... MySQL replies: ";
			/* Access column data by alias or column name */
			cout << res->getString("_message") << endl;
			cout << "\t... MySQL says it again: ";
			/* Access column data by numeric offset, 1 is the first column */
			cout << res->getString(1) << endl;
		}
		delete res;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " 
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	cout << endl;
	return EXIT_SUCCESS;
	return 0;
}
