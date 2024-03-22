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
	bool Dominus::Push::run(Stack<Memory> stack, Memory value) {
		try {
			stack.push(value);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	namespace Dominus {
	class Pop {
	public:
		Memory run(Stack<Memory> stack) {
			try {
				return stack.pop();
			}
			catch (...) {

				return *new Memory;
			}
		}
	};
	class Add {
	public:
		bool run(Stack<Memory> stack) {
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
	};
}