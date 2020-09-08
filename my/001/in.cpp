/**
 * 001make
*/

#define IN ("19.in")

#define N (1000000)
#define M (1000000)
#define TYPE (0)
#define TOP (100000000)
#define LIM >

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long a = 1e10, b = 1e5, mod, l, r;

#define ID ((a * (1 + (rand() % 9))) + (((b * rand()) + rand()) % a))

signed main() {
    freopen(IN, "w", stdout);

    srand(time(NULL));
    printf("%d\n", N);
    for (int i = 0, j; i < N; ++i)
        printf("%lld ", ID);
    putchar('\n');

    for (int i = 0; i < N; ++i)
        printf("%d ", rand() % TOP);
    putchar('\n');

    for (int i = 0; i < M; ++i) {
        do
            if ((r = ID) < (l = ID)) l ^= r ^= l ^= r;
        while (r - l LIM a);
        if (TYPE == 0) printf("%d %lld %lld\n", rand() & 1, l, r);
        if (TYPE == 1) printf("0 %lld %lld\n", l, r);
        if (TYPE == 2) printf("1 %lld %lld\n", l, r);
    }

    return 0;
}