#include "CCompiler.h"
#include <fstream>


CCompiler::CCompiler()
{
	data.fill('0');
}

void CCompiler::readInstructionsFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
        throw std::runtime_error("Failed to open '" + fileName + "'.");

    while (file.good()) {
        instructions.push_back(file.get());
    }
}

void CCompiler::interpretFunctions()
{

}