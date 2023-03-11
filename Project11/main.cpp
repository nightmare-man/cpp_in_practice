#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) }, mem{ new double[size] } {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
	};
	int Size()const { return size; };
	double get(int idx)const {
		if (idx < 0 || idx >= size) error("out of range\n");
		return mem[idx];
	};
	void set(int idx,double val){
		if (idx < 0 || idx >= size) error("out of range\n");
		mem[idx] = val;
	}
	//拷贝构造函数
	Myvector(const Myvector& arg) :size{ arg.size }, mem{new double[size]} {
		std::copy(arg.mem, arg.mem+size, mem);
	}
	~Myvector() {
		delete[] mem;
	}
private:
	int size;
	double* mem;
};
int main() {
	Myvector v1{ 1,2,3,4,5 };
	Myvector v2 = v1;
	cout << v2.get(3);
	return 0;
}