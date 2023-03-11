#include "../include/std_lib_facilities.h"
class Myvector {
public:
	Myvector(initializer_list<double> lst) :size{ int(lst.size()) }, mem{ new double[size] } {
		copy(lst.begin(), lst.end(), mem);
	};
	double get(int idx)const{
		return mem[idx];
	}
private:
	int size;
	double* mem;
};
int main() {
	//列表初始化容器initializer_list
	Myvector v{ 1,2,3,4,5 };
	cout << v.get(4);
}