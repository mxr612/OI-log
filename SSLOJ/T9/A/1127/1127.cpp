//AC

#include <stdio.h>
#include <math.h>
#include <string.h>

int p, now[501], ans[501] = {0};
int cmp[501], js[501];

void print(){
	for (int i = 10; i > 0; i--) {
		for (int j = 0; j < 50; j++) {
			printf("%d", ans[i * 50 - j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void HxL(int a[], int b[], int w) {
	memset(js, 0, sizeof(js));
	int ys = 0;
	for (int i = 1; i <= 500; i++) {
		js[i] = a[i] * b[w] + ys;
		ys = js[i] / 10;
		js[i] %= 10;
	}
}

void HpH(int w) {
	int ys = 0;
	for (int i = w; i <= 500; i++) {
		cmp[i] += js[i - w + 1] + ys;
		ys = cmp[i] / 10;
		cmp[i] %= 10;
	}
}

void HxH(int a[], int b[]) {
	memset(cmp, 0, sizeof(cmp));
	for (int i = 1; i <= 500; i++) {
		HxL(a, b, i);
		HpH(i);
	}
	for (int i = 1; i <= 500; i++) {
		a[i] = cmp[i];
	}
}

int main(int argc, char const *argv[])
{
	freopen("1127.in", "r", stdin);
	scanf("%d", &p);
	printf("%d\n", (int )floor(p * log10(2)) + 1);
	now[1] = 2;
	ans[1]++;
	do {
		if (p % 2) {
			HxH(ans, now);
		}
		p >>= 1;
		HxH(now, now);
		
	} while (p != 0);
	ans[1]--;
	print();
	return 0;
}