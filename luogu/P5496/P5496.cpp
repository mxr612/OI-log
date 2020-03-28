/**
 * P5496
 * PAM
 */

#include <stdio.h>
#include <stdlib.h>

char s[500020];

struct __node {
	int w, l;
	__node *next[26], *fail;
}*root0 = (__node *)calloc(sizeof(__node), 1), *root1 = (__node *)calloc(sizeof(__node), 1);

__node *_get(register __node *x, register int v) {
	while (s[v] != s[v - x->l - 1])x = x->fail;
	return x;
}

signed main() {

	freopen("P5496.in", "r", stdin);

	root0->fail = root1->fail = root1, root1->l = -1;
	for (register unsigned i = 0; i < 26; ++i)root0->next[i] = root1->next[i] = root0;

	scanf("%s", s);

	register __node *x = root1, *c;
	for (register unsigned i = 0, k = 0; s[i] != '\0'; ++i) {
		s[i] = ((s[i] - 97 + k) % 26) + 97;
		x = _get(x, i);
		if (x->next[s[i] - 'a'] == NULL || x->next[s[i] - 'a'] == root0) {
			c = (__node *)calloc(sizeof(__node), 1);
			c->fail = _get(x->fail, i)->next[s[i] - 'a'];
			c->w = c->fail->w + 1;
			c->l = x->l + 2;
			x->next[s[i] - 'a'] = c;
		}
		x = x->next[s[i] - 'a'];
		k = x->w;
		printf("%d ", k);
	}

	return 0;

}