#include <stdio.h>
#include <stdlib.h>
#include<queue>
struct __edge {int v; __edge *nx;}*edge[500020] = {NULL};
void _add_edge(int u, int v) {__edge *p = NULL; while (p == NULL)p = (__edge *)calloc(1, sizeof(__edge));p->v = v; p->nx = edge[u]; edge[u] = p;}
int n, f[500020] = {0}, siz[500020] = {0}, cmp;
unsigned long long ans = 0, res[500020] = {0};
char k[500020] = {0};
std::queue<int>que;
int main() {
	freopen("testdata2.in", "r", stdin);
	// freopen("brackets.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%c", &k[i]);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &f[i]), _add_edge(f[i], i);
	que.push(1);
	while (!que.empty()) {
		cmp = que.front(); que.pop();
		if (k[cmp] == '(')
			res[cmp] = res[f[cmp]], siz[cmp] = 0;
		else if (k[f[cmp]] == 0)
			res[cmp] = res[f[cmp]], siz[cmp] = f[cmp] = k[cmp] = 0;
		else
			k[cmp] = k[f[f[cmp]]], siz[cmp] = siz[f[f[cmp]]] + 1, res[cmp] = res[f[cmp]] + siz[cmp], f[cmp] = f[f[f[cmp]]];
		ans ^= cmp * res[cmp];
		for (__edge *i = edge[cmp]; i != NULL; i = i->nx)
			que.push(i->v);
	}
	printf("%llu", ans);
	return 0;
}
