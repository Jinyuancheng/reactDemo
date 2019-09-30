#include "ReadJsonData.h"

ReadJsonData::ReadJsonData(std::string& filename) 
{
	read_json(filename, this->m_oParent);
	this->m_oStudent->id = m_oParent.get<std::string>("id");
	this->m_oStudent->name = m_oParent.get<std::string>("name");
	this->m_oChild = m_oParent.get_child("attr");
	this->m_oStudent->attr->weight = this->m_oChild.get<std::string>("weight");
	this->m_oStudent->attr->height = this->m_oChild.get<std::string>("height");
	this->m_oChild = m_oParent.get_child("school");
	this->m_oStudent->school->xiaoxue = this->m_oChild.get<std::string>("xiaoxue");
	this->m_oStudent->school->zhongxue = this->m_oChild.get<std::string>("zhongxue");
	this->m_oStudent->school->gaozhong = this->m_oChild.get<std::string>("gaozhong");
	this->m_oStudent->school->daxue = this->m_oChild.get<std::string>("daxue");
}
ReadJsonData::~ReadJsonData() {}
PSTUDENT ReadJsonData::GetStudent()
{
	return this->m_oStudent;
}