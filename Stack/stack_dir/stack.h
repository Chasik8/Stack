#pragma once
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<iostream>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<malloc.h>
#include<map>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<string>
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
        Type pop();
        Type top();
        bool print();
    };
    template<typename Type>
    bool push(const Stack<Type>& s, const Type& inp);
    template<typename Type>
    Type pop(const Stack<Type>& s);

}

#include"stack.ii"