#include "../include/std_lib_facilities.h"
class A {
public:
	A() { cout << "A construct\n"; }
	~A() { cout << "A destruct\n"; }
};
class B :A {
public:
	B() { cout << "B construct\n"; }
	~B() { cout << "B destruct\n"; }
};
class Myvector {
public:
	Myvector(int s) :size{ s }, mem{ new double[s] } {
		//初始化
		cout << "init\n";
		for (int i = 0; i < s; i++) mem[i] = 0;
	};
	~Myvector() { delete[] mem;};
	double get(int idx)const { return mem[idx]; };
	void set(int idx, double val) { mem[idx] = val; };
	int Size()const { return size; };

private:
	int size;
	double* mem;
};
double* calc(int res, int max) {
	//p用于局部使用，但是忘记释放
	double* p = new double[max];
	double* res1 = new double[res];
	delete[] p;
	//delete[]和new[]都会记录分配的数组大小
	//但是指针却不记录，是为了保持指针的灵活性通用性
	//因为指针不仅仅用来指向new分配的内存，也用来指向
	//栈 或者静态内存空间等，这个时候不知道数组大小
	return res1;
}
int main() {
	//定义变量初始化为10
	int y = 10;
	//没有新变量，但是有符号r引用了y
	int& r = y;
	//通过r引用 y变为7
	r = 7;
	//定义变量y2 通过r 引用y给y2赋值7；
	int y2 = r;
	
	int& r2 = y2;
	//通过r2引用y2 r引用y 赋值
	r2 = r;
	return 0;
}