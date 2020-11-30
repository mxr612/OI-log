/**
 * portal
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

const int MXN = 100024;

int n, d;

std::vector<std::pair<int, int> > R, B;

signed main() {
    freopen("portal.in", "r", stdin);
    freopen("portal.out", "w", stdout);

    scanf("%d%d", &n, &d);

    for (int i = 0, x, y; i < n; i = ++i)
        scanf("%d%d", &x, &y), R.push_back(std::make_pair(x, y));
    for (int i = 0, x, y; i < n; i = ++i)
        scanf("%d%d", &x, &y), B.push_back(std::make_pair(x, y));

    for (int i = 0, j, res; i < n; ++i) {
        for (res = 1e9, j = 0; j < n; ++j)
            if (abs(R[i].second - B[j].second) <= d)
                res = std::min(res, abs(R[i].first - B[j].first) + abs(R[i].second - B[j].second));
        printf("%d\n", (res == 1e9) ? (-1) : (res));
    }

    return 0;
}
