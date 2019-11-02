/**
 * CSP-S2019复赛赛前模测（11月2日）A
 */

#include <stdio.h>
#include <stdlib.h>

struct __edge {
	int v, size;
	__edge *nx, *fb;
	void _free() {
		if (nx != NULL)
			nx->_free(), free(nx);
	}
}*edge[50020] = {NULL};

int n, k, ans;

__edge *_add_edge(int u, int v) {
	__edge *t;
	if (edge[u] == NULL) {
		t = (__edge *)calloc(1, sizeof(__edge));
		t->v = v, edge[u] = t;
	} else {
		for (__edge *p = edge[u]; p != NULL; p = p->nx) {
			if (p->nx == NULL || p->nx->v >= v) {
				t = (__edge *)calloc(1, sizeof(__edge));
				t->v = v, t->nx = p->nx, p->nx = t;
				break;
			}
		}
	}
	return t;
} void _fb(__edge *x, __edge *y) {x->fb = y; y->fb = x;}

int _count(int x, int dad) {
	int ret = 1;
	for (__edge *p = edge[x]; p != NULL; p = p->nx) {
		if (p->v != dad) {
			p->size = _count(p->v, x);
			p->fb->size = n - 1 - p->size;
			ret += p->size;
		}
	}
	return ret;
}

int _dfs(int x) {

}

void _update(int u, int v,int dad) {
	if (u == v)
		return ;
	for (__edge *p = edge[u]; p != NULL; p = p->nx) {
		if(p->v){

		}
	}
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1, a; i < n; ++i) {
		scanf("%d", &a);
		_fb(_add_edge(i, a), _add_edge(a, i));
	}
	_count(k, k);
	for (;;) {
		ans = _dfs();
	}

	for (int i = 1; i <= n; ++i)
		if (edge[i] != NULL)
			edge[i]->_free(), free(edge[i]);
	return 0;
}