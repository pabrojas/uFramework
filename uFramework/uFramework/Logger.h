#pragma once

#include <string>

namespace uFramework
{
	class Logger
	{
	public:

		//Methods
		static void fileNotFound(std::string Pathname);
		static void indexNotFound(std::string ListName, std::string Index);
		static void indexAlreadyExists(std::string ClassName, std::string Index);
		static void log(std::string Message);
		static void keyNotFound();
		static void printBounds(float x1, float y1, float x2, float y2);
		static void printPoint(float x, float y);
	};

}