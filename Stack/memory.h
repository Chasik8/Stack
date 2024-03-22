#pragma once
#include<string>
namespace Dominus {
    class Memory {
    private:
        long long int int_value;
        string string_value;
    public:
        Memory();
        explicit Memory(string str);
        explicit Memory(long long int dig);
        string get_string_value();
        long long int get_int_value();
        bool set_string_value(string value);
        bool set_int_value(long long int value);
    };
}