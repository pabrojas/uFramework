#include "Logger.h"

using namespace uFramework;

void Logger::FileNotFound(std::string Pathname)
{
	std::cout << "File not found : " + Pathname << std::endl;
}

void Logger::IndexAlreadyExists(std::string ClassName, std::string Index)
{
	std::cout << "Index : \"" + Index << "\" already exists on \"" << ClassName << "\" list" << std::endl;
}

void uFramework::Logger::Log(std::string Message)
{
	std::cout << Message << std::endl;
}
