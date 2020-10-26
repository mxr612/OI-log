
#include <stdio.h>
#include <stdlib.h>

const int MXN = 50012;

double x[MXN], y[MXN];

signed main() {
#ifdef ONLINE_JUDGE
    freopen("sight.in", "r", stdin);
    freopen("sight.out", "w", stdout);
#endif

    int n, ans = 0;
    double r, A, C;

    scanf("%d%lf", &n, &r);

    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);

    for (int i = 0, j; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (x[i] != x[j]) {
                A = -(y[i] - y[j]) / (x[i] - x[j]);
                C = -y[i] - A * x[i];
                if (C * C - r * r * (A * A + 1) > 0) ++ans;
            } else {
                if (abs(x[i]) - r > 0) ++ans;
            }
        }
    }

    printf("%d", ans);

    return 0;
}