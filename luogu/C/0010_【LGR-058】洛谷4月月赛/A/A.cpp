// A.in

#include <stdio.h>

int n, L, G, W, H;

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d %d %d\n", &n, &L, &G);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d\n", &W, &H);
		while (W > G || H > G) {W >>= 1; H >>= 1;}
		if (W < L || H < L)
			printf("Too Young\n");
		else if (W != H)
			printf("Too Simple\n");
		else printf("Sometimes Naive\n");
	}
	return 0;
}