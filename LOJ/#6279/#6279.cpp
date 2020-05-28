/**
 * LOJ #6279
 * 分块3
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

const int MXN = 101000;
const long long SUP = -(1ll << 32);

long long arr[MXN], sor[MXN], tag[MXN] = {0};
int pos[MXN] = {0};
bool sod[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a1.in", "r", stdin);
    FILE* ansf = fopen("a1.out", "r");
    long long anss;
    int cnt = 0;
#endif

    int n, siz, opt, l, r, ll, rr, mm;
    long long c, ans, cc;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), sod[pos[i] = (i - 1) / siz + 1] = true;
    pos[n + 1] = pos[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt) {  //==1
            ans = SUP;
            for (cc = c - tag[pos[l]]; l <= r && pos[l] == pos[l - 1]; ++l)
                if (arr[l] < cc)
                    ans = std::max(ans, arr[l] + tag[pos[l]]);
            for (cc = c - tag[pos[r]]; l <= r && pos[r] == pos[r + 1]; --r)
                if (arr[r] < cc)
                    ans = std::max(ans, arr[r] + tag[pos[r]]);
            for (; l <= r; l += siz) {
                cc = c - tag[pos[l]], ll = l, rr = l + siz;
                if (sod[pos[l]]) {
                    for (int j = ll; j < rr; ++j)
                        sor[j] = arr[j];
                    std::sort(&sor[ll], &sor[rr]);
                    sod[pos[l]] = false;
                }
                while (ll < rr)
                    if (sor[mm = (ll + rr) >> 1] < cc)
                        ll = mm + 1;
                    else
                        rr = mm;
                if (rr > l)
                    ans = std::max(ans, sor[rr - 1] + tag[pos[l]]);
            }
            if (ans == SUP)
                ans = -1;
#ifndef ONLINE_JUDGE
            ++cnt;
            fscanf(ansf, "%lld", &anss);
            if (ans != anss)
                printf("%10d %20lld %20lld\n", cnt, anss, ans);
#else
            printf("%lld\n", ans);
#endif
        } else {
            if (l <= r && pos[l] == pos[l - 1]) {
                sod[pos[l]] = true;
                while (l <= r && pos[l] == pos[l - 1])
                    arr[l++] += c;
            }
            if (l <= r && pos[r] == pos[r + 1]) {
                sod[pos[r]] = true;
                while (l <= r && pos[r] == pos[r + 1])
                    arr[r--] += c;
            }
            for (; l <= r; l += siz)
                tag[pos[l]] += c;
        }
    }

    return 0;
}