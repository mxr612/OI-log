/**
 * 2019.11.08【NOIP提高组】模拟 B 组
 * B 穿越泥地
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>

#define TOP (que.front())

const int way[4][2] = {
	{ +1, +0},
	{ +0, +1},
	{ -1, +0},
	{ +0, -1}
};

struct __help {
	int a[2000][2000] = {0};
	int &operator()(int x, int y) {return a[1000 + x][1000 + y];}
} cant, node;
struct __node {
	int x, y;
} cmp;

int X, Y, N;
std::queue<__node>que;

int main() {
	freopen("B.in", "r", stdin);
	memset(node.a, -1, sizeof(node.a));
	memset(cant.a, -1, sizeof(cant.a));
	scanf("%d%d%d", &X, &Y, &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &cmp.x, &cmp.y), cant(cmp.x, cmp.y) = 1;
	node(0, 0) = cmp.x = cmp.y = 0;
	que.push(cmp);
	while (!que.empty()) {
		for (int i = 0; i < 4; ++i) {
			cmp.x = TOP.x + way[i][0], cmp.y = TOP.y + way[i][1];
			if (abs(cmp.x) <= 501 && abs(cmp.y) <= 501 && cant(cmp.x, cmp.y) == -1 && node(cmp.x, cmp.y) == -1)
				node(cmp.x, cmp.y) = node(TOP.x, TOP.y) + 1, que.push(cmp);
		}
		que.pop();
	}
	printf("%d", node(X, Y));
	return 0;
}