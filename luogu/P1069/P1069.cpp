// P1069.in

#include <iostream>
#include <cmath>
using namespace std;

int prime[30000], pt = 0;

int N, m1, m2;

int M[30000];

int cmp, CMP[30000];

int ans = 100000;

void get(int arr[], int num) {
	for (int i = 1; i <= pt; i++) {
		arr[i] = 0;
		while (num > 1 && num % prime[i] == 0) {
			arr[i]++;
			num /= prime[i];
		}
	}
}

int sqr() {
	int ret = 0;
	for (int i = 1; i <= pt; i++) {
		if (M[i] == 0)
			continue;
		if (CMP[i] == 0)
			return 100000;
		ret = max(ret, (int)ceil(float(M[i]) / CMP[i]));
	}
	return ret;
}

int main() {
	freopen("P1069.in", "r", stdin);

	cin >> N;
	cin >> m1 >> m2;

	for (int i = 2; i <= m1; i++) {
		prime[++pt] = i;
		for (int j = 1; j < pt; j++) {
			if (i % prime[j] == 0) {
				pt--;
				break;
			}
		}
	}
	get(M, m1);
	for (int i = 1; i <= pt; i++)
		M[i] *= m2;

	for (int i = 1; i <= N; i++) {
		cin >> cmp;
		get(CMP, cmp);
		ans = min(ans, sqr());
	}

	if (ans == 100000)
		cout << -1;
	else
		cout << ans;

	return 0;
}