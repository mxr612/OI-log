/**
 * LOJ #6278
 * 分块2
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (50300)

long long arr[MXN], sor[MXN], tag[MXN];
int pos[MXN] = {0}, pol[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a1.in", "r", stdin);
    FILE* ansf = fopen("a1.out", "r");
    int cnt = 0;
    long long anss;
#endif

    int n, siz, opt, l, r, ll, rr, mm;
    long long c, cc, ans;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), sor[i] = arr[i], pos[i] = (i - 1) / siz + 1;
    pos[n + 1] = pos[n];
    for (int i = 1; i <= n; i += siz)
        std::sort(&sor[pol[pos[i]] = i], &sor[i + siz]);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt) {
            ans = 0, c *= c;
            for (cc = c - tag[pos[l]]; l <= r && pos[l] == pos[l - 1]; ++l)
                if (arr[l] < cc)
                    ++ans;
            for (cc = c - tag[pos[r]]; l <= r && pos[r] == pos[r + 1]; --r)
                if (arr[r] < cc)
                    ++ans;
            for (; l <= r; l += siz) {
                cc = c - tag[pos[l]], ll = l, rr = l + siz;
                while (ll < rr)
                    if (sor[mm = (ll + rr) >> 1] < cc)
                        ll = mm + 1;
                    else
                        rr = mm;
                ans += rr - l;
            }
#ifndef ONLINE_JUDGE
            ++cnt;
            fscanf(ansf, "%lld", &anss);
            if (ans != anss)
                printf("%5d %15lld %15lld\n", cnt, anss, ans);
#else
            printf("%lld\n", ans);
#endif
        } else {
            if (l <= r && pos[l] == pos[l - 1]) {
                while (l <= r && pos[l] == pos[l - 1])
                    arr[l++] += c;
                for (int j = pol[pos[l - 1]]; j < pol[pos[l - 1]] + siz; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[pol[pos[l - 1]]], &sor[pol[pos[l - 1]] + siz]);
            }
            if (l <= r && pos[r] == pos[r + 1]) {
                while (l <= r && pos[r] == pos[r + 1])
                    arr[r--] += c;
                for (int j = pol[pos[r + 1]]; j < pol[pos[r + 1]] + siz; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[pol[pos[r + 1]]], &sor[pol[pos[r + 1]] + siz]);
            }
            for (; l <= r; l += siz)
                tag[pos[l]] += c;
        }
    }

    return 0;
}