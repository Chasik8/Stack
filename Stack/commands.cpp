#include "commands.h"
#include "cpu.h"
#include "memory.h"
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
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Jeq::run(Stack<Memory>& stack, map<string, long long int>& stack_point, string label) {
		try {
			Memory first = stack.pop();
			if (first.get_string_value() != "" && stack.top().get_string_value() != "") {
				if (first.get_int_value() == stack.pop().get_int_value()) {
					Memory a("JEQ " + label);
					stack.push(a);
					return stack_point[label];
				}
			}
			return stack.get_index();
		}
		catch (...) {
			return -1;
		}
	}
}