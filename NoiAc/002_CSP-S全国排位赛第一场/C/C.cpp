// C

#include <iostream>
#include <algorithm>
using namespace std;

struct __man {
	unsigned long long a, b, w, s;
} man[200000];

int n;

unsigned long long sum[200000];

int _cmp_sort(__man a, __man b) {return a.w < b.w;}

int main() {

	freopen("C.in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> man[i].a >> man[i].b, man[i].w = man[i].a + man[i].b, man[i].s = man[i].a - man[i].b;

	sort(&man[1], &man[n + 1], _cmp_sort);

	for (int i = 1; i <= n; ++i)sum[i] = sum[i] + man[i].a;

	return 0;
}