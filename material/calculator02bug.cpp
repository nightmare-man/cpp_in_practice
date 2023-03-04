
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/
#include "../include/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) ,value(0){}
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char ch);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}
/// <summary>
/// 忽略字符ch及之前的所有输入
/// </summary>
/// <param name="ch"></param>
void Token_stream::ignore(char ch) {
    if (full && buffer.kind == ch) {
        full = false;
        return;
    }
    full = false;
    char x = 0;
    while (cin >> x) {
        if (x == ch) return;
    }
}
//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:    // for "print"
    case quit:    // for "quit"
    case '=':
    case '!':
    case '%':
    case '(': case ')': case '+': case '-': case '*': case '/':
    case '{':case '}':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7':case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);
            return Token(name, s);
        }
        error("Bad token");
    }
}
class Variable {
public:
    string name;
    double value;
    Variable(string s,double v):name(s),value(v) {};
};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
double get_value(string s) {
    for (const Variable v : var_table) {
        if (v.name == s) return v.value;
    }
    error("get:undefined variable:", s);
}
void set_value(string s, double value) {
    for ( Variable v : var_table) {
        if (v.name == s) {
            v.value = value;
            return;
        }
    }
    error("get:undefined variable:", s);
}
bool is_defined(string var) {
    for (const Variable v : var_table) {
        if (v.name == var) return true;
    }
    return false;
}
double define_name(string s,double v) {
    if (is_defined(s)) error(s, " declared twice\n");
    var_table.push_back(Variable(s, v));
    return v;
}
double statement();
double declaration();
double expression();    // declaration so that primary() can call expression()
double term();
double mi();
double primary();
double declaration() {
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration()\n");
    string v_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of", v_name);
    double d = expression();
    define_name(v_name, d);
    return d;
}
double statement() {
    Token t = ts.get();
    switch (t.kind)
    {
    case let: {
        return declaration();
    }
    default:
        ts.putback(t);
        return expression();
    }
}
double mif(int i) {
    if (i < 0) error("bad argument to mif()\n");
    if (i == 0) return 1;
    int ret = 1;
    for (int x = 1; x <= i; x++) {
        ret *= x;
    }
    return ret;
}
//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{': {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error(" '}' expected");
        return d;
    }
    case name: {
        return get_value(t.name);
    }
    case '-':{
        double d = primary();
        return d * (-1);
    }
    case '+': {
        double d = primary();
        return d;
    }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

double mi() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind)
        {
        case '!': {
            int a = narrow_cast<int>(left);
            left = double(mif(a));
            return left;
        }
            
        default:
            ts.putback(t);
            return left;
        }
    }
}
//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = mi();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= mi();
            t = ts.get();
            break;
        case '/':
        {
            double d = mi();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%': {
            try {
                int lval = narrow_cast<int>(left);
                int rval = narrow_cast<int>(mi());
                if (rval == 0) error("%: divide by zero\n");
                lval = lval % rval;
                left = int(lval);
                
            }
            catch (runtime_error& e) {
                error("% don't support float\n");
            }
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}


void clean_up_mess() {
    ts.ignore(print);
}
//------------------------------------------------------------------------------
void calculate() {
    while (cin) {
        try {
            cout << ">";
            Token t = ts.get();
            if (t.kind == quit) break; // 'q' for quit
            if (t.kind == print)        // ';' for "print now"
                cout << "=" << val << "\n";
            else
                ts.putback(t);
            val = statement();
        }
        catch (exception& e) {
            cout << "exception: caculate()" << e.what() << endl;
            clean_up_mess();
        }
        
    }
}
constexpr char number = '8';
constexpr char print = ';';
constexpr char quit = 'q';
constexpr char let = 'L';
constexpr char name = 'a';
const string declkey = "let";
Token_stream ts;        // provides get() and putback() 
vector<Variable> var_table;
double val = 0;
int main()
try
{
    define_name("pi", 3.1415);
    define_name("e", 2.71828);
    calculate();
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------