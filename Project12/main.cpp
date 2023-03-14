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
    int* const p = new int;
    //用引用指向指针指的位置，这样就不用再
    //频繁操作指针，防止指针修改过程中
    //的错误 相当于 int* const p;
    int a = 10;
    p = &a;
    int& z = *p;
    cout << z;
    return 0;
}