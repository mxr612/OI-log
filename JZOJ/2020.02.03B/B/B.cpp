/**
 * B.cpp
 */

#include <stdio.h>

int main() {

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	register int W, H, w, h;

	scanf("%d%d%d%d", &W, &H, &w, &h);

	for (register int i = 0; i * w <= W; ++i) {
		if (1.0 * (W - i * w) / (i + 1) < w) {
			w = i;
			break;
		}
	}
	for (register int i = 0; i * h <= H; ++i) {
		if (1.0 * (H - i * h) / (i + 1) < h) {
			h = i;
			break;
		}
	}
	printf("%d\n", w * h);

	return 0;
}