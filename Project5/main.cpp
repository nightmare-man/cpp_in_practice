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
double EE();
double EE1();
double EE2();

double EE() {
	double left = EE1();
	Token t = get_token();
	bool flag = true;
	while (flag) {
		//把所有高优先级的匹配到ee1，从左往右计算加减
		switch (t.kind) {
		case '+':
			left += EE1();
			t = get_token();
			break;
		case '-':
			left -= EE1();
			t = get_token();
			break;
		case '=':
			flag = false;
			break;
		default:
			cin.putback(t.kind);
			flag = false;
			break;
		}
	}
	return left;
}
double EE1() {
	double left = EE2();
	Token t = get_token();
	bool flag = true;
	while (flag) {
		switch (t.kind) {
		case '*':
			left *= EE2();
			t = get_token();
			break;
		case '/':
			left /= EE2();
			t = get_token();
			break;
		default:
			cin.putback(t.kind);
			flag = false;
			break;
		}
	}
	return left;
}
double EE2() {
	double left = 0;
	Token t = get_token();
	if (t.kind == 'n') {
		left = t.value;
	}
	else if (t.kind == '(') {
		left = EE();
		get_token();
	}
	else {
		cin.putback(t.kind);
	}
	return left;
}
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
	while (true) {
		cin.clear();
		cout << "Expression:";
		Token t;
		double result = 0;
		result = EE();
		
		cout << "result " << result << endl;
	}
	
	return 0;
}