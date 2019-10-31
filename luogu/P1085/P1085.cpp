/**
 * P1085
 * 不高兴的津津
 */

#include <stdio.h>

int a, max, cmp, day = 0;

int main(int argc, char const *argv[])
{
	// freopen("P1085.in", "r", stdin);
	for (int i = 1; i <= 7; i++) {
		scanf("%d %d", &a, &cmp);
		a += cmp;
		if(max < a){
			day=i;
			max=a;
		}
	}
	printf("%d",day);
	return 0;
}