#pragma once
#include"stack.hpp"
//#include"cpu.h"
#include"memory.h"
namespace Dominus {
	struct Batch {
		bool* begin_flag;
		Stack<Memory>* stack;
		map<string, long long int>* stack_point;
		Memory* value;
		string* label;
	};
	class Commands {
	public:
		virtual long long int run(Batch& input) ;
	};

	class Begin: public Commands {
	public:
		long long int run(Batch& input) override;
	};
	class End:public Commands {
	public:
		long long int run(Batch& input) override;
	};
	class Push:public Commands {
	public:
		long long int run(Batch& input) override;
	};
	class Pop:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Add:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Label:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Out:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Jeq:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Jne:public Commands {
	public:
		long long int run(Batch& input)override;
	};
	class Del:public Commands {
	public:
		long long int run(Batch& input)override;
	};
}