#include "../include/std_lib_facilities.h"
vector<double> f() {
    vector<double> ret{ 4 };
    ret.push_back(12.0);
    return ret;
}
int main() {
    //移动构造函数
    vector<double> v = f();
    cout << v[0];
}