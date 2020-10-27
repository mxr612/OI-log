
#include <stdio.h>
#include <stdlib.h>

signed main() {
    int n, k;
    char *S, *T;
    int *next, *pair, tot = 0;
    long long ans;

    scanf("%d%d", &n, &k);
    S = (char *)calloc(sizeof(char), n + 32), scanf("%s", S);
    T = (char *)calloc(sizeof(char), k + 32), scanf("%s", T);
    pair = (int *)calloc(sizeof(int), n + 32);
    next = (int *)calloc(sizeof(int), k + 32);

    for (int i = 0, j = -1; T[i]; ++i)
        if (j == -1 || T[i] == T[j]) {
            if (T[++i] == T[++j])
                next[i] = next[j];
            else
                next[++i] = ++j;
        } else
            j = next[j];

    for (int i = 0, j = 0; S[i];) {
        if (j == k)
            pair[tot++] = i - 1, j = next[j];
        else if (j == -1 || S[i] == T[j])
            ++i, ++j;
        else
            j = next[j];
    }
    pair[tot++] = n;
    ans = n * (1ll + n) / 2 - pair[0] * (1ll + pair[0]) / 2;
    for (long long i = 1, l; i < tot; ++i)
        l = pair[i] - pair[i - 1] + k - 2, ans -= l * (1 + l) / 2,
        printf("%d %d %d\n", pair[i - 1], pair[i], l * (1 + l) / 2);

    printf("%lld", ans);

    return 0;
}