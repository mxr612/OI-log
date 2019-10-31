/**
 * P1089
 * 津津的储蓄计划
 */

#include <stdio.h>

int save = 0, hand = 0, InPut;

int main(int argc, char const *argv[])
{
	freopen("P1089.in", "r", stdin);
	for (int i = 1; i <= 12; i++) {
		scanf("%d", &InPut);
		hand += 300;
		if (hand < InPut) {
			printf("-%d\n", i);
			return 0;
		}
		hand -= InPut;
		save += hand / 100;
		hand %= 100;
	}
	printf("%d\n", save * 120 + hand);
	return 0;
}