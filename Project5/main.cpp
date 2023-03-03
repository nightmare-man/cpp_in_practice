#include "../include/std_lib_facilities.h"
class Token {
public:
	char kind;
	double value;
};
class Token_stream {
public:
	
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

void Token_stream::putback(Token t) {
	if (full) error("putback() into a full buffer\n");
	buffer = t;
	full = true;
}
Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case '=':
	case '(':case ')':case '+':case '-':case '*':case '/': {
		Token t;
		t.kind = ch;
		t.value = 0;
		return t;
	}
	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':\
	case '8':case '9': {
		cin.putback(ch);
		Token t;
		t.kind = 'n';
		cin >> t.value;
		return t;
	}
	default: error("bad token\n"); break;
	}
}
Token_stream ts;
double EE();
double EE1();
double EE2();

double EE() {
	double left = EE1();
	Token t = ts.get();
	bool flag = true;
	while (flag) {
		//把所有高优先级的匹配到ee1，从左往右计算加减
		switch (t.kind) {
		case '+':
			left += EE1();
			t = ts.get();
			break;
		case '-':
			left -= EE1();
			t = ts.get();
			break;
		case '=':
			flag = false;
			break;
		default:
			ts.putback(t);
			flag = false;
			break;
		}
	}
	return left;
}
double EE1() {
	double left = EE2();
	Token t = ts.get();
	bool flag = true;
	while (flag) {
		switch (t.kind) {
		case '*':
			left *= EE2();
			t = ts.get();
			break;
		case '/': {
			double d = EE2();
			if (d == 0) error("divide by zero!\n");
			left /= d;
			t =ts.get();
			break;
		}
		case '%': {
			left = int(left) % int(EE2());
			t = ts.get();
			break;
		}
		
			
		default:
			ts.putback(t);
			flag = false;
			break;
		}
	}
	return left;
}
double EE2() {
	double left = 0;
	Token t = ts.get();
	if (t.kind == 'n') {
		left = t.value;
	}
	else if (t.kind == '(') {
		left = EE();
		Token t=ts.get();
		if (t.kind != ')') error("expect )\n");
	}
	else {
		ts.putback(t);
	}
	return left;
}


int main() {
	try {
		while (true) {
			cout << "Expression:";
			Token t;
			double result = 0;
			result = EE();
			cout << "result " << result << endl;
		}
	}
	catch (runtime_error& e) {
		cout << "runtime error:" << e.what() << endl;
	}
	
	
	return 0;
}