// T1 洪水

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

const short way[4][2] {
	{ 0, +1},
	{ 0, -1},
	{ +1, 0},
	{ -1, 0}
};

int R, C, x, y, cnt = 0, ck = 0;
char c;
short dt[60][60][4000] = {0};

struct node {
	short x, y, dep;
} cmp;
queue<node> que;
#define TOP (que.front())
#define ABL (!que.empty())

short ans[60][60] = {0}, res = 10000;
bool flag[60][60] = {false};

int main() {

	freopen("T1.in", "r", stdin);
	// freopen("T1.out", "w", stdout);

	cin >> R >> C;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> c;
			if (c == '.')cnt++;
			if (c == 'X')dt[i][j][0] = 2;
			if (c == 'D')dt[i][j][0] = 2, x = i, y = j;
			if (c == 'S') {
				cmp.x = i; cmp.y = j; cmp.dep = 0;
				que.push(cmp);
			}
			if (c == '*')
				dt[i][j][0] = 1, ck++;
		}
	}
	for (int i = 1; i <= R * C; ++i) {
		for (int j = 1; j <= R; ++j) {
			for (int k = 1; k <= C; ++k) {
				if (dt[j][k][i - 1] == 0) {
					for (int w = 0, _x, _y; w < 4; ++w) {
						_x = j + way[w][0];
						_y = k + way[w][1];
						if (0 < _x && _x <= R && 0 < _y && _y <= C && dt[_x][_y][i - 1] == 1) {
							dt[j][k][i] = 1;
							cnt--;
							break;
						}
					}
				} else
					dt[j][k][i] = dt[j][k][i - 1];
			}
		}
	}

	while (ABL) {
		ans[TOP.x][TOP.y] = TOP.dep;
		flag[TOP.x][TOP.y] = true;
		cmp.dep = TOP.dep + 1;
		for (int w = 0; w < 4; ++w) {
			cmp.x = TOP.x + way[w][0];
			cmp.y = TOP.y + way[w][1];
			if (0 < cmp.x && cmp.x <= R && 0 < cmp.y && cmp.y <= C) {
				que.push(cmp);
			}
		}
		while (ABL && (flag[TOP.x][TOP.y] || dt[TOP.x][TOP.y][TOP.dep] > 0))que.pop();
	}

	for (int w = 0, _x, _y; w < 4; ++w) {
		_x = x + way[w][0];
		_y = y + way[w][1];
		if (0 < _x && _x <= R && 0 < _y && _y <= C && flag[_x][_y])
			res = min(res, ans[_x][_y]);
	}

	if (res == 10000)
		cout << "KAKTUS";
	else
		cout << res + 1;

	return 0;
}