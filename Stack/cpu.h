#pragma once
#include"stack.h"
#include <fstream>
#include<string>
#include"commands.h"
/*#include"memory.h"*/
namespace Dominus {
    class CPU {
    private:
        Stack<Memory> stack;
        map<std::string, long long int> stack_point;
        bool begin_flag;
        //map<string, Token> commands;
        Begin _begin;
        End _end;
        Push _push;
        Add _add;
        Pop _pop;
        Out _out;
        Label _label;
        Jeq _jeq;
    public:
        CPU();
        //~CPU();
        bool run();
        std::string input(ifstream& file);
        bool parser(string s);
    };
}