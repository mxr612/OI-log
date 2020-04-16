/**
 * 2020.03.22【NOIP提高组】模拟A 组19
 * B
 * JZOJ 4172
 * BZOJ4166
 * luogu P5433
 */

#include <stdio.h>
#include <stdlib.h>

char s[100020];

class __PAM {

	struct __place {
		int v;
		__place *next;
	}*cmp;

	struct __node {
		int w, l;
		bool vis;
		__place *c;
		__node *next[26], *fail;
	} *root0 = NULL, *root1 = NULL;

public:

	void _build(char *s) {
		root0 = (__node *)calloc(sizeof(__node), 1), root1 = (__node *)calloc(sizeof(__node), 1);
		root0->fail = root1->fail = root1, root1->l = -1;
		register __node *x = root1, *c, *f;
		register int i, j;
		for (i = 0; i < 26; ++i)root0->next[i] = root1->next[i] = root0;
		for (i = 0; s[i] != '\0'; ++i) {
			while (s[i] != s[i - x->l - 1])x = x->fail;
			if (x->next[s[i] - 'a'] == root0) {
				c = (__node *)calloc(sizeof(__node), 1);
				for (j = 0; j < 26; ++j)c->next[j] = root0;
				for (f = x->fail; s[i] != s[i - f->l - 1]; f = f->fail);
				c->fail = f->next[s[i] - 'a'];
				c->l = x->l + 2;
				x->next[s[i] - 'a'] = c;
			}
			x = x->next[s[i] - 'a'];
			
			for (f = x; f != root1; f = f->fail)f->w ^= ((i << 1) - f->l + 1) >> 1;
		}
	}

	int _answer() {
		register int i, j, t = -1, res = 0;
		__node *que[100020];
		root0->vis = root1->vis = true;
		for (i = 0; i < 26; ++i)
			if (!root0->next[i]->vis)
				que[++t] = root0->next[i], que[t]->vis = true;
		for (i = 0; i < 26; ++i)
			if (!root1->next[i]->vis)
				que[++t] = root1->next[i], que[t]->vis = true;
		for (i = 0; i <= t; ++i) {
			if (res < que[i]->w)res = que[i]->w;
			for (j = 0; j < 26; ++j)
				if (!que[i]->next[j]->vis)
					que[++t] = que[i]->next[j], que[t]->vis = true;
		}
		return res;
	}

} PAM;

signed main() {

	freopen("B7.in", "r", stdin);

	int num;

	scanf("%d", &num);

	for (register int i = 0; i < num; ++i)
		scanf("%s", s), PAM._build(s), printf("%d\n", PAM._answer());

	return 0;

}