// A

#include <stdio.h>
#include <string.h>

char a[1000000] = {false};
int n, m;

int opt, l, r, sum;

void get() {
	char c;
	l = r = 0;
	opt = getchar() - '0';
	getchar();
	c=getchar();
	while ('0' <= c && c <= '9') {
		l = l * 10 + c - '0';
		c = getchar();
	}
	c=getchar();
	while ('0' <= c && c <= '9') {
		r = r * 10 + c - '0';
		c = getchar();
	}
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		a[i] = ~(getchar() - '0') + 1;
		getchar();
	}
	for (int i = 0; i < m; i++) {
		get();
		// printf("%d %d %d\n", opt, l, r);
		switch (opt) {
		case  1:
			memset(&a[l], 0, r - l + 1);
			break;
		case 2:
			memset(&a[l], -1, r - l + 1);
			break;
		case 3:
			for (int j = l; j < r; j++)
				a[j] |= a[j + 1];
			break;
		case 4:
			for (int j = r; j > l; j--)
				a[j] |= a[j - 1];
			break;
		case 5:
			for (int j = l; j < r; j++)
				a[j] &= a[j + 1];
			break;
		case 6:
			for (int j = r; j > l; j--)
				a[j] &= a[j - 1];
			break;
		default :
			sum = 0;
			for (int j = l; j <= r; j++)
				sum += a[j];
			printf("%d\n", ~sum + 1);
		}
	}
}