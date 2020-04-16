// 2

#include <iostream>
#include <cmath>
using namespace std;

int T;

double x[5], y[5], ans;

double sovle(double a, double b) {return sqrt(a * a + b * b);}

int main() {
	freopen("2.in", "r", stdin);
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
		ans = sovle(x[1] - x[2], y[1] - y[2]) + sovle(x[2] - x[3], y[2] - y[3]) + sovle(x[1] - x[3], y[1] - y[3]);
		cout << (int)ans << endl;
	}

	return 0;

}
