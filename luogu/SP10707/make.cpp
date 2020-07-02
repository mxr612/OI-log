#include <stdio.h>
#include <stdlib.h>
#include <time.h>

signed main() {
    freopen("check.in", "w", stdout);
    srand(time(NULL));

// #define RAD
#ifdef RAD
    int N = (rand() % 40000) + 1;
    int M = (rand() % 100000) + 1;
#else
    int N = 40;
    int M = 100;
#endif
    int R = 4;

    printf("%d %d\n", N, M);

    for (int i = 1; i <= N; ++i)
        printf("%d ", ((rand() % (N / R)) * 74751));

    for (int i = 1, a, b; i < N; ++i)
        if ((a = (rand() % N) + 1) != (b = (rand() % N) + 1))
            printf("%d %d\n", a, b);

    for (int i = 1; i <= M; ++i)
        printf("%d %d\n", (rand() % N) + 1, (rand() % N) + 1);

    return 0;
}