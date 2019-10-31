// A

#include <stdio.h>
#include <math.h>
#include <set>

long long n, m, q, p, c, sum = 0, a[400020];

std::multiset<long long>s;
std::multiset<long long>::iterator w;

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &m, &q);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum += a[i], s.insert(a[i]);
	w = s.end(), w--;
	printf("%lld\n", std::max((long long)*w, sum / m + ((sum % m == 0) ? 0 : 1)));

	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld", &p, &c);
		s.insert(c), s.erase(a[p]);
		sum += c - a[p], a[p] = c;
		w = s.end(), w--;
		printf("%lld\n", std::max((long long)*w, sum / m + ((sum % m == 0) ? 0 : 1)));
	}

	return 0;
}
