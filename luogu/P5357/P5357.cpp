/**
 * P5357
 * A
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

class __ACA {

	struct __node {
		int w;
		bool flag;
		__node *next[26], *fail;
	} *root = (__node *)calloc(sizeof(__node), 1), *ans[200020];

public:

	void _insert(char *s, register int v) {
		register __node *x = root;
		for (register int i = 0; s[i] != '\0'; x = x->next[s[i++] - 'a'])
			if (x->next[s[i] - 'a'] == NULL)
				x->next[s[i] - 'a'] = (__node *)calloc(sizeof(__node), 1);
		ans[v] = x;
	}

	void _build() {
		std::vector<__node *>que;
		register unsigned i, j;
		for (i = 0; i < 26; ++i)
			if (root->next[i] == NULL)root->next[i] = root;
			else root->next[i]->fail = root, que.push_back(root->next[i]);
		for (i = 0; i < que.size(); ++i)
			for (j = 0; j < 26; ++j)
				if (que[i]->next[j] == NULL)que[i]->next[j] = que[i]->fail->next[j];
				else que[i]->next[j]->fail = que[i]->fail->next[j], que.push_back(que[i]->next[j]);
	}

	void _query(char *s, register int n) {
		register __node *x = root;
		for (register int i = 0; s[i] != '\0'; x = x->next[s[i++] - 'a'], ++x->w);
		std::vector<__node *>que;
		que.push_back(root), root->flag = true;
		for (register unsigned i = 0, j; i < que.size(); ++i)
			for (j = 0; j < 26; ++j)
				if (!que[i]->next[j]->flag)
					que.push_back(que[i]->next[j]), que[i]->next[j]->flag = true;;
		for (register unsigned i = que.size() - 1; i > 0; --i)
			que[i]->fail->w += que[i]->w;
		for (register int i = 0; i < n; ++i)
			printf("%d\n", ans[i]->w);
	}

} ACA;

signed main() {

	freopen("P5357.in", "r", stdin);
	// freopen("P5357.out", "w", stdout);

	int n;
	char s[2000020];

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i)
		scanf("%s", s), ACA._insert(s, i);
	ACA._build();
	scanf("%s", s);
	ACA._query(s, n);

	return 0;

}