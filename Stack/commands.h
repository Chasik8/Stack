#pragma once
namespace Dominus {
	class Begin {
	public:
		bool run(bool* begin_flag);
	};

	class End {
	public:
		bool run(bool* begin_flag);
	};

	//class Push {
	//public:
	//	template<typename Type>
	//	const bool run(Stack<Type>* stack, Type value);
	//};
	//class Begin {
	//public:
	//	const bool run(bool* begin_flag);
	//};
	//class Begin {
	//public:
	//	const bool run(bool* begin_flag);
	//};
	//class Begin {
	//public:
	//	const bool run(bool* begin_flag);
	//};

}
#include"commands.inl"