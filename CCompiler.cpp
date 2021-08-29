#include "CCompiler.h"
#include <fstream>
#include <iostream>

CCompiler::CCompiler()
{
	data.fill(static_cast<char>(0));
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
    std::string::iterator f=instructions.begin();
    while (f!=instructions.end())
    {
        switch (*f)
        {
        case '<':
        {
            dataIterator--;
            break;
        }
        case '>':
        {
            dataIterator++;
            break;
        }
        case '+':
        {
            (*dataIterator) += 1;
            break;
        }
        case '-':
        {
            (*dataIterator) -= 1;
            break;
        }
        case '.':
        {
            std::cout << char(*dataIterator);
            break;
        }
        case '[':
        {
            StackForBraces.push(f);

            if (*dataIterator == 0)
            {
                auto startInstructionPtr = f;
                while (++f != instructions.end())
                {

                    if (*f == '[')
                        StackForBraces.push(f);
                    else if (*f == ']')
                    {
                        if (StackForBraces.empty())
                            throw std::runtime_error("Found a ']' that did not have a matching '['!");

                        auto tempInstructionPtr = StackForBraces.top();
                        StackForBraces.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (StackForBraces.empty())
                throw std::runtime_error("Found a ']' that did not have a matching '['!");

            if (*dataIterator != 0)
                f = StackForBraces.top();
            else
                StackForBraces.pop();

            break;
        }
        default:
            break;
        }
        f++;
    }

    if (!StackForBraces.empty())
        throw std::runtime_error("Found a '[' that did not have a matching ']'!");
}
