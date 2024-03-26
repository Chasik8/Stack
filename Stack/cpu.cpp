#include"stack.h"
#include"cpu.h"
#include <fstream>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<string>

namespace Dominus {
	CPU::CPU() {
		begin_flag = false;
		stack = *new Stack<Memory>;
		stack_point = *new map<std::string,long long int>;
		_begin = *new Begin;
		_end = *new End;
		_push = *new Push;
		_add = *new Add;
		_out = *new Out;
		_jeq = *new Jeq;
		//commands = {
		//	{"BEGIN",new Token(TokenType::Begin,new Begin)}
		//}
	}
	string CPU::input(ifstream& file) {
		string str;

		char symbol = file.get();
		while (symbol != '\n')
		{
			str += symbol;
			symbol = file.get();
		}
		return str;
	}
	string split(string str, long long int kol) {
		string ans = "";
		for (long long int i = 0, space = 0; i < str.size(); ++i) {
			bool flag = false;
			if (str[i] == ' ') {
				++space;
				flag = true;
			}
			if (space == kol) {
				return ans;
			}
			if (flag) {
				ans = "";
			}
			else {
				ans += str[i];
			}
		}
	}
	bool CPU::parser(string s) {
		string input = split(s, 0);
		if (s == "BEGIN") {
			_begin.run(&begin_flag);
		}
		else if (s == "END") {
			_end.run(&begin_flag);
		}
		else if (begin_flag) {
			if (s == "PUSH") {
				string typ = split(s, 1);
				Memory value;
				string str = split(s, 2);
				if (typ == "int") {
					long long int dig = atoi(str.c_str());
					value.set_int_value(dig);
				}
				else {
					value.set_string_value(str);
				}
				_push.run(stack, value);
			}
			else if (s == "POP") {
				_pop.run(stack);
			}
			else if (s == "ADD") {
				_add.run(stack);
			}
			else if (s == "LABEL") {
				string str = split(s, 1);
				_label.run(stack,stack_point, str);
			}
			else if (s == "OUT") {
				_out.run(stack);
			}
		}
		return true;
	}
	bool CPU::run() {
		string inp="input.txt";
		//cin >> inp;
		ifstream file(inp);
		string key = "";
		while (key != "END")
		{
			string key = input(file);
			parser(key);
		}
		return true;
	}
}