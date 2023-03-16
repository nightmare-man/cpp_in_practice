#include "../include/std_lib_facilities.h"
template<typename in,typename out,typename Fun>
out copy_if1(in start, in end, out res, Fun f) {
	while (start != end) {
		if (f(*start)) {
			*res = *start;
			res++;
		} 
		start++;
	}
	return res;
}
int main() {
	int a[]{ 1,2,3,4,5 };
	vector<int> p(5);
	copy_if1(a, a + 5, p.begin(), [](int a) {return a % 2; });
	for (auto a : p) cout << a << endl;
}