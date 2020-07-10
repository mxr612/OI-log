/**
 * P1483 序列变换
 * 傻逼欺骗题
 * 纯模拟M*pow(N,0,5)
*/

#define MXN (1000020)

#include <math.h>
#include <stdio.h>

int N, M;

int arr[MXN];
long long mod[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1483.in", "r", stdin);
#endif

    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);

    for (int i = 1, opt, x, y, res; i <= M; ++i) {
        scanf("%d", &opt);
        if (opt == 1)
            scanf("%d%d", &x, &y), mod[x] += y;
        else {
            scanf("%d", &x);
            res = arr[x];
            for (int i = 1; i < sqrt(x); ++i)
                if (x % i == 0)
                    res += mod[i] + mod[x / i];
            if (sqrt(x) * int(sqrt(x)) == x)
                res += mod[int(sqrt(x))];
            printf("%d\n", res);
        }
    }

    return 0;
}