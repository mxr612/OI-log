/**
 * A
 * PPMM
 */

#include <stdio.h>

char s[10];
int que[2000020] = {0}, max[2000020] = {0}, min[2000020] = {0};

int main() {

	freopen("A.in", "r", stdin);

	register int N, X, qi = 0, qo = 0, xi = 0, xo = 0, ni = 0, no = 0, flag = 0;

	scanf("%d", &N);

	for (register int i = 0; i < N; ++i) {
		scanf("%s", s);
		switch (s[1]) {
		case 'U':
			scanf("%d", &X);
			if (flag & 1)
				X = -X;
			que[qi++] = X;
			while (xo < xi && max[xi - 1] < X)--xi;
			while (no < ni && min[ni - 1] > X)--ni;
			max[xi++] = X;
			min[ni++] = X;
			break;
		case 'O':
			if (qo < qi) {
				if (max[xo] == que[qo])++xo;
				if (min[no] == que[qo])++no;
				++qo;
			}
			break;
		case 'I':
			if (qo < qi)
				++flag;
			break;
		case 'A':
			if (qo < qi)
				printf("%d\n", ((flag & 1) ? (-min[no]) : (max[xo])));
			break;
		default:;
		}
	}

	return 0;
}