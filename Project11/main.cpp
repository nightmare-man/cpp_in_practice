#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) }, mem{ new double[size] } {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
		cout << "调用了列表初始化\n";
	};
	Myvector(int s) :size{ s }, mem{new double[s]} {
		for (int i = 0; i < s; i++) mem[i] = 0;
		cout << "调用了初始化\n";
	}
	int Size()const { return size; };
	double get(int idx)const {
		if (idx < 0 || idx >= size) error("out of range\n");
		return mem[idx];
	};
	void set(int idx,double val){
		if (idx < 0 || idx >= size) error("out of range\n");
		mem[idx] = val;
	}
	
	Myvector(const Myvector& arg) :size{ arg.size }, mem{new double[size]} {
		std::copy(arg.mem, arg.mem+size, mem);
		cout << "调用了拷贝初始化\n";
	}

	Myvector(Myvector&& v)noexcept :size{ v.size }, mem{v.mem} {
		v.size = 0;
		v.mem = nullptr;
		cout << "调用了移动初始化\n";
	}
	
	Myvector& operator=(Myvector&& v)noexcept;
	
	Myvector& operator=(const Myvector& v);
	~Myvector() {
		delete[] mem;
	}
private:
	int size;
	double* mem;
};
Myvector& Myvector::operator=(Myvector&& v) noexcept{
	size = v.size;
	mem = v.mem;
	v.size = 0;
	v.mem = nullptr;
	cout << "调用了移动赋值\n";
	return *this;
}
Myvector& Myvector::operator=(const Myvector& v) {
	double* p = new double[v.size];
	std::copy(v.mem, v.mem + v.size, p);
	delete[] mem;
	mem = p;
	size = v.size;
	cout << "调用了拷贝赋值\n";
	return *this;
}

Myvector f1() {
	Myvector res{ 1,2,3 };
	return res;
}
int main() {
	Myvector v(3);

	Myvector v1(4);
	//编译器进行了优化，没有调用移动构造
	//而是直接把返回的右值对象改成左值成为了v2
	Myvector v2 = f1();
	return 0;
}