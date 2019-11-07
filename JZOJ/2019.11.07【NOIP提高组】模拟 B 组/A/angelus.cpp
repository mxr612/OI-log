/**
 * JZOJ_2019.11.07【NOIP提高组】模拟 B 组
 * A 七天使的通讯(angelus)
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define int long long

int t, n, m, u, v;
bool flag;

struct __tree {
	int vl[5020] = {0};
	void _update(int x, int v) {
		for (; x <= n; x += x & (-x))
			vl[x] += v;
	}
	void operator<<(int x) {_update(x, 1);}
	void operator>>(int x) {_update(x, -1);}
	int _ask(int x) {
		int ret = 0;
		for (; x > 0; x -= x & (-x))
			ret += vl[x];
		return ret;
	} bool operator()(int x, int y) {return _ask(std::max(x, y)) - _ask(std::min(x, y) - 1) == 0;}
	void operator()() {memset(vl, 0, sizeof(vl));}
} black, white;

signed main() {
	freopen("angelus.in", "r", stdin);
	scanf("%d", &t);
	while (t-- > 0) {
		flag = true;
		black(), white();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			if (black(u, v))
				black << std::min(u, v), black>>std::max(u, v);
			else if (white(u, v))
				white << std::min(u, v), white>>std::max(u, v);
			else
				flag = false;
		}
		if(flag)
			printf("sane\n");
		else
			printf("non\n");
	}
	return 0;
}