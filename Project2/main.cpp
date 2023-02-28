#include "../include/std_lib_facilities.h"
int main() {
	string first_name{ "" };
	string receiver_name{ "" };
	cout << "enter ur first name:";
	cin >> first_name;
	cout << "Hello," << first_name;
	cout << "\nenter receiver:";
	cin >> receiver_name;
	cout << "Dear " << receiver_name;
	return 0;
}