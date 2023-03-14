#include "../include/std_lib_facilities.h"
//类定义的内部，Link<Elem>简写为Link
//如果是外部定义成员函数 则需要Link<Elem>
template<typename Elem>
struct Link {
	Link* prev;
	Link* succ;
	Elem val;
};
template<typename Elem>
class List {
public:
	class iterator;
	iterator begin();
	iterator end();
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	void push_back(const Elem& v);
	void push_front(const Elem& v);
	void pop_front();
	void pop_back();
	Elem& front();
	Elem& last();
};
template<typename Elem>
class List<Elem>::iterator {
private:
	Link<Elem>* cur;
public:
	iterator(Link<Elem>* p) :cur(p) {};
	iterator& operator--() { cur = cur->prev; return *this; }
	iterator& operator++() { cur = cur->succ; return *this; }
	Elem& operator*() { return cur->val; }
	bool operator==(const iterator& b) { return cur == b.cur; }
	bool operator!=(const iterator& b) { return !(*this == b); }
};
template<typename Iter>
Iter high(Iter first, Iter last) {
	Iter high = first;
	for (Iter p = first; p != last; p++) {
		if (*high < *p) high = p;
	}
	return high;
}
int main() {
	//未定义的错误
	int* a;
	cout << &a[0];
	return 0;
}

