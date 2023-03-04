
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../include/std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) ,value(0){}
};
struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};
class Symbol_table {
public:
	double get(string name);
	void set(string name, double value);
	bool is_declared(string name);
	void declare(string name,double value);
private:
	vector<Variable> var_table;

};
double Symbol_table::get(string name) {
	for (Variable x : var_table) {
		if (x.name == name) return x.value;
	}
	error(name, " not declared when get()");
}
void Symbol_table::set(string name, double value) {
	for (Variable x : var_table) {
		if (x.name == name) {
			x.value = value;
			return;
		}
	}
	error(name, " not declared when set()");
}bool Symbol_table::is_declared(string name) {
	for (Variable x : var_table) {
		if (x.name == name) return true;
	}
	return false;
}
void Symbol_table::declare(string name, double value) {
	if (is_declared(name)) error(name, " declare twice");
	var_table.push_back(Variable(name, value));
}
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char sqrt_ch = 'z';
const char number = '8';
const char name = 'a';
const string sqrt_s = "sqrt";

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(name);
			if (s == "sqrt") return Token(sqrt_ch);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}




Symbol_table st;
Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name: {
		string name = t.name;
		t = ts.get();
		if (t.kind == '=') {
			double right = expression();
			st.set(name, right);
			return right;
		}
		else {
			ts.unget(t);
			return st.get(name);
		}
		
	}
		
	case sqrt_ch: {
		t = ts.get();
		if (t.kind != '(') error("'(' expected after sqrt");
		double left = sqrt(expression());
		t = ts.get();
		if (t.kind != ')') error("')' expected after sqrt(");
		return left;
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	st.declare(name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}