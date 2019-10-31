#include <stdio.h>
#include <string.h>

int a[500], b[500], ans[500];
int js[500];
char incmp;

void HxL(int w) {
	int ys = 0;
	memset(js, 0, sizeof(js));
	for (int i = 1; i <= 500; i++) {
		js[i] = a[i] * b[w] + ys;
		ys = js[i] / 10;
		js[i] %= 10;
	}
}

void HpH(int w) {
	int ys = 0;
	for (int i = w; i <= 500; i++) {
		ans[i] += js[i - w + 1] + ys;
		ys = ans[i] / 10;
		ans[i] %= 10;
	}
}

void HxH() {
	for (int i = 1; i <= 500; i++) {
		HxL(i);
		HpH(i);
	}
}

int main(int argc, char const *argv[])
{
	freopen("HxH.in", "r", stdin);

	int aa = 111;
	int bb = 200;

	for (int i = 1; i < 500 && aa > 0; i++) {
		a[i] = aa % 10;
		aa /= 10;
	}
	for (int i = 1; i <= 500 && bb > 0; i++) {
		b[i] = bb % 10;
		bb /= 10;
	}
	HxH();
	return 0;
}