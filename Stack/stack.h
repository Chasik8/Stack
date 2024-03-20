#pragma once
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<iostream>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<malloc.h>
#include<map>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<string>
#include"commands.h"
using namespace std;
namespace Dominus {
    template<typename Type>
    class Stack
    {
    private:
        Type* arr;
        long long int index;
        long long int len;
    public:
        explicit Stack(Type inpv);
        Stack();
        Stack(const Stack<Type>& inp);
        Stack(const Stack<Type>&& inp);
        bool operator=(const Stack<Type>&& inp);
        bool operator=(const Stack<Type>& inp);
        ~Stack();
        bool push(const Type inp);
        Stack pop();
        Stack top();
        bool print();
    };
    template<typename Type>
    bool push(const Stack<Type>& s, const Type& inp);
    template<typename Type>
    bool pop(const Stack<Type>& s);
    template<typename Type>
    class CPU {
    private:
        Stack<string> stack;
        Stack<long long int> stack_point;
        map<string, Type*> commands;
        bool begin_flag;
    public:
        CPU();
        ~CPU();
        bool run();
        bool input();
    };
}
#include"stack.inl"
#include"cpu.inl"