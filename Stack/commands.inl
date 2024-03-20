#include"commands.h"
#include"stack.h"
//#include<pair.h>
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
	//template<typename Type>
	//const bool Push::run(Stack<Type>* stack,Type value) {
	//	stat->push(value);
	//}
	//const bool Begin::run(bool* begin_flag) {
	//	*begin_flag = true;
	//}
	//const bool Begin::run(bool* begin_flag) {
	//	*begin_flag = true;
	//}
	//const bool Begin::run(bool* begin_flag) {
	//	*begin_flag = true;
	//}
}