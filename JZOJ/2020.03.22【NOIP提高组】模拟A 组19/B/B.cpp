/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
char s[1000020], ss[2000020];
struct __dis {
	int p;
	__dis *next;
} *dis[2000020] = {NULL};
int ans[2000020] = {0};

class __tree {

	struct __node {
		int w, l, r, s, tag;
		bool flag;
		__node *ls, *rs;
	}*root;

	void _build_tree(__node *&x, int l, int r) {
		if (r < l)return ;
		while (x == NULL)x = (__node *)calloc(sizeof(__node), 1);
		x->l = l, x->r = r, x->s = r - l + 1;
		if (l < r)
			_build_tree(x->ls, l, (l + r) >> 1), _build_tree(x->rs, ((l + r) << 1) + 1, r);
	}

	inline void _push(__node *x) {
		if (x->ls != NULL) {
			if (x->flag) {
				x->ls->w = x->rs->w = x->ls->tag = x->rs->tag = 0;
				x->ls->flag = x->rs->flag = true;
				x->flag = false;
			}
			else {
				x->ls->w += x->tag * x->s;
				x->rs->w += x->tag * x->s;
				x->ls->tag += x->tag;
				x->rs->tag += x->tag;
			}
		}
	}



public:

	inline void _build_tree(int n) {_build_tree(root, 0, n);}
	inline void _clear() {if (root != NULL)root->w = 0, root->flag = true;}




} tree;





signed main() {

	freopen("B.in", "r", stdin);

	scanf("%d", &T);

	ss[0] = '\2', ss[1] = '\1';

	for (register int t = 0, i, j, k; t < T; ++t) {
		scanf("%s", s);
		for (i = 0, j = 2; s[i] != '\0'; ++i)
			ss[j++] = s[i], ss[j++] = '\1';
		ss[j] = '\0';
		printf("%s\n", ss);
	}

	return 0;

}