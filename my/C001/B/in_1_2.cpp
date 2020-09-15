/**
 * Amazing John的P30拍照贼棒
 * in_1_2
*/

#define MXN (10000020)

#define OO ("03.in")

#define N (1000000)
#define A (1000000)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c;

signed main() {
    freopen(OO, "w", stdout);

    srand(time(NULL));

    printf("%d\n", N);

    printf("%d %d\n", N, 0);
    for (int i = 2, v; i < N; ++i)
        printf("%d %d\n", 1, rand() % A);
    printf("%d %d", 2, rand() % A);
}