#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<string> words;
	for (int o = 0;o<10; o++) {
		string tmp="";
		cin >> tmp;
		words.push_back(tmp);
	}
	sort(words);
	string mode = words[0];
	int mode_time = 1;
	int now_time = 1;
	for (int i = 1; i < words.size(); i++) {
		if (words[i] ==words[i - 1]) {
			now_time++;
		}
		else {
			if (now_time > mode_time) {
				mode_time = now_time;
				mode = words[i - 1];
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