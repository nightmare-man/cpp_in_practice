#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector() :size{ 0 }, space{ 0 }, mem{ nullptr } {};
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) },space{int(lst.size())}, mem{new double[size]} {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
		cout << "调用了列表初始化\n";
	};
	Myvector(int s) :size{ s },space{ s } ,mem{ new double[s] } {
		for (int i = 0; i < s; i++) mem[i] = 0;
		cout << "调用了初始化\n";
	}
	int Size()const { return size; };
	double get(int idx)const {
		if (idx < 0 || idx >= size) error("out of range\n");
		return mem[idx];
	};
	void set(int idx, double val) {
		if (idx < 0 || idx >= size) error("out of range\n");
		mem[idx] = val;
	}

	Myvector(const Myvector& arg) :size{ arg.size }, space{arg.size}, mem{ new double[size] } {
		std::copy(arg.mem, arg.mem + size, mem);
		cout << "调用了拷贝初始化\n";
	}

	Myvector(Myvector&& v)noexcept :size{ v.size }, space{v.space}, mem{ v.mem } {
		v.size = 0;
		v.mem = nullptr;
		cout << "调用了移动初始化\n";
	}

	Myvector& operator=(Myvector&& v)noexcept;

	Myvector& operator=(const Myvector& v);
	~Myvector() {
		delete[] mem;
	}
	int Capcity() const{
		return space;
	}
	//改变vector大小
	//space可能变大但不可能变小
	void resize(int newsize);
	void push_back(double d);
	double& operator[](int idx);
	const double& operator[](int idx)const;
private:
	int size;
	int space;
	double* mem;
	//重新分配空间
	void reserve(int newalloc) {
		if (newalloc <= space) return;
		double* p = new double[newalloc];
		std::copy(mem, mem + size, p);
		delete[] mem;
		mem = p;
		space = newalloc;
	}
};
double& Myvector::operator[](int idx) {
	if (idx < 0 || idx >= size) error("out of range");
	return mem[idx];
}
const double& Myvector::operator[](int idx)const {
	if (idx < 0 || idx >= size) error("out of range");
	return mem[idx];
}
void Myvector::push_back(double d) {
	if (space == 0) reserve(8);
	else if (size == space) reserve(space * 2);
	mem[size] = d;
	size++;
}
void Myvector::resize(int newsize) {
	reserve(newsize);
	//重新赋值0
	for (int i = 0; i < newsize; i++) mem[i] = 0;
	size = newsize;
}
Myvector& Myvector::operator=(Myvector&& v) noexcept {
	size = v.size;
	mem = v.mem;
	space = v.space;
	v.size = 0;
	v.mem = nullptr;
	v.space = 0;
	cout << "调用了移动赋值\n";
	return *this;
}
Myvector& Myvector::operator=(const Myvector& v) {
	//对引用也可以取指针，和引用的变量一样的地址
	if (this == &v)return *this;
	
	if (space < v.size) {
		double* p = new double[v.size];
		std::copy(v.mem, v.mem + v.size, p);
		delete[] mem;
		size = v.size;
		space = v.size;
		mem = p;
	}
	else {
		std::copy(v.mem, v.mem + v.size, mem);
		size = v.size;
	}
	cout << "调用了拷贝赋值\n";
	return *this;
}

Myvector f1() {
	Myvector res{ 1,2,3 };
	return res;
}
void f(Myvector v) {
	cout << v.Size();
}
int main() {
	Myvector v{1,2,3};
	v.push_back(4);
	v[3] = 10;
	Myvector v1{};
	v1 = v;
	for (int i = 0; i < v1.Size(); i++) {
		cout << v1[i] << endl;
	}
}