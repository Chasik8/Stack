#include"stack.h"
#include"commands.h"
#include <fstream>
namespace Dominus {
	template<typename Type>
	CPU<Type>::CPU() {
		begin_flag = false;
		commands = {
			{"BEGIN",Begin}
		};
	}
	template<typename Type>
	bool CPU<Type>::input() {


	}
	template<typename Type>
	bool CPU<Type>::run() {
		string inp;
		cin >> inp;
		ifstream file(inp);
		string key="";
		while (key!="END")
		{
			string key = input();
			commands[key].run();
		}
	}
	string input(ifstream file) {
		string str;

		char symbol=file.get();
		while (symbol!=' '|| symbol != '\n')
		{
			str += symbol;
		}
		return str;
	}
}