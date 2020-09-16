/**
 * Amazing John的P30拍照贼棒
 * in_3_5
*/

#define MXN (10000020)

#define OO ("11.in")

#define N (100000)
#define A (1000000)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c;

signed main() {
    freopen(OO, "w", stdout);

    srand(time(NULL));

    printf("%d\n", N);

    printf("%d %d\n", N, rand() % A);
    for (int i = 2, v; i <= N; ++i)
        printf("%d %d\n", i - 1, rand() % A);
}