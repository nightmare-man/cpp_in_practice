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
	double& operator[](int n) { 
		if (n < 0 || n >= size) error("out of range");
		return mem[n]; 
	}
	//适用于const的Myvector对象使用[]
	double operator[](int n) const {
		if (n < 0 || n >= size) error("out of range");
		return mem[n];
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
void f(const Myvector& v) {
	//调用了const版本的[]
	double d = v[1];
	cout << d;
}
int main() {
	int a[20];
	int b = 0;
	a = &b;
	Myvector v(3);

	Myvector v1(4);
	v[1] = 2;
	f(v);
	return 0;
}