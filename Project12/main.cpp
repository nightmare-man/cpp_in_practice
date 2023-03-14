#include "../include/std_lib_facilities.h"

template<typename Elem>
struct Link {
	Link* prev;
	Link* succ;
	Elem val;
};
//链表的定义
template<typename Elem>
struct List {
	Link<Elem>* first;
	Link<Elem>* last;
};
int main() {

}