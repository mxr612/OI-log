
#define MXN (40000)
#define MXM (100000)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

signed main() {
    freopen("test_in", "w", stdout);
    srand(time(NULL));

// #define RAD
#ifdef RAD
    int N = (rand() % MXN) + 1;
    int M = (rand() % MXM) + 1;
#else
    int N = 10;
    int M = MXM;
#endif
    int R = 0;  //点权重复指数
    int L = 1;  //离散指数

    printf("%d %d\n", N, M);

    if (R == 0)
        for (int i = 1; i <= N; ++i)
            printf("%d ", i * L);
    else
        for (int i = 1; i <= N; ++i)
            printf("%d ", ((rand() % (N / R)) * L));

    putchar('\n');

    for (int i = 2; i <= N; ++i)
        printf("%d %d\n", i, (rand() % (i - 1)) + 1);

    for (int i = 1; i <= M; ++i)
        printf("%d %d\n", (rand() % N) + 1, (rand() % N) + 1);

    return 0;
}