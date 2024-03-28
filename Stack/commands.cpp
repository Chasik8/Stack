#include "commands.h"
#include "cpu.h"
#include "memory.h"
#include "stack.hpp"
	//class Dominus::Push {
	//public:
	//	bool run(Stack<Memory> stack, Memory value) {
	//		try {
	//			stack.push(value);
	//			return true;
	//		}
	//		catch (...) {
	//			return false;
	//		}
	//	}
	//};
namespace Dominus {
	bool Begin::run(bool* begin_flag) {
		try {
			*begin_flag = true;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool End::run(bool* begin_flag) {
		try {
			*begin_flag = false;
			return true;
		}
		catch (...) {
			return false;
		}
	}

	bool Push::run(Stack<Memory>& stack, Memory value) {
		try {
			stack.push(value);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Pop::run(Stack<Memory>& stack) {
		try {
			stack.pop();
			Memory add("POP");
			stack.push(add);
			return true;
		}
		catch (...) {

			return false;
		}
	}
	bool Add::run(Stack<Memory>& stack) {
		try {
			Memory first = stack.pop();
			Memory second = stack.top();
			stack.push(first);
			stack.push(*new Memory(first.get_int_value() + second.get_int_value()));
			Memory add("ADD");
			stack.push(add);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Label::run(Stack<Memory>& stack, map<string, long long int>& stack_point,string label) {
		try {
			stack_point[label]= stack.get_index();
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Out::run(Stack<Memory>& stack) {
		try {
			if (stack.top().get_string_value() != "") {
				std::cout << stack.pop().get_string_value() << std::endl;
			}
			else {
				std::cout << stack.pop().get_int_value() << std::endl;
			}
			//Memory add("OUT");
			//stack.push(add);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Del::run(Stack<Memory>& stack) {
		try {
			stack.pop();
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Jeq::run(Stack<Memory>& stack, map<string, long long int>& stack_point, string label) {
		try {
			long long int index_search = stack.get_index()-1;
			Memory first;
			for (;; --index_search) {
				first = stack.get(index_search);
				if (stack.get(index_search).get_string_value() == "") {
					break;
				}
			}
			--index_search;
			Memory second;
			for (;; --index_search) {
				second = stack.get(index_search);
				if (stack.get(index_search).get_string_value() == "") {
					break;
				}
			}
			if (first.get_string_value() == "" && second.get_string_value() == "") {
				if (first.get_int_value() == second.get_int_value()) {
					//Memory add("JEQ " + label);
					//stack.push(add);
					return stack_point[label];
				}
				else {
					return -1;
				}
			}
			else {
				cout << "exit" << endl;
			}
		}
		catch (...) {
			return -1;
		}
	}
	long long int Jne::run(Stack<Memory>& stack, map<string, long long int>& stack_point, string label) {
		try {
			long long int index_search = stack.get_index() - 1;
			Memory first;
			for (; index_search >= 0; --index_search) {
				first = stack.get(index_search);
				if (stack.get(index_search).get_string_value() == "") {
					break;
				}
			}
			--index_search;
			Memory second;
			for (; index_search>=0; --index_search) {
				second = stack.get(index_search);
				if (stack.get(index_search).get_string_value() == "") {
					break;
				}
			}
			if (first.get_string_value() == "" && second.get_string_value() == "") {
				if (first.get_int_value() != second.get_int_value()) {
					//Memory add("JEQ " + label);
					//stack.push(add);
					return stack_point[label];
				}
				else {
					return -1;
				}
			}
			else {
				cout << "exit" << endl;
			}
		}
		catch (...) {
			return -1;
		}
	}
}