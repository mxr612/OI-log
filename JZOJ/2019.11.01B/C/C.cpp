// C

#include <stdio.h>

int n, q, p = 1;
char s[100020], c;

int main() {
	freopen("C.in", "r", stdin);
	scanf("%d\n", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%c ", &c);
		switch (c) {
		case 'T':
			scanf("%c\n", &c);
			s[p++] = c;
			break;
		case 'U':
			scanf("%d\n", &q);
			p -= q;
			break;
		case 'Q':
			scanf("%d\n", &q);
			printf("%c\n", s[q]);
			break;
		default:
			break;
		}
	}
	return 0;
}