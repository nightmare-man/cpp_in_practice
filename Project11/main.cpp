class Aaaaaa {
public:
	int a;
	Aaaaaa() { a++; };
	~Aaaaaa() { a--; };
};
int main() {
	//try catch 在windows上使用的是seh机制
	//在try 块里 一直到catch时所有的局部对象 都会自动析构
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