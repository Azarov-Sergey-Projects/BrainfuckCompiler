// BrainfuckCompiler.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "BrainFuckMainClass.h"
#include "CInterpretator.h"

static bool readFile(const std::string& filename, std::string& contents)
{
    std::ifstream file(filename);
    if (!file.is_open())
        return false;
    std::string str;
    while (std::getline(file, str))
        contents += str + "\n";
    file.close();
    return true;
}

int main(int argc, char* argv[])
{
    std::string code;

    if (argc < 2)
    {
        std::cout << "Type commands" << std::endl;
        std::cin >> code;
    }
    else
    {
        if (!readFile(argv[1], code))
        {
            std::cout << "failed to read input file!" << std::endl;
            return -1;
        }
    }

    Brainfuck brainfuck;
    auto error = brainfuck.parse(code);
    if (error != Brainfuck::Success)
    {
        std::cout << "Error while trying to parse code" << std::endl;
    }
    CInterpreter interpretator;
    if (brainfuck.execute(interpretator) != true)
    {
        std::cout << "Error while executing code" << std::endl;
    }
    return 0;
}



