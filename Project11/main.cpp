#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) }, mem{ new double[size] } {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
	};
	double get(int idx)const {
		if (idx < 0 || idx >= size) error("out of range\n");
		return mem[idx];
	};
	void set(int idx,double val){
		if (idx < 0 || idx >= size) error("out of range\n");
		mem[idx] = val;
	}
	~Myvector() {
		delete[] mem;
	}
private:
	int size;
	double* mem;
};
class Aaa {
public:
	int val1;
	//引用也可以作为成员变量
	int& val2;
	Aaa(int a, int& b) :val1{ a }, val2{ b } {};
};
int main() {
	int a = 10;
	Aaa a1{a,a};

}