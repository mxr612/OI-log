/**
 * 001make
*/

#define II ("09.in")

#define N (1000000)
#define M (1000000)
#define LEN (10000000)
#define LOW (0)
#define TOP (10)
#define TYPE (0)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <map>

#define ID (((((long long)rand()) * rand()) % LEN) + 10000)

std::map<long long, long long> chk;

signed main() {
    freopen(II, "w", stdout);

    srand(time(NULL));

    printf("%d %d\n", N, M);
    unsigned long long x;
    for (int i = 0; i < N; ++i) {
        while (chk.count(x = ID))
            ;
        ++chk[x];
        printf("%llu ", x);
    }
    putchar('\n');
    for (int i = 0; i < N; ++i)
        printf("%d ", LOW + (rand() % TOP));
    putchar('\n');
    unsigned long long l, r;
    for (int i = 0, o; i <= M; ++i) {
        do {
            if ((r = ID) < (l = ID)) l ^= r ^= l ^= r;
        } while (r - l > (sqrt(LEN)));
        if (TYPE)
            o = (TYPE == 1) ? (0) : (1);
        else
            o = !((rand() & 1) && (rand() & 1));
        printf("%d %llu %llu\n", o, l, r);
    }

    return 0;
}