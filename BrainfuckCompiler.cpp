// BrainfuckCompiler.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "CCompiler.h"


int main(int argc, char** agrv)
{
    std::string inputFileName;
    CCompiler interpretator;
    if (argc != 2)
    {
        std::cout << "Input File Name==HelloWorld.txt" << std::endl 
            << "Its Default File Name" << std::endl;
        inputFileName = "HelloWorld.txt";
    }
    else
    {
        try
        {
            inputFileName = agrv[1];
            interpretator.readInstructionsFromFile(inputFileName);
            interpretator.interpretFunctions();
        }
        catch (const std::exception& e)
        {
            std::cout << std::endl << e.what() << std::endl;
        }
    }
    return 0;
}


