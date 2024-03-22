#include"memory.h"
#include<string>
namespace Dominus{
	long long int Memory::get_int_value() {
		return int_value;
	}
	string Memory::get_string_value() {
		return string_value;
	}
	bool Memory::set_int_value(long long int value) {
		try {
			int_value = value;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	bool Memory::set_string_value(string value) {
		try {
			string_value = value;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	Memory::Memory(long long int dig = 0) {
		int_value = dig;
	}
	Memory::Memory(string str) {
		string_value = str;
	}
	Memory::Memory() {
		string_value = "";
		int_value = 0;
	}
}