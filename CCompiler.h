#pragma once
#include <string>
#include <array>

class CCompiler
{
public:
	CCompiler();
	void readInstructionsFromFile(const std::string& fileName);
	void interpretFunctions();
private:
	std::array<char,30000> commands;
};