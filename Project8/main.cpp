#include "../include/std_lib_facilities.h"
struct Reading {
	int hour;
	double temperature;
};
/// <summary>
/// 读到结尾或者终结符结束int的输入
/// </summary>
/// <param name="ist"></param>
/// <param name="v"></param>
/// <param name="terminator"></param>
void fill_vector(istream& ist, vector<int>& v, char terminator) {
	//对于输入流istream good()是正常
	//eof()是输入结束
	//fail()是读入错误 比如需要数字而下一个是x
	//bad是严重故障 比如磁盘错误
	for (int i; ist >> i;)v.push_back(i);
	if (ist.eof()) return;
	if (ist.bad()) error("ist is bad");
	if (ist.fail()) {
		ist.clear();//先清除状态为了获得下一个字符
		char c;
		ist >> c;
		if (c != terminator) {
			ist.unget();//放回输入流
			ist.clear(ios_base::failbit);
			//遇到的fail并非终结符引起的，重新设置回fail
		}
	}
}
int main() {
	cout << "enter input file name:";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("can't open file\n");
	vector<int> vint;
	fill_vector(ist, vint, '*');
	for (int x : vint) cout << x << " ";
	if (ist.fail()) cout << "\n非终结符结束\n";
	else cout << "\n终结符结束\n";
	return 0;
}