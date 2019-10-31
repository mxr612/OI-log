// B

#include <stdio.h>
#include <stdlib.h>

struct __snake {

	struct __node {
		int x, y;
		__node *nx = NULL, *bk = NULL;
	}*head = NULL, *tail = NULL;

	const int WAY[4][2] = {
		{ 0, +1},
		{ -1, 0},
		{ 0, -1},
		{ +1, 0}
	};

	void _start(int x, int y) {
		head = tail = (__node *)calloc(1, sizeof(__node));
		head->x = x;
		head->y = y;
	}

	bool _move(char map[800][800], int n, int m, char way) {

		__node *p = (__node *)calloc(1, sizeof(__node)), *cmp;
		p->x = head->x, p->y = head->y;
		switch (way) {
		case 'W':
			p->x += WAY[0][0], p->y += WAY[0][1];
			break;
		case 'A':
			p->x += WAY[1][0], p->y += WAY[1][1];
			break;
		case 'S':
			p->x += WAY[2][0], p->y += WAY[2][1];
			break;
		case 'D':
			p->x += WAY[3][0], p->y += WAY[3][1];
			break;
		default :
			break;
		}

		if (n < p->x || p->x < 1 || n < p->y || p->y < 1) {
			free(p);
			printf("%d %d\n", WAY[0][0], WAY[0][1]);
			return false;
		}

		p->nx = head;
		head->bk = p;
		head = p;

		if (map[p->x][p->y] != 'o') {
			cmp = tail;
			tail = tail->bk;
			tail->nx = NULL;
			free(cmp);
		}

		return true;
	}

	void _print(char map[800][800]) {
		for (__node *p = tail; p != NULL; p = p->bk)
			map[p->x][p->y] = '#';
		map[head->x][head->y] = '@';
	}

	void _clear() {
		__node *cmp[2] = {head, head->nx};
		for (int i = 0; cmp[i % 2] != NULL; cmp[i % 2] = cmp[(i + 1) % 2]->nx, ++i)
			free(cmp[i % 2]);
	}

} snake;

int n, m, p = 0;
char map[800][800], s[200000];

int main() {

	freopen("B.in", "r", stdin);

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			map[i][j] = getchar();
			if (map[i][j] == '@') {
				map[i][j] = '.';
				snake._start(i, j);
			}
		}
		getchar();
	}

	scanf("%s", s);

	while (s[p] != '\0' && snake._move(map, n, m, s[p]))++p;

	// if (s[p] != '\0')
	printf("GG");
	// else {
	snake._print(map);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			putchar(map[i][j]);
		putchar('\n');
	}
	// }

	return 0;

}