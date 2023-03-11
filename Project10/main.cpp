#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(int s) :size{ s }, mem{ new double[s] } {
		//初始化
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
	Myvector d{ 5 };
	cout << d.Size()<<endl;
	cout << "d[0]" << d.get(0) << endl;
	d.set(0, 10);
	cout << "d[0]" << d.get(0) << endl;
	return 0;
}