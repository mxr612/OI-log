/**
 * JZOJ2020.09.25
 * C求和
 * JZOJ1164
*/

#include <math.h>
#include <stdio.h>

long long N, A, B;

int p[1000], tot;

int gcd(int a, int b) { return (b == 0) ? (a) : (gcd(b, a % b)); }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%lld", &N);

    if (N <= 100000) {
        int ans = 0;
        for (int i = 1; i <= N; ++i)
            ans += (gcd(i, N) == 1) * i;
        printf("%d", ans);
    } else {
        A = N;
        for (int i = 2, k; i <= sqrt(A); ++i)
            if (A % i == 0)
                for (p[tot++] = i; A % i == 0; A /= i)
                    ;
        if (A > 1) p[tot++] = A;
        for (int i = 1, j, s, c; i < (1 << tot); ++i) {
            for (s = 1, c = 0, j = 0; j < tot; ++j)
                if (i & (1 << j))
                    s *= p[j], ++c;
            B += ((c & 1) ? (s) : (-s)) * (1 + N / s) * (N / s) / 2;
        }
        printf("%lld", (1 + N) * N / 2 - B);
    }

    return 0;
}