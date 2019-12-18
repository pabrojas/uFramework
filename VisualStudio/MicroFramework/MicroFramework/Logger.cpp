#include "pch.h"
#include "Logger.h"

#include <iostream>
#include <string>


void Logger::fileNotFound(std::string pathname)
{
	std::cout << "File not found : " << pathname << std::endl;
}

void Logger::indexNotFound(std::string listName, std::string index)
{
	std::cout << "Index : \"" << index << "\" not found on list \"" << listName << "\"" << std::endl;
}

void Logger::indexAlreadyExists(std::string className, std::string index)
{
	std::cout << "Index : \"" + index << "\" already exists on \"" << className << "\" list" << std::endl;
}

void Logger::log(std::string message)
{
	std::cout << message << std::endl;
}

void Logger::logSL(std::string message)
{
	std::cout << message ;
}

void Logger::keyNotFound()
{
	std::cout << "Key not found" << std::endl;
}

void Logger::printBounds(float x1, float y1, float x2, float y2)
{
	std::cout << "x(" << x1 << ", " << x2 << ") y(" << y1 << ", " << y2 << ")" << std::endl;
}

void Logger::printPoint(float x, float y)
{
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

void Logger::printObject(float x, float y, float w, float h, bool defaultSize, std::string sprite)
{
	std::cout << "[x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << ", default: " << defaultSize << ", sprite: " << sprite << "]" << std::endl;
}
