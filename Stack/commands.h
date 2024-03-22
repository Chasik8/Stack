#pragma once
#include"stack.h"
#include"cpu.h"
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

	class Begin;
	class End;
	class Push {
	public:
		bool run(Stack<Memory> stack, Memory value) ;
	};
	class Pop;
	class Add;

}
#include"commands.inl"