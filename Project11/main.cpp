#include "../include/std_lib_facilities.h"
template <typename T>
class Myvector {
private:
	int size;
	int space;
	T* mem;
	//重新分配空间
	void reserve(int newalloc) {
		if (newalloc <= space) return;
		T* p = new T[newalloc];
		std::copy(mem, mem + size, p);
		delete[] mem;
		mem = p;
		space = newalloc;
	}
public:
	//explicit 关键字避免隐式构造函数的转换
	//比如构造函数只需要传入一个int
	//需要传入该类型的时候可以传一个int代替，成为隐式转换
	//使用explicit 后可避免
	explicit Myvector() :size{ 0 }, space{ 0 }, mem{ nullptr } {};
	Myvector(initializer_list<T> lst) :size{ int(lst.size()) }, space{ int(lst.size()) }, mem{ new T[size] } {
		//容器的copy
		std::copy(lst.begin(), lst.end(), mem);
		cout << "调用了列表初始化\n";
	};
	Myvector(int s) :size{ s }, space{ s }, mem{ new T[s] } {
		for (int i = 0; i < s; i++) mem[i] = 0;
		cout << "调用了初始化\n";
	}
	int Size()const { return size; };
	T get(int idx)const {
		if (idx < 0 || idx >= size) error("out of range\n");
		return mem[idx];
	};
	void set(int idx, T val) {
		if (idx < 0 || idx >= size) error("out of range\n");
		mem[idx] = val;
	}

	Myvector(const Myvector& arg) :size{ arg.size }, space{ arg.size }, mem{ new T[size] } {
		std::copy(arg.mem, arg.mem + size, mem);
		cout << "调用了拷贝初始化\n";
	}

	Myvector(Myvector&& v)noexcept :size{ v.size }, space{ v.space }, mem{ v.mem } {
		v.size = 0;
		v.mem = nullptr;
		cout << "调用了移动初始化\n";
	}

	Myvector& operator=(Myvector&& v)noexcept;

	Myvector& operator=(const Myvector& v);
	~Myvector() {
		delete[] mem;
	}
	int Capcity() const {
		return space;
	}
	//改变vector大小
	//space可能变大但不可能变小
	void resize(int newsize);
	void push_back( T& d);
	//void push_back(const T&& d);
	T& operator[](int idx);
	const T& operator[](int idx)const;

};
template <typename T> T& Myvector<T>::operator[](int idx) {
	if (idx < 0 || idx >= size) error("out of range");
	return mem[idx];
}
template<typename T> const T& Myvector<T>::operator[](int idx)const {
	if (idx < 0 || idx >= size) error("out of range");
	return mem[idx];
}
template<typename T> void Myvector<T>::push_back( T& d) {
	cout << "左值引用" << endl;
	if (space == 0) reserve(8);
	else if (size == space) reserve(space * 2);
	mem[size] = d;
	size++;
}

template<typename T> void Myvector<T>::resize(int newsize) {
	reserve(newsize);
	//重新赋值0
	for (int i = 0; i < newsize; i++) mem[i] = 0;
	size = newsize;
}
template<typename T> Myvector<T>& Myvector<T>::operator=(Myvector<T>&& v) noexcept {
	size = v.size;
	mem = v.mem;
	space = v.space;
	v.size = 0;
	v.mem = nullptr;
	v.space = 0;
	cout << "调用了移动赋值\n";
	return *this;
}
template<typename T> Myvector<T>& Myvector<T>::operator=(const Myvector<T>& v) {
	//对引用也可以取指针，和引用的变量一样的地址
	if (this == &v)return *this;

	if (space < v.size) {
		T* p = new T[v.size];
		std::copy(v.mem, v.mem + v.size, p);
		delete[] mem;
		size = v.size;
		space = v.size;
		mem = p;
	}
	else {
		std::copy(v.mem, v.mem + v.size, mem);
		size = v.size;
	}
	cout << "调用了拷贝赋值\n";
	return *this;
}

template<typename T> Myvector<T> f1() {
	Myvector res{ 1,2,3 };
	return res;
}
template<typename T> void f(Myvector<T> v) {
	cout << v.Size();
}
string f() {
	return string{ "nihao" };
}
int main() {
	//左值：可以在表达式左边的值 ：即变量
	//右值 ：只能在表达式右边的值 如字面量 函数返回值等零时对象
	// 左值引用，如果是常量左值引用，则可以传入 右值，但是这样会
	//延长右值的存活时间，实际是产生了一个临时变量（左值），发生了复制
	//非常量左值引用，不允许传入右值
	// 右值引用，不产生复制 直接引用	
	Myvector<string> p;
	string s{ "23" };
	//如果没有定义右值引用
	p.push_back(f());
	p[0]="qq";
	cout << p[0];
}