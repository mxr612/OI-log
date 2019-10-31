// C

#include <iostream>
using namespace std;

char a[1100][1100] = {0};

int n, m, q, ans = 0;

struct __big_bin {
	int fa[1100000], size[1100000], cnt = 0;
	void operator<<(int x) {
		fa[x] = x; size[x] = 1, ++cnt;
	}
	int& operator[](int x) {
		return fa[x];
	}
	int _root(int x) {
		if (fa[x] != x)
			fa[x] = _root(fa[x]);
		return fa[x];
	} int operator()(int x) {return _root(x);}
	void _merge(int x, int y) {
		x = _root(x);
		y = _root(y);
		if (x == y)
			return ;
		--cnt;
		if (size[x] > size[y]) {
			fa[y] = x;
			size[x] += size[y], size[y] = 0;
		} else {
			fa[x] = y;
			size[y] += size[x], size[x] = 0;
		}
	} void operator()(int x, int y) {_merge(x, y);}

} bin;
struct __small_bin {
	int fa[1100], size[1100], cnt = 0;
	void operator<<(int x) {
		fa[x] = x; size[x] = 2, ++cnt;
	}
	int operator[](int x) {
		return fa[x];
	}
	int _root(int x) {
		if (fa[x] != x)
			fa[x] = _root(fa[x]);
		return fa[x];
	} int operator()(int x) {return _root(x);}
	int _merge(int x, int y) {
		x = _root(x);
		y = _root(y);
		cnt--;
		if (x < y) {
			fa[y] = x;
			size[x] += size[y], size[y] = 0;
			return x;
		} else {
			fa[x] = y;
			size[y] += size[x], size[x] = 0;
			return y;
		}
	} int operator()(int x, int y) {return _merge(x, y);}
} lt[1100];

void _try(char a[1100][1100], int x, int y) {
	if (bin(x * 1000 + y) == 0)
		bin << x * 1000 + y;
	if (a[x - 1][y] == '1')
		bin(x * 1000 + y, (x - 1) * 1000 + y);
	if (a[x + 1][y] == '1')
		bin(x * 1000 + y, (x + 1) * 1000 + y);
	if (a[x][y - 1] == '1')
		bin(x * 1000 + y, x * 1000 + (y - 1));
	if (a[x][y + 1] == '1')
		bin(x * 1000 + y, x * 1000 + (y + 1));
}

int main() {

	freopen("C.in", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	cin >> q;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			lt[i] << j;
			if (a[i][j] == '1')
				lt[i](j - 1, j), _try(a, i, j);
		}
	}
	for (int i = 1, xa, ya, xb, yb; i <= q; ++i) {
		cin >> xa >> ya >> xb >> yb;
		for (int j = xa; j <= xb; ++j)
			for (int k = lt[j](yb); k >= ya; k = lt[j](k - 1, k))
				a[j][k] = '1', _try(a, j, k);
		cout << bin.cnt << endl;
	}

	return 0;

}