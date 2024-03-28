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

    template<class Type>
    class Stack
    {
    private:
        Type* arr;
        long long int index;
        long long int len;
    public:
        explicit Stack(Type inpv) {
            arr = malloc(sizeof(Type));
            arr[0] = inpv;
            index = 1;
            len = 1;
        }
        Stack() {
            index = 0;
            len = 0;
        }
        Stack(const Stack<Type>& inp) {
            delete[] arr;
            arr = new Type[inp.len];
            for (long long int i = 0; i < inp.index; ++i) {
                arr[i] = inp.arr[i];
            }
            index = inp.index;
            len = inp.len;
        }
        Stack(const Stack<Type>&& inp);
        Stack<Type>* operator=(const Stack<Type>&& inp) {
            delete[] arr;
            arr = new Type[inp.len];
            for (long long int i = 0; i < inp.index; ++i) {
                arr[i] = inp.arr[i];
            }
            index = inp.index;
            len = inp.len;
        }
        Stack<Type>* operator=(const Stack<Type>& inp) {
            if (&inp != this) {
                delete[] arr;
                arr = new Type[inp.len];
                for (long long int i = 0; i < inp.index; ++i) {
                    arr[i] = inp.arr[i];
                }
                index = inp.index;
                len = inp.len;
                return this;
            }
            return this;
        }
        bool push(const Type inp) {
            if (len == 0) {
                arr = new Type[1];
                arr[0] = inp;
                len = 1;
                index = 1;
            }
            else if (index == len) {
                Type* arr_old = arr;
                arr = new Type[2 * len];
                for (long long int i = 0; i < index; ++i) {
                    arr[i] = arr_old[i];
                }
                delete[] arr_old;
                len *= 2;
                arr[index] = inp;
                ++index;
            }
            else {
                arr[index] = inp;
                ++index;
            }
            return true;
        }
        Type get(long long int i) {
            Type a = arr[i];
            return arr[i];
        }
        ~Stack() {
            delete arr;
            index = 0;
            len = 0;
        }
        Type pop() {
            if (index == 0) {
                return  *new Type;
            }
            --index;
            return arr[index];
        }
        Type top() {
            if (index == 0) {
                Type nul = *new Type;
                return nul;
            }
            return arr[index - 1];
        }
        bool print() {
            for (long long int i = 0; i < index; ++i) {
                if (arr[i].get_string_value() == "") {
                    cout << arr[i].get_int_value() << endl;
                }
                else {
                    cout << arr[i].get_string_value() << endl;
                }
            }
            return true;
        }
        bool clear() {
            delete[] arr;
            len = 0;
            index = 0;
            return true;
        }
        long long int get_index() {
            return index;
        }
    };
    template<typename Type>
    bool push(Stack<Type>& s, const Type& inp) {
        s.push(inp);
		return true;
    }
    template<typename Type>
    Type pop(const Stack<Type>& s) {
        return s.pop();
    }
}
