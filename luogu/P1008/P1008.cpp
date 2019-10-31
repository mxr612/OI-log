#include <stdio.h>


int use[10] = {0}, p[10];
int c1, c2, c3;

void fac(int c) {
	if (c == 10) {
		c1 = p[1] * 100 + p[2] * 10 + p[3];
		c2 = p[4] * 100 + p[5] * 10 + p[6];
		c3 = p[7] * 100 + p[8] * 10 + p[9];
		if (c3 == 3 * c1 && c2 == 2 * c1) {
			printf("%d %d %d\n", c1, c2, c3);
		}
		return ;
	}
	for (int i = 1; i <= 9; i++) {
		if (use[i] == 0) {
			use[i] = 1;
			p[c] = i;
			fac(c + 1);
			use[i] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	fac(1);
	return 0;
}