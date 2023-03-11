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
Link* add(Link* p, Link* suc) {
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
//删除节点 返回p的前驱或者后继 优先返回后继，除非只有前驱
Link* erase(Link*p) {
	if (!p) return nullptr;
	Link* ret = nullptr;
	if (p->prev) {
		ret = p->prev;
		p->prev->succ = p->succ;
	}
	if (p->succ) {
		ret = p->succ;
		p->succ->prev = p->prev;
	}
	return ret;
}
/// <summary>
/// 在p及后继中找val
/// </summary>
/// <param name="p"></param>
/// <param name="val"></param>
/// <returns></returns>
Link* find(Link* p,string val) {
	while (p&&p->value!=val) {
		p = p->succ;
	}
	return p;
}
/// <summary>
/// step向后移动x个节点
/// </summary>
/// <param name="p"></param>
/// <param name="step"></param>
/// <returns></returns>
Link* advance(Link* p, int step) {
	if (!p) return nullptr;
	if (step== 0) {
		return p;
	}
	else if(step>0){
		while (p && step != 0) {
			p = p->succ;
			step--;
		}
		return p;
	}
	else {
		while (p && step != 0) {
			p = p->prev;
			step++;
		}
		return p;
	}
}
int main() {
	Link* gods1 = new Link{ "Thor" };
	Link*gods2 = new Link{ "Odin"};
	Link* gods3 = new Link{ "Freia" };
	Link* head = insert(insert(gods1, gods2),gods3) ;

	print_god(erase(gods2));
}