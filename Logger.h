#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include <chrono>
#include <format>

class Logger
{
public:

	enum class Category {
		Info,
		Debug,
		Error,
		Critical
	};

	
	Logger();

	static void Log(Logger::Category category, const std::string& buffer);
	static void Info(const std::string& buffer);
	static void Error(const std::string& buffer);



private:
	static std::string GetCategoryString(Logger::Category cat);


};
