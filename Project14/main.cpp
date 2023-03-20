
class A {
public:
	//A(const A& x) = delete;
	//Shape& operator=(const A& x) = delete;

	A() :value{0} {};
	A(int x) :value{ x } {};
private:
	int value;
};
class BBBB :public A {

};
class CCCC :public A {

};
int main() {
	BBBB bb;
	
	CCCC cc;
	
	//为什么要禁用拷贝赋值 和 拷贝初始化？
	// 防止截断（即虽然B和C都继承A 但是各自还有独特的私有成员）
	//直接拷贝会出问题，因此删除了基类的拷贝
	//真想在派生类之间拷贝怎么办呢？自己实现clone函数（基类实现）
	//即使开启拷贝赋值只能都转化为基类行后再拷贝
	A a = A{ cc };
	A b = A{ bb };
	a = b;
	
}