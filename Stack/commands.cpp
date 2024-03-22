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

	bool Push::run(Stack<Memory> stack, Memory value) {
		try {
			stack.push(value);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Pop::run(Stack<Memory> stack) {
		try {
			stack.pop();
			return true;
		}
		catch (...) {

			return false;
		}
	}
	bool Add::run(Stack<Memory> stack) {
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
	
}