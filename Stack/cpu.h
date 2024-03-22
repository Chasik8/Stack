#pragma once
#include"stack.h"
#include <fstream>
#include<string>
#include"commands.h"
#include"memory.h"
namespace Dominus {
    class CPU {
    private:
        Stack<Memory> stack;
        Stack<long long int> stack_point;
        bool begin_flag;
        //map<string, Token> commands;
        Begin _begin;
        End _end;
        Push _push;
        Add _add;
        Pop _pop;
    public:
        CPU();
        //~CPU();
        bool run();
        std::string input(ifstream& file);
        bool parser(string s, ifstream& file);
    };
}
#include"cpu.inl"