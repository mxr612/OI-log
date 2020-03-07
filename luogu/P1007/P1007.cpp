/**
 * P1007
 */

#include <stdio.h>
#include <algorithm>

int main() {

	int L, N, a, min = 0, max = 0;

	scanf("%d%d", &L, &N);

	for (register int i = 0; i < N; ++i) {
		scanf("%d", &a);
		min = std::max(min, std::min(a, L - a + 1));
		max = std::max(max, std::max(a, L - a + 1));
	}

	printf("%d %d\n", min, max);

	return 0;
}