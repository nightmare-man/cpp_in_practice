#include "../include/std_lib_facilities.h"
string line="";
int idx=0;
vector<string> nv = { "birds","fish","C++" };
vector<string> vv = { "rules","fly","swim" };
vector<string> conjv = { "and","or","but" };
bool noun() {
	if (idx >= line.size()) return false;
	bool ret = false;
	for (string x : nv) {
		if (line.find(x, idx) == idx) {
			ret = true;
			idx += x.size();
			break;
		}
	}
	return ret;
}
bool verb() {
	if (idx >= line.size()) return false;
	bool ret = false;
	for (string x : vv) {
		if (line.find(x, idx) == idx) {
			ret = true;
			idx += x.size();
			break;
		}
	}
	return ret;
}
bool conj() {
	if (idx >= line.size()) return false;
	bool ret = false;
	for (string x : conjv) {
		if (line.find(x, idx) == idx) {
			ret = true;
			idx += x.size();
			break;
		}
	}
	return ret;
}
bool split() {
	bool ret =idx<line.size()&&line[idx] == ' ';
	while (idx < line.size()&&line[idx] == ' ') {
		idx++;
	}
	return ret;
}
bool sentence() {
	if (idx >= line.size()) return false;
	bool ret = noun() && split() && verb();
	if(idx<line.size()) ret=ret && split() && conj() && split() && sentence();
	return ret;
}
int  main() {
	line = "C++ fly and birds swim";
	idx = 0;
	cout << line << " is sentence?" << sentence() << endl;
}