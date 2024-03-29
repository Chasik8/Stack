#pragma once
#include"stack.hpp"
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
        map<string,shared_ptr< Commands>> commands;
        Batch batch;
    public:
        CPU();
        ~CPU();
        bool run();
        std::string input(ifstream& file);
        bool parser(string s);
    };
}