#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<string> words;
	for (string tmp; cin >> tmp;) {
		words.push_back(tmp);
	}
	sort(words);
	for (int i = 0; i < words.size(); i++) {
		if (i == 0 || words[i] != words[i - 1]) cout << words[i]<<" ";
	}
	return 0;
}
int square(int x) {
	return x * x;
}