#include "../include/std_lib_facilities.h"
namespace X {
	int var = 7;
	void print() {
		cout << var << endl;
	}
}
namespace Y {
	int var = 9;
	void print() {
		cout << var << endl;
	}
}
namespace Z {
	int var = 11;
	void print() {
		cout << var << endl;
	}
}
int main() {
	X::print();
	X::var = 8;
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 14;
		print();
	}
	print();
	X::print();
	return 0;
}