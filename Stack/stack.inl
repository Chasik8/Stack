#include"stack.h"
namespace Dominus {
	template<typename Type>
	Stack<Type>::Stack(Type inpv) {
		arr = malloc(sizeof(Type));
		arr[0] = inpv;
		index = 1;
		len = 1;
	}
	template<typename Type>
	Stack<Type>::Stack(const Stack<Type>& inp) {
		arr = inp.arr;
		index = inp.index;
		len = inp.len;
	}
	template<typename Type>
	Stack<Type>::Stack() {
		index = 0;
		len = 0;
	}
	template<typename Type>
	Stack<Type>::Stack(const Stack<Type>&& inp) {
		arr = inp.arr;
		index = inp.index;
		len = inp.len;
	}
	template<typename Type>
	bool Stack<Type>::operator= (const Stack<Type>&& inp) {
		if (&inp != this) {
			arr = inp.arr;
			index = inp.index;
			len = inp.len;
			return true;
		}
		return false;
	}
	template<typename Type>
	bool Stack<Type>::operator= (const Stack<Type>& inp) {
		if (&inp != this) {
			arr = inp.arr;
			index = inp.index;
			len = inp.len;
			return true;
		}
		return false;
	}
	template<typename Type>
	Stack<Type>::~Stack() {
		//free(arr);
		index = 0;
		len = 0;
	}
	template<typename Type>
	bool Stack<Type>::push(const Type inp) {
		try {
			if (len == 0) {
				arr = (Type*)malloc(sizeof(Type));
				arr[0] = inp;
				len = 1;
				index = 1;
			}
			else if (index == len) {
				realloc(arr,2 * len);
				len *= 2;
				arr[index] = inp;
				++index;
			}
			else {
				arr[index] = inp;
				++index;
			}
			return true;
		}
		catch (...){
			return false;
		}
	}
	template<typename Type>
	bool push(const Stack<Type>& s, const Type inp) {
		try {
			s.push(inp);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	template<typename Type>
	Stack<Type> Stack<Type>::pop() {
		if (index == 0) {
			return NULL;
		}
		--index;
		return arr[index];
	}
	template<typename Type>
	Stack<Type> pop(const Stack<Type>& s) {
		s.pop();
		return true;
	}
	template<typename Type>
	Stack<Type> Stack<Type>::top() {
		if (index == 0) {
			return NULL;
		}
		return arr[index-1];
	}
	template<typename Type>
	bool Stack<Type>::print() {
		try {
			for (long long int i = 0; i < index; ++i) {
				cout << arr[i] << " ";
			}
			return true;
		}
		catch (...) {
			return false;
		}
	}
}
