#include <iterator>
#include <utility>
#include <iostream>
using namespace std;
//注意重载的函数在哪个命名空间
namespace std {
	// I am not happy that I had to put these stream operators in std namespace.
	template<class A,class B>
	ostream& operator<<(ostream& os, const pair<A, B>& p) {
		return os << p.first << " " << p.second;
	}
	template<class A, class B>
	istream& operator>>(istream& is, pair<A, B>&p ) {
		return is >> p.first >> p.second;
	}
}
int main() {
	
	istream_iterator<pair<string,int>> in{ cin };
	auto p = *in;
	cout << p.first;
	
}