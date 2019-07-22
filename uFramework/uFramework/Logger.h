#pragma once

#include <iostream>

namespace uFramework
{
	class Logger
	{
	public:

		//Methods
		static void FileNotFound(std::string Pathname);
		static void IndexAlreadyExists(std::string ClassName, std::string Index);
		static void Log(std::string Message);
	};

}