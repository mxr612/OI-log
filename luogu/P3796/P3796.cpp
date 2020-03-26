/**
 * P3796
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 20000

struct __str {
	char s[100];
	int id, ans;
	__str *next;
} str[200];

class __ACA {

	struct __node {
		__node *next[26], *fail;
		__str *str;
	} node[MAX], *root, *que[MAX];
	int usage;

public:

	inline void _clear() {memset(node, 0, sizeof(node)), root = &node[0], usage = 0;}
	void _insert(register char *s, register __str *str) {
		register __node *x = root;
		for (register int i = 0; s[i] != '\0'; x = x->next[s[i++] - 'a'])
			if (x->next[s[i] - 'a'] == NULL)
				x->next[s[i] - 'a'] = &node[++usage];
		str->next = x->str;
		x->str = str;
	}
	void _build() {
		register int top = 0, i, j;
		for (i = 0; i < 26; ++i)
			if (root->next[i] == NULL)root->next[i] = root;
			else root->next[i]->fail = root, que[top++] = root->next[i];
		for (i = 0; i < top; ++i)
			for (j = 0; j < 26; ++j)
				if (que[i]->next[j] == NULL)que[i]->next[j] = que[i]->fail->next[j];
				else que[i]->next[j]->fail = que[i]->fail->next[j], que[top++] = que[i]->next[j];
	}
	void _query(register char *s) {
		register __node *x = root, *y;
		register __str *str;
		for (register int i = 0; s[i] != '\0'; ++i)
			for (y = x = x->next[s[i] - 'a']; y != NULL; y = y->fail)
				for (str = y->str; str != NULL; str = str->next)
					++str->ans;
	}

} ACA;

bool _cmp(__str a, __str b) {
	return (a.ans == b.ans) ? (a.id < b.id) : (a.ans > b.ans);
}

signed main() {

	freopen("P3796_2.in", "r", stdin);
	// freopen("P3796.out", "w", stdout);

	int N;
	char T[1000020];

	scanf("%d", &N);

	register int i;
	while (N > 0) {
		memset(str, 0, sizeof(str));
		ACA._clear();
		for (i = 0; i < N; ++i)
			scanf("%s", str[i].s), str[i].id = i, ACA._insert(str[i].s, &str[i]);
		ACA._build();
		scanf("%s", T);
		ACA._query(T);
		std::sort(&str[0], &str[N], _cmp);
		printf("%d\n%s\n", str[0].ans, str[0].s);
		for (i = 1; i < N && str[i].ans == str[i - 1].ans; ++i)
			printf("%s\n", str[i].s);
		scanf("%d", &N);
	}



	return 0;

}
