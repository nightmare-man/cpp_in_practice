#include "Chrono.h"
int main() {
	Chrono::Date d;
	std::cout << d;\
	while(!(std::cin >> d)){
		std::cout << "bad input\n";
		std::cin.clear();
		//清除输入标志
	}
	std::cout << d;
	return 0;
}