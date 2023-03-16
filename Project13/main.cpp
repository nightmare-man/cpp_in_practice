#include "../include/std_lib_facilities.h"

int main() {
	string from, to;
	cin >> from >> to;
	ifstream is{ from };
	ofstream os{ to };
	istream_iterator<string> ii{ is };
	//当输入流结束时，遇到eof时，其iterator等于默认iterator，因此
	//可以用eos{}当序列末尾
	istream_iterator<string> eos;
	//以"\n"作为分隔符
	ostream_iterator<string> oo{ os,"\n"};
	//使用指向string的迭代器初始化vector<string>

	vector<string> b{ ii,eos };
	//对vector进行排序
	//sort(b.begin(), b.end());
	//复制到输出流
	//删除相邻的复制，因此最好先排序
	unique_copy(b.begin(), b.end(), oo);
	return 0;
}