#include "../include/std_lib_facilities.h"

int main() {
	vector<double> temps;
	for (double temp; cin >> temp;) temps.push_back(temp);
	double sum = 0;
	double high_temp = -1000;
	double low_temp = 1000;
	
	for (int x : temps) {
		if (x > high_temp) high_temp = x;
		if (x < low_temp) low_temp = x;
		sum += x;
	}
	cout << "high temp " << high_temp << endl;
	cout << "low temp " << low_temp << endl;
	cout << "average temp " << sum / temps.size() << endl;
	return 0;
}
