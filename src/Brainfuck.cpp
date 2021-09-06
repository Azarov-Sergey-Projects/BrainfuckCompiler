#include "BrainFuckMainClass.h"
#include "CInterpretator.h"
Brainfuck::Brainfuck()
{
    commandMap['>'] = IncrementPointer;
    commandMap['<'] = DecrementPointer;
    commandMap['+'] = IncrementData;
    commandMap['-'] = DecrementData;
    commandMap['.'] = WriteData;
    commandMap['['] = JumpForward;
    commandMap[']'] = JumpBackward;
}

Brainfuck::ParseError Brainfuck::parse(const std::string& code)
{
    std::vector<size_t> bracketStack;
    size_t matchingBracket;

    for (auto ch : code)
    {
        auto found = commandMap.find(ch);
        if (found != commandMap.end()) //the character is a valid brainfuck command
        {
            auto node = CommandNode(found->second);
            switch (node.command)
            {
            case JumpForward:
                commands.push_back(node); //add the command to the list
                bracketStack.push_back(commands.size() - 1); //push a pointer to this command on the bracket stack
                break;

            case JumpBackward:
                if (!bracketStack.size()) //empty bracket stack means bracket mismatch
                    return ErrorBracketMismatch;

                matchingBracket = bracketStack.back(); //pop the last element from the bracket stack
                bracketStack.pop_back();

                node.matchingBracket = matchingBracket; //update the closing bracket
                commands.push_back(node); //add the command to the list
                commands[matchingBracket].matchingBracket = commands.size() - 1; //update the opening bracket
                break;

            default:
                commands.push_back(node); //add the command to the list
                break;
            }
        }
        else
        {
            if (ch == '\n')
            {
                line++;
                column = 1;
            }
            else if (ch != '\r')
                column++;
            commands.push_back(CommandNode(Unknown)); //add an unknown (empty) command to the list
        }
    }
    return bracketStack.size() ? ErrorBracketMismatch : Success; //non-empty bracket stack means bracket mismatch
}

bool Brainfuck::execute(CInterpreter& semantics)
{
    auto commandCount = commands.size();
    if (!commands.size())
        return false;

    for (size_t currentCommand = 0; currentCommand < commandCount; currentCommand++)
    {
        unsigned char byte;
        switch (commands[currentCommand].command)
        {
        case Unknown: //unknown commands do nothing (this allows comments)
            break;

        case IncrementPointer:
            semantics.IncrementPointer();
            break;

        case DecrementPointer:
            semantics.DecrementPointer();
            break;

        case IncrementData:
            semantics.IncrementData();
            break;

        case DecrementData:
            semantics.DecrementData();
            break;

        case WriteData:
            semantics.WriteData();
            break;

        case JumpForward:
            if (semantics.TestZero())
                currentCommand = commands[currentCommand].matchingBracket;
            break;

        case JumpBackward:
            if (!semantics.TestZero())
                currentCommand = commands[currentCommand].matchingBracket;
            break;
        }
    }
    return true;
}

