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
	long long int Commands::run(Batch& input) {
		return 1;
	}
	long long int Begin::run(Batch& input) {
		try {
			*input.begin_flag = true;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int End::run(Batch& input) {
		try {
			*input.begin_flag = false;
			return true;
		}
		catch (...) {
			return false;
		}
	}

	long long int Push::run(Batch& input) {
		try {
			(*input.stack).push(*input.value);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Pop::run(Batch& input) {
		try {
			(*input.stack).pop();
			Memory add("POP");
			(*input.stack).push(add);
			return true;
		}
		catch (...) {

			return false;
		}
	}
	long long int Add::run(Batch& input) {
		try {
			Memory first = (*input.stack).pop();
			Memory second = (*input.stack).top();
			(*input.stack).push(first);
			(*input.stack).push(*new Memory(first.get_int_value() + second.get_int_value()));
			Memory add("ADD");
			(*input.stack).push(add);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Label::run(Batch& input) {
		try {
			(*input.stack_point)[*input.label]= (*input.stack).get_index();
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Out::run(Batch& input) {
		try {
			if ((*input.stack).top().get_string_value() != "") {
				std::cout << (*input.stack).pop().get_string_value() << std::endl;
			}
			else {
				std::cout << (*input.stack).pop().get_int_value() << std::endl;
			}
			//Memory add("OUT");
			//stack.push(add);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Del::run(Batch& input) {
		try {
			(*input.stack).pop();
			return true;
		}
		catch (...) {
			return false;
		}
	}
	long long int Jeq::run(Batch& input) {
		try {
			long long int index_search = (*input.stack).get_index()-1;
			Memory first;
			for (;; --index_search) {
				first = (*input.stack).get(index_search);
				if ((*input.stack).get(index_search).get_string_value() == "") {
					break;
				}
			}
			--index_search;
			Memory second;
			for (;; --index_search) {
				second = (*input.stack).get(index_search);
				if ((*input.stack).get(index_search).get_string_value() == "") {
					break;
				}
			}
			if (first.get_string_value() == "" && second.get_string_value() == "") {
				if (first.get_int_value() == second.get_int_value()) {
					//Memory add("JEQ " + label);
					//stack.push(add);
					return (*input.stack_point)[*input.label];
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
	long long int Jne::run(Batch& input) {
		try {
			long long int index_search = (*input.stack).get_index() - 1;
			Memory first;
			for (; index_search >= 0; --index_search) {
				first = (*input.stack).get(index_search);
				if ((*input.stack).get(index_search).get_string_value() == "") {
					break;
				}
			}
			--index_search;
			Memory second;
			for (; index_search>=0; --index_search) {
				second = (*input.stack).get(index_search);
				if ((*input.stack).get(index_search).get_string_value() == "") {
					break;
				}
			}
			if (first.get_string_value() == "" && second.get_string_value() == "") {
				if (first.get_int_value() != second.get_int_value()) {
					//Memory add("JEQ " + label);
					//stack.push(add);
					return (*input.stack_point)[*input.label];
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