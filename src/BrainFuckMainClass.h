#pragma once
#include <unordered_map>
#include <iostream>
#include "CCompiler.h"
#include "CInterpretator.h"

class Brainfuck
{
public:
    enum ParseError
    {
        Success,
        ErrorBracketMismatch,
        GenericError
    };
    Brainfuck();
    ParseError parse(const std::string& code);
    bool execute(CInterpreter& semantics);
private:
    enum Command
    {
        Unknown,
        IncrementPointer,
        DecrementPointer,
        IncrementData,
        DecrementData,
        WriteData,
        JumpForward,
        JumpBackward
    };

    struct CommandNode
    {
        CommandNode(Command command)
            : command(command),
            matchingBracket(-1)
        {
        }

        size_t matchingBracket;
        Command command;
    };

    std::vector<CommandNode> commands;
    std::unordered_map<char, Command> commandMap;
    int line = 1;
    int column = 1;
};