#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <map>
using namespace std;

//学生成绩
typedef struct  
{
	std::string fMath;			/*\ 数学成绩 \*/
	std::string fChinese;		/*\ 语文成绩 \*/
	std::string fEnglish;		/*\ 英语成绩 \*/
}STUDENT_GARDE, *PSTUDENT_GARDE;
//学生属性
typedef struct  
{
	std::string fWeight;		/*\ 体重 \*/
	std::string fHeight;		/*\ 身高 \*/
}STUDENT_INFO, *PSTUDENT_INFO;
//学生
class CStudent
{
public:
	CStudent() {}
	~CStudent() {}
	void SetStuInfo(STUDENT_INFO& _StuInfo) { this->m_oStuInfo = _StuInfo; }
	void SetStuGarde(STUDENT_GARDE& _StuGarde) { this->m_oStuGarde = _StuGarde; }
	void SetStuId(std::string _StuId) { this->m_iId = _StuId; }
	void SetStuName(std::string _StuName) { this->m_sName = _StuName; }
	void SetStuSchool(std::string _StuSchool) { this->m_sSchool = _StuSchool; }
	std::string GetStuId() { return this->m_iId; }
	void StuPrint()
	{
		std::cout << "Student Id : " << this->m_iId << std::endl;
		std::cout << "Student Name : " << this->m_sName << std::endl;
		std::cout << "Student School : " << this->m_sSchool << std::endl;
		std::cout << "Student Weight : " << this->m_oStuInfo.fWeight << std::endl;
		std::cout << "Student Height : " << this->m_oStuInfo.fHeight << std::endl;
		std::cout << "Student Math : " << this->m_oStuGarde.fMath << std::endl;
		std::cout << "Student Chinese : " << this->m_oStuGarde.fChinese << std::endl;
		std::cout << "Student English : " << this->m_oStuGarde.fEnglish<< std::endl;
	}
private:
	std::string			m_iId;			/*\ 学生id \*/
	std::string			m_sName;		/*\ 学生名字 \*/
	std::string			m_sSchool;		/*\ 学生学校的名称 \*/
	STUDENT_INFO		m_oStuInfo;		/*\ 学生信息 \*/
	STUDENT_GARDE		m_oStuGarde;	/*\ 学生成绩 \*/
};

int main1(int argc,char *argv[])
{
	boost::property_tree::ptree oParentIni, oChildIni;
	boost::property_tree::ptree oParentXml, oChildXml;
	std::map<std::string, CStudent> mapStudents;
	std::map<std::string, CStudent>::iterator itStuOpt;
	STUDENT_GARDE strStuGarde;
	STUDENT_INFO strStuInfo;
	CStudent oStu;
	read_ini("./config.ini", oParentIni);
	read_xml("./config_attr.xml", oParentXml);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v1, oParentXml.get_child("student"))
	{
		if (v1.first == "stu")
		{
			memset(&strStuGarde, 0, sizeof(strStuGarde));
			memset(&strStuInfo, 0, sizeof(strStuInfo));
			BOOST_FOREACH(boost::property_tree::ptree::value_type &v2, v1.second)
			{
				if (v2.first == "<xmlattr>")
				{
					oStu.SetStuId(v1.second.get<std::string>("<xmlattr>.id"));
				}
				else if (v2.first == "grade")
				{
					strStuGarde.fMath = v2.second.get<std::string>("<xmlattr>.shuxue");
					strStuGarde.fChinese = v2.second.get<std::string>("<xmlattr>.yuwen");
					strStuGarde.fEnglish = v2.second.get<std::string>("<xmlattr>.yingyu");
				}
				else if (v2.first == "info")
				{
					strStuInfo.fWeight = v2.second.get<std::string>("<xmlattr>.weight");
					strStuInfo.fHeight = v2.second.get<std::string>("<xmlattr>.height");
				}
			}
			oStu.SetStuName(v1.second.get<std::string>("name"));
			oStu.SetStuGarde(strStuGarde);
			oStu.SetStuInfo(strStuInfo);
			mapStudents.insert(std::map<std::string, CStudent>::value_type(oStu.GetStuId(), oStu));
		}
	}
	/*\ 读取ini配置文件 \*/
	oChildIni = oParentIni.get_child("STUDENT1");
	itStuOpt = mapStudents.find(oChildIni.get<std::string>("id"));
	if (itStuOpt != mapStudents.end())
	{
		itStuOpt->second.SetStuSchool(oChildIni.get<std::string>("school"));
	}
	oChildIni = oParentIni.get_child("STUDENT2");
	itStuOpt = mapStudents.find(oChildIni.get<std::string>("id"));
	if (itStuOpt != mapStudents.end())
	{
		itStuOpt->second.SetStuSchool(oChildIni.get<std::string>("school"));
	}
	oChildIni = oParentIni.get_child("STUDENT3");
	itStuOpt = mapStudents.find(oChildIni.get<std::string>("id"));
	if (itStuOpt != mapStudents.end())
	{
		itStuOpt->second.SetStuSchool(oChildIni.get<std::string>("school"));
	}
	oChildIni = oParentIni.get_child("STUDENT4");
	itStuOpt = mapStudents.find(oChildIni.get<std::string>("id"));
	if (itStuOpt != mapStudents.end())
	{
		itStuOpt->second.SetStuSchool(oChildIni.get<std::string>("school"));
	}
	for (std::map<std::string, CStudent>::iterator itStu = mapStudents.begin();
		itStu != mapStudents.end(); itStu++)
	{
		std::cout << "map==>first : " << itStu->first << "===============================================Start" << endl;
		itStu->second.StuPrint();
		std::cout << "map==>first : " << itStu->first << "===============================================End" << endl;
	}
	system("pause");
	return 0;
}