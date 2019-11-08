/**
 * 2019.11.08【NOIP提高组】模拟 B 组
 * C 挑剔的美食家
 */

#include <stdio.h>
#include <algorithm>
#include <set>

struct __cow {
	int a, b;
	bool operator<(__cow x) {return a < x.a;}
} cow[100020];
struct __cao {
	int c, d;
	bool operator<(__cao x) {return d < x.d;}
} cao[100020];

int N, M, p = 1, cnt = 0, ans = 0;
std::multiset<int> s;
std::multiset<int>::iterator t;

int main() {
	freopen("C.in", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &cow[i].a, &cow[i].b);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d", &cao[i].c, &cao[i].d);
	std::sort(&cow[1], &cow[N + 1]);
	std::sort(&cao[1], &cao[M + 1]);
	for (int i = 1; i <= M; ++i) {
		while (p <= N && cow[p].a <= cao[i].d)
			s.insert(cow[p].b), p++;
		if (!s.empty()) {
			t = s.upper_bound(cao[i].d);
			if (t != s.begin()) 
				s.erase(--t),cnt++, ans += cao[i].d;
		}
	}
	printf("%d", ans);
	return 0;
}