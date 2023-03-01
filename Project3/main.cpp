#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<int> num;
	for (int tmp; cin >> tmp;) {
		num.push_back(tmp);
	}
	sort(num);
	int max = num[num.size() - 1];
	int min = num[0];
	int mode = num[0];
	int mode_time = 1;
	int now_time = 1;
	for (int i = 1; i < num.size(); i++) {
		if (num[i] == num[i - 1]) {
			now_time++;
		}
		else {
			if (now_time > mode_time) {
				mode_time = now_time;
				mode = num[i - 1];
			}
			now_time = 1;
		}
	}
	cout << "mode " << mode << " times " << mode_time << endl;
	return 0;
}
int square(int x) {
	return x * x;
}