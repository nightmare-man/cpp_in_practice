#include "../include/std_lib_facilities.h"

int solution(const string& s) {
	if (s.size() == 0) return 0;
	int sz = s.size();
	vector<vector<int>> p(sz, vector<int>(sz));
	//左边界
	for (int i = 0; i < sz; i++) {
		//右边界
		for (int j = i; j < sz; j++) {
			if (i == j) {
				p[i][j] = 1;
			}
			else {
				auto end = s.begin() + j;
				auto ret = find(s.begin() + i, end, s[j]);
				if (ret == end) p[i][j] = p[i][j - 1] + 1; else p[i][j] = p[i][j - 1];
			}
		}
	}

	int ret = 1;
	for (int j = 1; j < sz; j++) {
		int x = ret;
		for (int i = 0; i <= j; i++) {
			x += p[i][j];
		}
		ret = x;
	}
	return ret;
}
int main() {
	cout << solution("aaa");
}