// T0.cpp

#include <iostream>
using namespace std;

int n, m;
unsigned long long a[5001][5001] = {0};

int main() {
	freopen("T0.in", "r", stdin);
	freopen("T0.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = i + 1; k <= n; k++) {
				for (int l = j + 1; l <= m; ++l) {
					
				}
			}
		}
	}

	return 0;
}