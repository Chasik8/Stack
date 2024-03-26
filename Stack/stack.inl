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
		delete[] arr;
		arr = new Type[inp.len];
		for (long long int i = 0; i < inp.index; ++i) {
			arr[i] = inp.arr[i];
		}
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
		delete[] arr;
		arr = new Type[inp.len];
		for (long long int i = 0; i < inp.index; ++i) {
			arr[i] = inp.arr[i];
		}
		index = inp.index;
		len = inp.len;
	}
	template<typename Type>
	Stack<Type>* Stack<Type>::operator= (const Stack<Type>&& inp) {
		if (&inp != this) {
			delete[] arr;
			arr = new Type[inp.len];
			for (long long int i = 0; i < inp.index; ++i) {
				arr[i] = inp.arr[i];
			}
			index = inp.index;
			len = inp.len;
			return  this;
		}
		return this;
	}
	template<typename Type>
	Stack<Type>* Stack<Type>::operator= (const Stack<Type>& inp) {
		if (&inp != this) {
			delete[] arr;
			arr = new Type[inp.len];
			for (long long int i = 0; i < inp.index; ++i) {
				arr[i] = inp.arr[i];
			}
			index = inp.index;
			len = inp.len;
			return this;
		}
		return this;
	}
	template<typename Type>
	Stack<Type>::~Stack() {
		delete arr;
		index = 0;
		len = 0;
	}
	template<typename Type>
	bool Stack<Type>::push(const Type inp) {
		try {
			if (len == 0) {
				arr = new Type[1];
				arr[0] = inp;
				len = 1;
				index = 1;
			}
			else if (index == len) {
				Type* arr_old = arr;
				arr = new Type[2 * len];
				for (long long int i = 0; i < index; ++i) {
					arr[i] = arr_old[i];
				}
				delete[] arr_old;
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
		catch(...) {
			return false;
		}
	}
	template<typename Type>
	bool push(Stack<Type>& s, const Type inp) {
		try {
			s.push(inp);
			return true;
		}
		catch (...) {
			return false;
		}
	}
	template<typename Type>
	Type Stack<Type>::pop() {
		if (index == 0) {
			return  *new Type;
		}
		--index;
		return arr[index];
	}
	template<typename Type>
	Type pop(const Stack<Type>& s) {
		return s.pop();
	}
	template<typename Type>
	Type Stack<Type>::top() {
		if (index == 0) {
			Type nul = *new Type;
			return nul;
		}
		return arr[index-1];
	}
	template<typename Type>
	bool Stack<Type>::print() {
		try {
			for (long long int i = 0; i < index; ++i) {
				if (arr[i].get_string_value() == "") {
					cout << arr[i].get_int_value() << endl;
				}
				else {
					cout << arr[i].get_string_value() << endl;
				}
			}
			return true;
		}
		catch (...) {
			return false;
		}
	}
	template<typename Type>
	bool Stack<Type>::clear() {
		try {
			delete[] arr;
			len = 0;
			index = 0;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	template<typename Type>
	long long int Stack<Type>::get_index() {
		return index;
	}
	template<typename Type>
	Type Stack<Type>::operator[](long long int i) {
		try {
			Type a= arr[i];
			return arr[i];
		}
		catch (...) {
			return *new Type;
		}
	}
}
