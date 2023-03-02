#include "../include/std_lib_facilities.h"
class Token {
public:
	char kind;
	double value;
};
Token get_token() {
	char tmp = ' ';
	Token t{'a',0};
	string num="";
	
	while (cin >> tmp||num!="") {
		bool end = false;
		if (tmp >= '0' && tmp <= '9') {
			num += tmp;
		}
		else {
			if (num != "") {
				int sum = 0;
				for (int i = 0; i < num.size(); i++) {
					sum += int(num[i] - '0') * pow(10, num.size() - 1);
				}
				t.value = sum;
				cin.putback(tmp);
				break;
			}
			
			switch (tmp) {
				case ' ':
				case '\n':
				case '\t':
					break;
				case '+':
				case '-':
				case '*':
				case '/':
					t.kind = tmp;
					end = true;
					break;
			}
		}
		tmp = 0;
		if (end) break;
	}
	return t;
}
vector<Token> tok;
int main() {
	cout << "Expression:";
	Token t;
	while (cin) {
		t=get_token();
		tok.push_back(t);
	}
	for (Token t : tok) {
		cout << "value " << t.value << " kind " << t.kind << endl;
	}
	return 0;
}