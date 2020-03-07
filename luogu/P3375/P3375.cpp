/**
 * P3375
 */

#include <stdio.h>

char a[10000050] = {0}, b[10000050] = {0};
int kmp[10000050] = {0};

int main() {

	freopen("P3375.in", "r", stdin);

	scanf("%s%s", a + 1, b + 1);

	for (register int i = 2, j = 0; b[i] != '\0'; ++i) {
		while (j > 0 && b[i] != b[j + 1])j = kmp[j];
		if (b[i] == b[j + 1])++j;
		kmp[i] = j;
	}
	for (register int i = 1, j = 0; a[i] != '\0'; ++i) {
		while (j > 0 && a[i] != b[j + 1])j = kmp[j];
		if (a[i] == b[j + 1])++j;
		if (b[j + 1] == '\0')printf("%d\n", i - j + 1), j = kmp[j];
	}
	for (register int i = 1; b[i] != '\0'; ++i)
		printf("%d ", kmp[i]);

	return 0;

}