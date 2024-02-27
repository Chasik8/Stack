#pragma once
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<iostream>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<vector>
using namespace std;

namespace Dominus {
    template<typename Type>
    class Stack
    {
    private:
        vector<Type> arr;
    public:
        explicit Stack(vector<Type>& inpv);
        Stack();
        Stack(const Stack<Type>& inp);
        Stack(const Stack<Type>&& inp);
        Stack& operator=(const Stack<Type>&& inp);
        ~Stack();
        bool push(const Type inp);
        Stack pop();
        Stack top();
        //void print();
    };
}
#include"stack.inl"