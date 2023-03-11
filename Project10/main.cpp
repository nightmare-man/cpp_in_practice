#include "../include/std_lib_facilities.h"
struct Link {
	string value;
	Link* prev;
	Link* succ;
	Link(string v,Link* p=nullptr,Link* s=nullptr):value(v),prev(p),succ(s) {}
};
void print_god(Link* r) {
	while (r) {
		cout << r->value << "->";
		r = r->succ;
	}
}
Link* insert(Link* p,Link* pre) {
	//注意检测空指针
	if (!p) return nullptr;
	if (!pre) return p;
	pre->succ = p;
	if (p->prev) {
		p->prev->succ = pre;
		pre->prev = p->prev;
	}
	p->prev = pre;
	return pre;
}
int main() {
	Link* gods1 = new Link{ "Thor" };
	Link*gods2 = new Link{ "Odin"};
	Link* gods3 = new Link{ "Freia" };
	Link* head = insert(insert(gods1, gods2),gods3) ;
	print_god(head);
}