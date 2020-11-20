/**
 * game
*/

#include <stdio.h>
#include <string.h>

const long long MXN = 100024,
                MD = 1000000007;

long long R[MXN], C[MXN], ans = 0;

char opt[10];

signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "r", stdout);

    int N, M, K, X, Y;

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; ++i)
        R[i] = 1;
    for (int i = 1; i <= M; ++i)
        C[i] = 1;
    for (int i = 0; i < K; ++i)
        if (scanf("%s%d%d", opt, &X, &Y), strcmp("R", opt))  //S
            C[X] = (C[X] * Y) % MD;
        else  //R
            R[X - 1] = (R[X - 1] * Y) % MD;

    for (int i = 0, j; i < N; ++i)
        for (j = 1; j <= M; ++j)
            ans = (ans + (i * M + j) % MD * R[i] % MD * C[j]) % MD;

    printf("%lld", ans);

    return 0;
}