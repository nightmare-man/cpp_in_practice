#include <iostream>
#include <vector>
#include <list>
using namespace std;
using Line = vector<char>;
class Text_iterator {
private:
	list<Line>::iterator lpos;
	Line::iterator cpos;
public:
	//这里有个坑，为啥不是传递引用而是传值呢？
	//vector<char> 的begin()返回是一个右值
	//临时的，如果想直接用的话这里就不能用引用
	//如果想用引用 得
	//vector<char>::iterator p= vector<char>.bein()
	//再传p作为第二个参数
	// 而采用这种方法，会多定义一个中间局部变量，浪费性能
	//直接调用移动赋值快
	Text_iterator(list<Line>::iterator ll, Line::iterator cc) :lpos{ ll }, cpos{ cc } {};
	bool operator==(const Text_iterator& b) { return (lpos == b.lpos) && (cpos == b.cpos); };
	bool operator!=(const Text_iterator& b) { return !((*this) == b); }
	char& operator*() {
		return *cpos;
	}
	Text_iterator& operator++() {
		if (cpos == (*lpos).end()) {
			lpos++;
			cpos = (*lpos).begin();
		}
		else cpos++;
		return *this;
	}
	Text_iterator& operator--() {
		if (cpos == (*lpos).begin()) {
			lpos--;
			cpos = (*lpos).end();
		}
		else cpos--;
		return *this;
	}
};
struct Doc {
	list<Line> line;
	Text_iterator begin() {
		return Text_iterator(line.begin(),(*line.begin()).begin() );
	}


	//构造函数添加空行
	Doc() { line.push_back(Line{}); }
};

istream& operator>>(istream& is, Doc& d) {

	for (char ch; is.get(ch);) {
		d.line.back().push_back(ch);
		if (ch == '\n') d.line.push_back(Line{});
	}
	if (d.line.back().size()) d.line.push_back(Line{});
	return is;
}

int main() {
	Doc d;
	cin >> d;

	return 0;
}