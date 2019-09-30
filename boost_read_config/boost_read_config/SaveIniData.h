#pragma once
#ifndef _SAVEINIDATA_H_
#define _SAVEINIDATA_H_
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
typedef struct
{
	std::string Ip;
	std::string port;
}Stru_ServerConfig, * pStru_ServerConfig;

typedef struct
{
	std::string host;
	std::string user;
	std::string pass;
	std::string database;
}Stru_MysqlConfig, * pStru_MysqlConfig;

class CSaveIniData
{
public:
	CSaveIniData(std::string& filename);
	~CSaveIniData();
public:
	Stru_MysqlConfig GetMysqlConfig();
	Stru_ServerConfig GetServerConfig();
	std::string toString();
private:
	boost::property_tree::ptree m_oParent;
	boost::property_tree::ptree m_oChild;
	Stru_ServerConfig   m_oServerConfig;
	Stru_MysqlConfig	m_oMysqlConfig;
};
#endif


