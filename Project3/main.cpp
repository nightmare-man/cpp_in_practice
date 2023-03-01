#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<double> distance;
	double sum = 0;
	for (double tmp; cin >> tmp;) {
		distance.push_back(tmp);
		sum += tmp;
	}
	sort(distance);
	cout << "total distance " << sum << " min distance " << distance[0] << " max distance "\
		<< distance[distance.size() - 1] << " average distance " << sum / distance.size();
	return 0;
}
int square(int x) {
	return x * x;
}