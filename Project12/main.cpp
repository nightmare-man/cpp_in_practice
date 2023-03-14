#include "../include/std_lib_facilities.h"

int* get_from_j(int* count) {
	return new int[3] {1, 2, 3};
}
vector<int>* get_from_i() {
	return new vector<int>{ 1,2,3 };
}
template<typename Iterator>
Iterator high(Iterator first, Iterator last) {
	Iterator high = first;
	for (Iterator p = first; p != last; ++p) {
		if (*high < *p) high = p;
	}
	return high;
}
int main() {
	int jc = 0;
	int* jd = get_from_j(&jc);
	int* jh = high(jd, jd + jc);

	vector<int>* id = get_from_i();
	vector<int>& v = *id;
	int* ih = high(&v[0], &v[0] + v.size());
	delete[] jd;
	int* p = &(*id)[0];
	delete id;
	cout<<*p;
	return 0;
}