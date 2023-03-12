#include "../include/std_lib_facilities.h"
bool is_pal(const string& s) {
	int first = 0;
	int last = s.length() - 1;
	while (first < last) {
		if (s[first] != s[last]) return false;
		first++;
		last--;
	}
	return true;
}
bool is_pal1(const char s[],int size) {
	int first = 0;
	int last = size - 1;
	while (first < last) {
		if (s[first] != s[last]) return false;
		first++;
		last--;
	}
	return true;
}
istream& read_word(istream& is, char* buff, int max) {
	is.width(max);//最多读max-1;
	is >> buff;
	return is;
}
int strlen(char s[]) {
	int cnt = 0;
	while (*s) {
		s++;
		cnt++;
	}
	return cnt;
}
int main() {
	constexpr int max = 128;
	char s[max];
	//cin输入字符数组时会自动补0
	cin >> s;
}