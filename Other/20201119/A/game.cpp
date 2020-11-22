/**
 * game
*/

#include <stdio.h>
#include <string.h>

const long long MXN = 1000024,
                MD = 1000000007;

long long R[MXN], C[MXN], ans = 0;

char opt[10];

signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

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

    long long bI = 0, bII = 0;
    for (int i = 1; i <= M; ++i)
        bI = (bI + C[i]) % MD,
        bII = (bII + i * C[i]) % MD;

    for (int i = 0; i < N; ++i)
        ans = (ans + i * R[i] % MD * M % MD * bI + R[i] * bII) % MD;

    printf("%lld", ans);

    return 0;
}