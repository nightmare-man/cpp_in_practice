#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) }, mem{ new double[size] } {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
	};
	Myvector(int s) :size{ s }, mem{new double[s]} {
		for (int i = 0; i < s; i++) mem[i] = 0;
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
	//拷贝构造函数
	//隐式类型转换 Myvector&arg->const Myvector&
	Myvector(const Myvector& arg) :size{ arg.size }, mem{new double[size]} {
		std::copy(arg.mem, arg.mem+size, mem);
	}
	//拷贝赋值
	Myvector& operator=(const Myvector& v);
	~Myvector() {
		delete[] mem;
	}
private:
	int size;
	double* mem;
};
Myvector& Myvector::operator=(const Myvector& v) {
	double* p = new double[v.size];
	std::copy(v.mem, v.mem + v.size, p);
	delete[] mem;
	mem = p;
	size = v.size;
	return *this;
}
/// <summary>
/// 函数返回对象，并用来赋值（拷贝赋值），该对象成为零时对象，复制
/// 会被销毁
/// </summary>
/// <returns></returns>
Myvector f1() {
	Myvector res{ 1,2,3 };
	return res;
}
int main() {
	Myvector v(3);

	Myvector v1(4);

	Myvector v2 = f1();
	cout << v2.get(1);
	return 0;
}