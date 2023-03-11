#include "../include/std_lib_facilities.h"
class Link {
public:
	Link(string v, Link* p = nullptr, Link* s = nullptr) :value{ v }, prev{ p }, succ{s} {}
	Link* insert(Link* pre);
	Link* add(Link* suc);
	Link* find(const string value) const;
	Link* erase();
	Link* advance(int step)const;
	void print_all()const;
	Link* prev;
	Link* succ;
	string value;
};
Link* Link::insert(Link* pre) {
	//this 指针；
	Link* p = this;
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
Link* Link::add(Link* suc) {
	Link* p = this;
	if (!p) return nullptr;
	if (!suc) return p;
	suc->prev = p;
	if (p->succ) {
		p->succ->prev = suc;
		suc->succ = p->succ;
	}
	p->succ = suc;
	return p;
}
Link* Link::find(const string v) const{
	Link* p =const_cast<Link*>( this);
	while (p && p->value != v) {
		p = p->succ;
	}
	return p;
}
/// <summary>
/// 从列表中移除本节点 优先返回suc 
/// </summary>
/// <returns></returns>
Link* Link::erase() {
	Link* p = this;
	Link* ret = nullptr;
	if (p->prev) {
		p->prev->succ = p->succ;
		ret =p->prev;
	}
	if (p->succ) {
		p->succ->prev = p->prev;
		ret = p->succ;
	}
	return ret;
}
void Link::print_all()const {
	const Link* p = this;
	cout << "{";
	while (p) {
		cout << p->value<<',';
		p = p->succ;
	}
	cout << "}\n";
	return;
}
int main() {
	Link* norse_god = new Link{ "Thor" };
	norse_god = norse_god->insert(new Link{ "Odin" });
	norse_god = norse_god->insert(new Link{ "Zeus" });
	norse_god = norse_god->insert(new Link{ "Freia" });

	Link* greek_god = new Link{ "Hera" };
	greek_god = greek_god->insert(new Link{ "Athena" });
	greek_god = greek_god->insert(new Link{ "Mars" });
	greek_god = greek_god->insert(new Link{ "Poseidon" });
	Link* p = greek_god->find("Mars");
	if (p) p->value = "Ares";
	greek_god->print_all();
	Link* p2 = norse_god->find("Zeus");
	if (p2) {
		if (p2 == norse_god)norse_god = norse_god->succ;
		p2->erase();
		greek_god = greek_god->insert(p2);
	}
	norse_god->print_all();
	greek_god->print_all();
	return 0;
}