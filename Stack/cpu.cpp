#include"stack.hpp"
#include"cpu.h"
#include <fstream>
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include<string>

namespace Dominus {
	CPU::CPU() {
		begin_flag = false;
		stack = *new Stack<Memory>;
		stack_point = *new map<std::string,long long int>;
		commands = {
			{"_begin", make_shared<Begin>()},
			{"_end", make_shared<End>()},
			{"_push", make_shared<Push>()},
			{"_add", make_shared<Add>()},
			{"_pop", make_shared<Pop>()},
			{"_out", make_shared<Out>()},
			{"_label", make_shared<Label>()},
			{"_jeq", make_shared<Jeq>()},
			{"_jne", make_shared<Jne>()},
			{"_del", make_shared<Del>()},

		};
		batch = {
			&begin_flag,
			&stack,
			&stack_point
		};
	}
	CPU::~CPU() {
		delete &stack;
		delete& stack_point;
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
			commands["_begin"]->run(batch);
		}
		else if (s == "END") {
			commands["_end"]->run(batch);
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
				batch.value = &value;
				commands["_push"]->run(batch);
			}
			else if (s == "POP") {
				commands["_pop"] -> run(batch);
			}
			else if (s == "ADD") {
				commands["_add"]->run(batch);
			}
			else if (s == "LABEL") {
				string str = split(input, 1);
				batch.label = &str;
				commands["_label"]->run(batch);
			}
			else if (s == "OUT") {
				commands["_out"]->run(batch);
			}
			else if (s == "DEL") {
				commands["_del"]->run(batch);
			}
			else if (s == "JEQ"||s=="JNE") {
				string str_label = split(input, 1);
				while (true)
				{
					long long int pos = stack.get_index();
					//stack.print();
					long long int iter=-1;
					batch.label = &str_label;
					if (s == "JEQ") {
						iter= commands["_jeq"]->run(batch);
					}else if (s == "JNE"){
						iter= commands["_jne"]->run(batch);
					}
					if (iter == -1) {
						break;
					}
					string str;
					for (;iter < pos; ++iter) {
						if (stack.get(iter).get_string_value() == "") {
							str = "PUSH int " + to_string(stack.get(iter).get_int_value());
						}
						else {
							str = stack.get(iter).get_string_value();
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