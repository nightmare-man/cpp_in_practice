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
		cpos++;
		if (cpos == (*lpos).end()) {
			lpos++;
			cpos = (*lpos).begin();
		}
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
class Doc {
public:
	list<Line> line;

	Text_iterator begin() {
		return Text_iterator(line.begin(), (*line.begin()).begin());
	};
	Text_iterator end() {
		auto last = line.end();
		--last;//最后一行为空
		return Text_iterator(last, (*last).end());
	}
	void erase_line(int n);
	//构造函数添加空行
	Doc() { line.push_back(Line{}); }
};
void Doc::erase_line(int n) {
	
	auto p = line.begin();
	p++;
	advance(p,n);
	line.erase(p);
}
istream& operator>>(istream& is, Doc& d) {

	for (char ch; is.get(ch);) {
		d.line.back().push_back(ch);
		if (ch == '\n') d.line.push_back(Line{});
	}
	if (d.line.back().size()) d.line.push_back(Line{});
	return is;
}
ostream& operator<<(ostream& os,   Doc& d) {
	//for 迭代器运算 auto p的类型是*iterator
	for (auto p : d) cout <<p;
	return os;
}
/// <summary>
/// 重写的advance
/// </summary>
/// <typeparam name="iterator"></typeparam>
/// <param name="p"></param>
/// <param name="n"></param>
template<typename iterator>
void advance(iterator& p,int n) {
	if (n == 0) return;
	else if (n > 0) {
		while (n) {
			p++;
			n--;
		}
	}
	else {
		while (n) {
			p--;
			n++;
		}
	}
	return;
}
int main() {
	Doc d;
	cin >> d;
	d.erase_line(-1);
	cout << d;
	return 0;
}