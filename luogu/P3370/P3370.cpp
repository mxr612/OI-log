/**
 * luogu
 * P3370
 * 哈希
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int cnt = 0;

struct __node {
	ull w;
	int cnt;
	__node *last, *next;
} *hash[114514] = {NULL};

void push(char s[]) {
	ull hash_1 = 0, hash_2 = 0;
	for (register int i = 0; s[i] != '\0'; ++i)
		hash_1 = (hash_1 << 8) + 132 + s[i];
	hash_1 %= 114514;
	for (register int i = 0; s[i] != '\0'; ++i)
		hash_2 = hash_2 * 233 + 1432 + s[i];
	if (hash[hash_1] == NULL) {
		hash[hash_1] = (__node *)calloc(sizeof(__node), 1);
		hash[hash_1]->w = hash_2;
		hash[hash_1]->cnt = 1;
		++cnt;
	}
	else if (hash[hash_1]->w == hash_2)
		++hash[hash_1]->cnt;
	else
		for (register __node *x = hash[hash_1]; true; x = x->next)
			if (x->next == NULL) {
				x->next = (__node *)calloc(sizeof(__node), 1);
				x->next->w = hash_2;
				x->next->cnt = 1;
				++cnt;
				break;
			} else if (x->next->w == hash_2) {
				++x->next->cnt;
				break;
			}

}

signed main() {

	freopen("P3370.in", "r", stdin);

	int n;
	char s[2000];
	scanf("%d", &n);
	for (register int i = 0; i < n; ++i) {
		scanf("%s", s);
		push(s);
	}

	printf("%d\n", cnt);

	return 0;

}