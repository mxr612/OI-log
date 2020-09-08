/**
 * 001make
*/

#define IN ("05.in")

#define N (1000)
#define M (1000)
#define TYPE (0)
#define TOP (1005)
#define LIM >

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <map>

std::map<long long, int> map;

long long cp, a = 1e10, b = 1e5, mod, l, r;

#define ID ((a * (1 + (rand() % 9))) + (((b * rand()) + rand()) % a))

signed main() {
    freopen(IN, "w", stdout);

    srand(time(NULL));
    printf("%d %d\n", N, M);
    for (int i = 0, j; i < N; ++i) {
        while (map.count(cp = ID))
            ;
        printf("%lld ", ID);
    }
    putchar('\n');

    for (int i = 0; i < N; ++i)
        printf("%d ", rand() % TOP);
    putchar('\n');

    for (int i = 0; i < M; ++i) {
        do
            if ((r = ID) < (l = ID)) l ^= r ^= l ^= r;
        while (a LIM r - l);
        if (TYPE == 0) printf("%d %lld %lld\n", rand() & 1, l, r);
        if (TYPE == 1) printf("0 %lld %lld\n", l, r);
        if (TYPE == 2) printf("1 %lld %lld\n", l, r);
    }

    return 0;
}