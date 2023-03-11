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
int main() {
	//列表初始化容器initializer_list
	Myvector v{ 1,2,3,4,5 };
	Myvector v2{ 0,0,0,0,0 };
	//析构函数会报错，原因是浅拷贝，导致v原来分配的内存
	//被释放两次 而v2原来的的没释放
	cout << v2.get(4);
}