/**
 * JZOJ
 * 2020.02.25【NOIP提高组】模拟A 组10
 * A
 * 3870. 单词检索(search)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

int N, M, L;
char s[1020];

struct __hash {

	int ans = 0;

	struct __node {
		ull w;
		int cnt;
		__node *next;
	}*hash[114514] = {NULL};

	void reset() {
		memset(&hash, 0, sizeof(hash));
	}

	void insert(ull hash_1, ull hash_2) {
		if (hash[hash_1] == NULL) {
			hash[hash_1] = (__node *)calloc(sizeof(__node), 1);
			hash[hash_1]->w = hash_2;
			hash[hash_1]->cnt = 1;
			if (hash[hash_1]->cnt == M)++ans;
		} else if (hash[hash_1]->w == hash_2) {
			++hash[hash_1]->cnt;
			if (hash[hash_1]->cnt == M)++ans;
		}
		else {
			for (register __node *x = hash[hash_1]; true; x = x->next) {
				if (x->next == NULL) {
					x->next = (__node *)calloc(sizeof(__node), 1);
					x->next->w = hash_2;
					x->next->cnt = 1;
					if (x->next->cnt == M)++ans;
					break;
				}
				if (x->next->w == hash_2) {
					++x->next->cnt;
					if (x->next->cnt == M)++ans;
					break;
				}
			}
		}
	}

	bool push(char s[], int start) {
		ull hash_1 = 0, hash_2 = 0;
		for (register int i = start, end = start + L; i < end; ++i) {
			if (s[i] == '\0')return false;
			hash_1 = hash_1 * 233 + s[i] + 19290817, hash_2 = hash_2 * 19290817 + s[i] + 114514;
		}
		hash_1 %= 114514;
		insert(hash_1, hash_2);
		return true;
	}

	void merge(__hash x) {
		for (register int i = 0; i < 114514; ++i)
			for (register __node *j = x.hash[i]; j != NULL; j = j->next)
				insert(i, j->w);
	}

} cmp, ans;

signed main() {

	freopen("A.in", "r", stdin);

	scanf("%d%d%d", &N, &M, &L);

	for (register int i = 0, j; i < N; ++i) {
		scanf("%s", s);
		cmp.reset();
		for (j = 0; cmp.push(s, j); ++j);
		ans.merge(cmp);
	}

	printf("%d\n", ans.ans);

	return 0;

}