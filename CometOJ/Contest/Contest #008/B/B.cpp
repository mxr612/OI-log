// B 支援城市

#include <iostream>
using namespace std;

int n;
unsigned long long w[100001], w_[100001], sum = 0, sum_ = 0;

int main() {

	freopen("B.in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		w_[i] = w[i] * w[i];
		sum += w[i];
		sum_ += w_[i];
	}

	for (int x = 1; x <= n; ++x)
		cout << (n * w_[x]) + (sum_) - (2 * w[x]*sum) << ' ';

	return 0;
}