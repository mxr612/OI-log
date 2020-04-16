// B

#include <iostream>
using namespace std;

unsigned long long n, ans = 0;
unsigned long long bk[100020] = {0};

unsigned long long tree[100020] = {0};
void _update(unsigned long long x, unsigned long long v) {
	for (; x > 0; x -= (x) & (-x))
		tree[x] += v;
}
unsigned long long _ask(unsigned long long x) {
	unsigned long long res = 0;
	for (; x <= n; x += (x) & (-x)) 
		res += tree[x];
	return res;
}

int main() {

	freopen("B.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> bk[i];

	for (int i = 1, j = 1; i <= n; ++i) {
		if (bk[i] < bk[i + 1] || i == n) {
			for (int k = 0, p; k <= (i - j) / 2; ++k)
				p = bk[j + k], bk[j + k] = bk[i - k], bk[i - k] = p;
			j = i + 1;
			++ans;
		}
	}

	for (int i = 1; i <= n; ++i) {
		ans += _ask(bk[i] + 1);
		_update(bk[i], 1);


	}

	cout << ans;

	return 0;
}