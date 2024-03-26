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
		_jne = *new Jne;
		_del = *new Del;
		//commands = {
		//	{"BEGIN",new Token(TokenType::Begin,new Begin)}
		//}
	}
	CPU::~CPU() {
		delete &stack;
		delete& stack_point;
		delete& _begin;
		delete& _end;
		delete& _push;
		delete& _add;
		delete& _pop;
		delete& _out;
		delete& _label;
		delete& _jeq;
		delete& _jne;
		delete& _del;
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
		for (long long int i = 0, space = -1; i < str.size(); ++i) {
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
	bool CPU::parser(string input) {
		string s = split(input, 0);
		if (s == "BEGIN") {
			_begin.run(&begin_flag);
		}
		else if (s == "END") {
			_end.run(&begin_flag);
		}
		else if (begin_flag) {
			if (s == "PUSH") {
				string typ = split(input, 1);
				Memory value;
				string str = split(input, 2);
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
				string str = split(input, 1);
				_label.run(stack,stack_point, str);
			}
			else if (s == "OUT") {
				_out.run(stack);
			}
			else if (s == "DEL") {
				_del.run(stack);
			}
			else if (s == "JEQ"||s=="JNE") {
				string str_label = split(input, 1);
				while (true)
				{
					long long int pos = stack.get_index();
					//stack.print();
					long long int iter=-1;
					if (s == "JEQ") {
						iter=_jeq.run(stack, stack_point, str_label);
					}else if (s == "JNE"){
						iter=_jne.run(stack, stack_point, str_label);
					}
					if (iter == -1) {
						break;
					}
					string str;
					for (;iter < pos; ++iter) {
						if (stack[iter].get_string_value() == "") {
							str = "PUSH int " + to_string(stack[iter].get_int_value());
						}
						else {
							str = stack[iter].get_string_value();
						}
						parser(str);
						//stack.print();
					}
					stack_point[str_label] = pos-1;
				}
			}
		}
		return true;
	}
	bool CPU::run() {
		string inp;
		cin >> inp;
		ifstream file(inp);
		string key = "";
		while (key != "END")
		{
			key = input(file);
			parser(key);
		}
		return true;
	}
}