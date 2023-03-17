#include "../include/std_lib_facilities.h"
namespace std {
	using it = vector<int>::iterator;
	it binary_search(it start, it end, const int val) {
		int l = 0;
		int r = end - start-1;
		int tar_idx = end - start;
		while (l <= r) {
			int m = (l + r) / 2;
			int this_val = *(start + m);
			if (this_val == val) {
				tar_idx = m;
				break;
			}
			else if (this_val > val)r = m - 1;
			else l = m + 1;;
		}
		return start + tar_idx;
	}
}
int main() {
	vector<int> v{ 2,3,56,6,4,6 };
	
	sort(v.begin(), v.end());
	for (const auto x : v) cout << x << " ";
	auto p=binary_search(v.begin(), v.end(), 12);
	if (p == v.end()) cout << "\nnot find" << endl;
	else cout << "\nfind" << endl;
}