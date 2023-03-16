#include "../include/std_lib_facilities.h"
template<typename it,typename T>
T accumulate1(it start,it end,T init){
	while (start != end) {
		init += *start;
		start++;
	} 
	return init;
}
//使用函数对象或者lambda生成匿名函数对象 进一步泛化
template<typename it,typename T,typename OP>
T accumulate1(it start, it end, T init, OP op) {
	while (start != end) {
		init = op(init, *start);
		start++;
	}
	return init;
}
int main() {
	vector<int> p{ 1,2,3,4 };
	int sum = 0;
	//cout << accumulate1(p.begin(), p.end(), sum);
	cout << accumulate1(p.begin(), p.end(), sum, [](int a, int b) {return a + b; });
	
}