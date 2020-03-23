/**
 * P3796
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

class __ACA {

	struct __node {
		int w;
		bool tag;
		__node *next[130], *fail;
	}*root = NULL, stack[20000];
	int top = 0;

public:

	inline void _clear() {memset(stack, 0, sizeof(stack)), root = NULL, top = 0;};
	inline void _build_ACA(char s[]) {
		register __node **x = &root;
		for (register int i = 0; s[i] != '\0'; ++i) {
			if (*x == NULL)*x = &stack[top++];

		}
	}


} ACA;


signed main() {

	freopen("P3796.in", "r", stdin);

	int N, stack[200], top = 0;

	char T[100020], s[200][100];

	scanf("%d", &N);

	while (N != 0) {
		ACA._clear(), top = 0;
		scanf("%s", T);
		for (register int i = 0; i < N; ++i) {
			scanf("%s", s[i]);

		}
		scanf("%d", &N);
	}

	printf("%.3lf\n", 3.1415926535);

	return 0;

}
