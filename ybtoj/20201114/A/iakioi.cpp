/**
 * iakioi
*/

#include <stdio.h>

#include <algorithm>
#include <bitset>

const int MXN = 100024;

std::pair<int, int> arr[MXN];

std::bitset<MXN> R, C;

signed main() {
    freopen("iakioi.in", "r", stdin);
    freopen("iakioi.out", "w", stdout);

    int T, n, m, q, ans;

    scanf("%d", &T);

    while (T--) {
        R.reset(), C.reset(), ans = 0;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 0; i < q; ++i)
            scanf("%d%d", &arr[i].first, &arr[i].second);
        std::sort(arr, arr + q);
        for (int i = 0; i < q; ++i)
            if (!R[arr[i].first] && !C[arr[i].second])
                ++ans, R[arr[i].first] = C[arr[i].second] = true;
        printf("%d\n", ans);
    }

    return 0;
}