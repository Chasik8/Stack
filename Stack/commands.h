#pragma once
#include"stack.h"
//#include"cpu.h"
#include"memory.h"
namespace Dominus {
	//class Element {
	//public:
	//	virtual void print() const = 0;
	//	virtual ~Element() {}
	//};
	//enum class TokenType {
	//	Begin,
	//	End,
	//};

	//class Token {
	//private:
	//	std::string value;
	//	TokenType type;
	//public:
	//	Token(TokenType type, Element* element) : type(type), element(element) {}
	//};

	class Begin {
	public:
		bool run(bool* begin_flag);
	};
	class End {
	public:
		bool run(bool* begin_flag);
	};
	class Push {
	public:
		bool run(Stack<Memory>& stack, Memory value) ;
	};
	class Pop {
	public:
		bool run(Stack<Memory> &stack);
	};
	class Add {
	public:
		bool run(Stack<Memory>& stack);
	};
	class Label {
	public:
		bool run(Stack<Memory>& stack, map<string,long long int>& stack_point, string label);
	};
	class Out {
	public:
		bool run(Stack<Memory>& stack);
	};
	class Jeq {
	public:
		long long int run(Stack<Memory>& stack, map<string, long long int>& stack_point, string label);
	};
	class Jne {
	public:
		long long int run(Stack<Memory>& stack, map<string, long long int>& stack_point, string label);
	};
}