
#define ii ("00.in")
#define oo ("00.out")

#define MXN (1000020)

#include <stdio.h>

int n, m;

long long id[MXN], arr[MXN];

signed main() {
    freopen(ii, "r", stdin);
    freopen(oo, "w", stdout);

    scanf("%d%d", &n, &m);

    for (long long i = 0; i < n; ++i)
        scanf("%lld", &id[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);

    int o, ans;
    long long l, r;
    bool is;
    for (int i = 0, j; i < m; ++i) {
        scanf("%d%lld%lld", &o, &l, &r);
        if (o) {
            is = true;
            for (j = 0; j < n; ++j)
                if (l <= id[j] && id[j] <= r)
                    is &= (arr[j] > 0);
            if (is)
                for (j = 0; j < n; ++j)
                    if (l <= id[j] && id[j] <= r)
                        --arr[j];
        } else {
            for (j = 0; j < n; ++j)
                if (l <= id[j] && id[j] <= r)
                    ++arr[j];
        }
        for (ans = j = 0; j < n; ++j)
            ans += (arr[j] > 0);

        printf("%d\n", ans);
    }

    return 0;
}