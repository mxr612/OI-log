// fignt.in
// P5016.in

#include <iostream>
using namespace std;

long long n, m, p1, s1, s2;
long long c[100001];
long long LR = 0, ch = 0xfffffffffffffff, p2;

#define ab(z) ((z)<0?-(z):(z))

int main() {
	freopen("fight.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	cin >> m >> p1 >> s1 >> s2;

	c[p1] += s1;
	for (int i = 1; i <= n; i++)
		LR += c[i] * (m - i);

	for (int i = n; i > 0; i--)
		if (ch > ab(LR + s2 * (m - i)))
			p2 = i, ch = ab(LR + s2 * (m - i));

	cout << p2;

	return 0;
}