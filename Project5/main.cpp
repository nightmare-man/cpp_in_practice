#include "../include/std_lib_facilities.h"
class Token {
public:
	char kind;
	double value;
};
Token get_token() {
	char tmp = 'x';
	string num = "";
	Token t{ 'n',0 };
	bool end = false;
	while (cin >> tmp) {
		end = false;
		if (tmp >= '0' && tmp <= '9') {
			num += tmp;
		}
		else {
			if (num != "") {
				int len = num.length();
				double n = 0;
				for (int i = 0; i < len; i++) {
					n += double(num[i] - '0') * pow(10, len - 1 - i);
				}
				t.value = n;
				num = "";
				cin.putback(tmp);
				break;
			}
			else {
				switch (tmp) {
				case '+':
				case '-':
				case '*':
				case '/':
				case '(':
				case ')':
				case '=':
					t.kind = tmp;
					end = true;
					tmp = ' ';
					break;

				}
			}
		}
		if (end) break;
	}
	return t;
}
vector<Token> tok;
bool E(int left, int right, int& r);
bool E1(int left, int right, int& r);
bool E2(int left, int right, int& r);
bool E2(int left, int right, int& r) {
	if (left == right) return (tok[left].kind == 'n' && (r = tok[left].value));
	if (left > right) return false;
	if(right-left>1) return (tok[left].kind=='('&&E(left+1,right-1,r)&&tok[right].kind==')') ;
	return false;
}
bool E1(int left, int right, int& r) {
	int lval = 0;
	int rval = 0;
	bool flag = false;
	for (int i = left; i <= right; i++) {
		if (tok[i].kind == '*') {
			if (E2(left, i - 1, lval) && E2(i + 1, right, rval)) {
				flag = true;
				r = lval * rval;
				break;
			}
		}
		if (tok[i].kind == '/') {
			if (E2(left,i - 1, lval) && E2(i + 1, right, rval)) {
				flag = true;
				r = lval / rval;
				break;
			}
		}
	}
	return flag || (E2(left, right, r));
}
bool E(int left,int right,int&r) {
	int lval = 0;
	int rval = 0;
	bool flag = false;
	for (int i = left; i <= right; i++) {
		if (tok[i].kind == '+') {
			if (E1(left, i - 1, lval) && E1(i + 1, right, rval)) {
				flag = true;
				r = lval + rval;
				break;
			}
		}
		if (tok[i].kind == '-') {
			if (E1(left, i - 1, lval) && E1(i + 1, right, rval)) {
				flag = true;
				r = lval - rval;
				break;
			}
		}
	}
	return flag || (E1(left, right, r));
}

int main() {
	cout << "Expression:";
	Token t;
	while (cin) {
		t=get_token();
		if (t.kind != '=')
			tok.push_back(t);
		else break;
	}
	for (Token t : tok) {
		cout << "value " << t.value << " kind " << t.kind << endl;
	}
	int result = 0;
	E(0, tok.size() - 1, result);
	cout << "result " << result << endl;
	return 0;
}