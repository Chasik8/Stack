#include"stack.h"
namespace Dominus {
	template<typename Type>
	Stack<Type>::Stack(vector<Type>& inpv) {
		arr = inpv;
	}
	template<typename Type>
	Stack<Type>::Stack(const Stack<Type>& inp) {
		arr = inp.arr;
	}
	template<typename Type>
	Stack<Type>::Stack() {
		arr = vector<Type>(0);
	}
	template<typename Type>
	Stack<Type>::Stack(const Stack<Type>&& inp) {
		arr = inp.arr;
	}
	template<typename Type>
	Stack<Type>& Stack<Type>::operator= (const Stack<Type>&& inp) {
		if (&inp != this) {
			arr = inp.arr;
		}
		return this;
	}
	template<typename Type>
	Stack<Type>::~Stack() {
		arr.clear();
	}
	template<typename Type>
	bool Stack<Type>::push(const Type inp) {
		try {
			arr.push_back(inp);
			return true;
		}
		catch (...){
			return false;
		}
	}
	template<typename Type>
	Stack<Type> Stack<Type>::pop() {
		if (arr.size() == 0) {
			return None;
		}
		return arr.pop_back();
	}
	template<typename Type>
	Stack<Type> Stack<Type>::top() {
		if (arr.size() == 0) {
			return None;
		}
		return arr[arr.size()-1];
	}
}
