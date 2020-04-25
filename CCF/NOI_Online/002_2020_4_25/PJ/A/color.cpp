/**
 * NOI Online 2
 * A
 * color
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

int T, k;
double x, y;

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while (--T >= 0) {
        scanf("%lf%lf%d", &x, &y, &k);
        if (x < y)
            std::swap(x, y);
        printf("%s\n", (ceil(((std::max(x, y) - 1) / std::min(x, y))) < k)
                           ? ("Yes")
                           : ("No"));
    }

    return 0;
}