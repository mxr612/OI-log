/**
 * 2019.11.11【NOIP提高组】模拟 B 组
 * C 长途旅行
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int C, n, m, T;
struct __edge {
	int v, w;
	__edge *nx;
}*edge[70] = {NULL};
void _add_edge(int u, int v, int w) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->w = w, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}

bool A_dis[10020][70];

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &C);
	while (C-- > 0) {
		scanf("%d%d%d", &n, &m, &T);
		for (int i = 1, u, v, w; i <= m; ++i)
			scanf("%d%d%d", &u, &v, &w), _add_edge(u, v, w), _add_edge(v, u, w);
		if (T <= 10000) {
			memset(A_dis, 0, sizeof(A_dis));
			A_dis[0][0] = true;
			for (int i = 0; i <= T; ++i)
				for (int j = 0; j < n; ++j)
					if (A_dis[i][j])
						for (__edge *k = edge[j]; k != NULL; k = k->nx)
							A_dis[i + k->w][k->v] = true;
			if (A_dis[T][n - 1]) printf("Possible\n");
			else printf("Impossible\n");
		} else if (n <= 5 && m <= 10) {
			
		} else {

		}
		for (int i = 0; i < n; ++i)
			_free_edge(edge[i]);
	}
	return 0;
}