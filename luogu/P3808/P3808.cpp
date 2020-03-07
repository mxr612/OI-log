/**
 * P3808
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>

struct __ACA {
	int w;
	__ACA *next[26], *fail;
}*root = (__ACA *)calloc(sizeof(__ACA), 1);

void _trie_insert(char s[], register __ACA *x) {
	for (register int i = 0; s[i] != '\0'; x = x->next[s[i++] - 'a'])
		while (x->next[s[i] - 'a'] == NULL)
			x->next[s[i] - 'a'] = (__ACA *)calloc(sizeof(__ACA), 1);
	++(x->w);
}

void _ACA_build(register __ACA * x) {
	register int i;
	std::queue<__ACA *> bfs;
	for (i = 0; i < 26; ++i)
		if (x->next[i] == NULL)
			x->next[i] = x;
		else
			x->next[i]->fail = x, bfs.push(x->next[i]);
	while (!bfs.empty()) {
		x = bfs.front(), bfs.pop();
		for (i = 0; i < 26; ++i)
			if (x->next[i] == NULL)
				x->next[i] = x->fail->next[i];
			else
				x->next[i]->fail = x->fail->next[i], bfs.push(x->next[i]);
	}
}

int _ACA_query(char s[], register __ACA *x) {
	register int res = 0;
	register __ACA *f;
	for (register int i = 0; s[i] != '\0'; ++i) {
		x = x->next[s[i] - 'a'];
		for (f = x; f != root && f->w != -1; f = f->fail)
			res += f->w, f->w = -1;
	}
	return res;
}

signed main() {

	freopen("P3808.in", "r", stdin);

	int n;
	char s[1000020];
	scanf("%d", &n);
	for (register int i = 0; i < n; ++i)
		scanf("%s", s), _trie_insert(s, root);

	_ACA_build(root);

	scanf("%s", s);
	printf("%d\n", _ACA_query(s, root));

	return 0;

}