#pragma once

#include <string>

class Logger
{
public:

	//Methods
	static void fileNotFound(std::string pathname);
	static void indexNotFound(std::string listName, std::string index);
	static void indexAlreadyExists(std::string className, std::string index);
	static void log(std::string message);
	static void logSL(std::string message);
	static void keyNotFound();
	static void printBounds(float x1, float y1, float x2, float y2);
	static void printPoint(float x, float y);
	static void printObject(float x, float y, float w, float h, bool defaultSize, std::string sprite);

};

