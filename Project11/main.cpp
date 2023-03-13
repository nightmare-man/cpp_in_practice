class Aaaaaa {
public:
	int a;
	Aaaaaa() { a++; };
	~Aaaaaa() { a--; };
};
int main() {
	//定义一个变量，实际就是分类内存并在函数开始的时候调用构造函数
	//结尾的时候也会调用析构函数
	//异常处理的catch块是一个单独的函数，里面也会调用析构函数
	Aaaaaa a;
	try {
		a.a = 10;
		throw;
	}
	catch (...) {
		a.a =a.a + 20;
	}
	return 0;
}