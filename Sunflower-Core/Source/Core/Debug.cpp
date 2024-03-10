#pragma once
#include <iostream>
#include <string>
namespace Sunflower
{
	void Log(const char* text)
	{
		std::cout << text;
	}
	void Log(float text)
	{
		std::cout << text;
	}
	void Log(int text)
	{
		std::cout << text;
	}
	void LogWarning(std::string text)
	{
		std::cout << "Warning: " + text;
	}

	void LogError(std::string text)
	{
		std::cout << "Error: " + text;
	}
};