// BrainfuckCompiler.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "CCompiler.h"


int main(int argc, char** agrv)
{
    std::string inputCommands;
    CCompiler interpretator;
    try
    {
        if (argc != 2)
        {
            std::cout << "Type instructions" << std::endl;
            std::cin >> inputCommands;
            interpretator.setInstructions(inputCommands);
        }
        else
        {
            interpretator.readInstructionsFromFile(agrv[1]);
        }
        std::cout << "After interpretating:" << std::endl<<std::endl;
        interpretator.compileInstructions();
    }
    catch (const std::exception& e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }
    return 0;
}


