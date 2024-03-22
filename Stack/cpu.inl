//#include"stack.h"
//#include"cpu.h"
//#include <fstream>
//#define _CRT_DISABLE_PERFCRIT_LOCKS
//#include<string>
//
//namespace Dominus {
//	CPU::CPU() {
//		begin_flag = false;
//		stack = *new Stack<Memory>;
//		stack_point=*new Stack<long long int>;
//		_begin = *new Begin;
//		_end = *new End;
//		_push = *new Push;
//		_add = *new Add;
//		//commands = {
//		//	{"BEGIN",new Token(TokenType::Begin,new Begin)}
//		//}
//	}
//	string CPU::input(ifstream& file) {
//		string str;
//
//		char symbol = file.get();
//		while (symbol != ' ' && symbol != '\n')
//		{
//			str += symbol;
//			symbol = file.get();
//		}
//		return str;
//	}
//	bool CPU::parser(string s, ifstream& file) {
//		if (s == "BEGIN") {
//			_begin.run(&begin_flag);
//		}
//		else if (s == "END") {
//			_end.run(&begin_flag);
//		}
//		else if (s == "PUSH") {
//			string typ=input(file);
//			Memory value;
//			string str = input(file);
//			if (typ == "int"){
//				long long int dig = atoi(typ.c_str());
//				value.set_int_value(dig);
//			}
//			else {
//				value.set_string_value(str);
//			}
//			_push.run(stack,value);
//		}
//		else if (s == "POP") {
//			_pop.run(stack);
//		}
//		else if (s == "ADD") {
//			_add.run(stack);
//		}
//
//	}
//	bool CPU::run() {
//		string inp;
//		cin >> inp;
//		ifstream file(inp);
//		string key="";
//		while (key!="END")
//		{
//			string key = input(file);
//			parser(key,file);
//		}
//		return true;
//	}
//}