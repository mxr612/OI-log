/**
 * P3808
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

class __ACA {

	struct __node {
		int w;
		__node *next[26], *fail;
	}*root = (__node *)calloc(sizeof(__node), 1);

public:

	inline void _insert(register char *s) {
		register __node *x = root;
		for (register int i = 0; s[i] != '\0'; x = x->next[s[i++] - 'a'])
			if (x->next[s[i] - 'a'] == NULL)
				x->next[s[i] - 'a'] = (__node *)calloc(sizeof(__node), 1);
		++x->w;
	}

	inline void _build() {
		register __node *que[1000000];
		register unsigned i, j, top = 0;
		for (j = 0; j < 26; ++j)
			if (root->next[j] == NULL)root->next[j] = root;
			else root->next[j]->fail = root, que[top++] = root->next[j];
		for (i = 0; i < top; ++i)
			for (j = 0; j < 26; ++j)
				if (que[i]->next[j] == NULL)que[i]->next[j] = que[i]->fail->next[j];
				else que[i]->next[j]->fail = que[i]->fail->next[j], que[top++] = que[i]->next[j];
	}

	int _query(char s[]) {
		register __node *x = root, *y;
		register int i = 0, ans = 0;
		while (s[i] != '\0')
			for (y = x = x->next[s[i++] - 'a']; y != NULL && y->w > -1; y = y->fail)
				ans += y->w, y->w = -1;
		return ans;
	}

} ACA;

int main() {

	freopen("P3808.in", "r", stdin);

	int n;
	char s[1000020];

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i)
		scanf("%s", s), ACA._insert(s);

	ACA._build();

	scanf("%s", s);
	printf("%d\n", ACA._query(s));

	return 0;

}