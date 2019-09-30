#pragma once
#ifndef _SAVEJSONDATA_H_
#define _SAVEJSONDATA_H_
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
typedef struct
{
	std::string weight;
	std::string height;
}ATTR, * PATTR;

typedef struct
{
	std::string xiaoxue;
	std::string zhongxue;
	std::string gaozhong;
	std::string daxue;
}SCHOOL, * PSCHOOL;

typedef struct
{
	std::string id;
	std::string name;
	ATTR* attr;
	SCHOOL* school;
}STUDENT, * PSTUDENT;

class ReadJsonData
{
public:
	ReadJsonData(std::string& filename);
	~ReadJsonData();
public:
	PSTUDENT GetStudent();
private:
	boost::property_tree::ptree m_oParent;
	boost::property_tree::ptree m_oChild;
	PSTUDENT m_oStudent;
};
#endif

