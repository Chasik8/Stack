#include"commands.h"
#include"stack.h"
namespace Dominus {
	class Begin {
	public:
		bool run(bool* begin_flag) {
			try {
				*begin_flag = true;
				return true;
			}
			catch (...) {
				return false;
			}
		}
	};
	class End {
	public:
		bool run(bool* begin_flag) {
			try {
				*begin_flag = false;
				return true;
			}
			catch (...) {
				return false;
			}
		}
	};
	//bool Push::run(Stack<Memory> stack, Memory value) {
	//	try {
	//		stack.push(value);
	//		return true;
	//	}
	//	catch (...) {
	//		return false;
	//	}
	//}
	
	//class Push {
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
	//class Pop {
	//public:
	//	Memory run(Stack<Memory> stack) {
	//		try {
	//			return stack.pop();
	//		}
	//		catch (...) {
	//			
	//			return *new Memory;
	//		}
	//	}
	//};
	//class Add {
	//public:
	//	bool run(Stack<Memory> stack) {
	//		try {
	//			Memory first = stack.pop();
	//			Memory second = stack.top();
	//			stack.push(first);
	//			stack.push( *new Memory(first.get_int_value() + second.get_int_value()));
	//			return true;
	//		}
	//		catch (...) {

	//			return false;
	//		}
	//	}
	//};
}