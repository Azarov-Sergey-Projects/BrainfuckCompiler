#pragma once
#include <string>
#include <array>
#include <iterator>
#include <stack>
class CCompiler
{
public:
	CCompiler();                                           //using to  fill data by default
	void readInstructionsFromFile(const std::string& fileName);
	void compileInstructions();
	void setInstructions(const std::string& inputInstructions);
private:
	std::array<char,30000> data;                           //in default Brainfuck by Muller used 1 byte with 30000 cells
	std::string instructions;                              //here we will save our commands from file
	std::stack<std::string::iterator> StackForBraces;      //needed for operation '['
	std::array<char, 30000>::iterator dataIterator=data.begin();  //for much easier iterate 
};