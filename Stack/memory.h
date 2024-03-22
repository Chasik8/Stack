#pragma once
#include <string>
namespace Dominus {
    class Memory {
    private:
        long long int int_value;
        std::string string_value;
    public:
        Memory();
        explicit Memory(std::string str);
        explicit Memory(long long int dig);
        std::string get_string_value();
        long long int get_int_value();
        bool set_string_value(std::string value);
        bool set_int_value(long long int value);
    };
}