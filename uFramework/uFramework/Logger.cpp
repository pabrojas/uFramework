#include "Logger.h"
#include <iostream>
#include <string>

using namespace uFramework;

void Logger::fileNotFound(std::string Pathname)
{
	std::cout << "File not found : " << Pathname << std::endl;
}

void Logger::indexNotFound(std::string ListName, std::string Index)
{
	std::cout << "Index : \"" << Index << "\" not found on list \"" << ListName << "\"" << std::endl;
}

void Logger::indexAlreadyExists(std::string ClassName, std::string Index)
{
	std::cout << "Index : \"" + Index << "\" already exists on \"" << ClassName << "\" list" << std::endl;
}

void Logger::log(std::string Message)
{
	std::cout << Message << std::endl;
}

void Logger::keyNotFound()
{
	std::cout << "Key not found" << std::endl;
}
