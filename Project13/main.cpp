#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
int main() {
	unordered_map< string,int> words;
	for (string s; cin >> s;) ++words[s];
	for (const auto& p : words) cout << p.first << " " << p.second << endl;
}