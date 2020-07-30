/**
 * A
 */

#include <stdio.h>

char s[100020];

int main() {

	freopen("A.in", "r", stdin);

	register int N, min = 0, max = 0;

	scanf("%d%s", &N, s);

	for (register int i = 0; i < N; ++i)
		if (s[i] == 'L')++min;
		else ++max;

	printf("%d", min + max + 1);

	return 0;
}