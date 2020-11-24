/**
 * column
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>

const int MXN = 1024;

double r[MXN], x[MXN], ans;

signed main() {
    freopen("column.in", "r", stdin);
    freopen("column.out", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0, j; i < n; ++i)
        for (scanf("%lf", r + i), x[i] = r[i], j = 0; j < i; ++j)
            x[i] = std::max(x[i], x[j] + sqrt((r[i] + r[j]) * (r[i] + r[j]) - (r[i] - r[j]) * (r[i] - r[j]))),
            ans = std::max(ans, x[i] + r[i]);

    printf("%.3lf", ans);

    return 0;
}