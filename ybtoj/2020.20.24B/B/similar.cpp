
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <queue>

const int MXN = 200056;

char S[MXN], T[MXN];
int arr[MXN], ans[MXN];
struct Query {
    int l, w, d;
    bool operator<(const Query Q) const { return l < Q.l; }
} query[MXN];
int res[MXN];

signed main() {
#ifdef ONLINE_JUDGE
    freopen("similar.in", "r", stdin);
    freopen("similar.out", "w", stdout);
#endif

    int n, q;

    scanf("%s", S + 1);

    for (n = 1; S[n]; ++n)
        arr[n] = arr[n - 1] + S[n] - '0';

    scanf("%d", &q);

    for (int i = 0, j, s; i < q; ++i) {
        scanf("%s", T);
        for (s = 0, j = 0; T[j]; ++j)
            s += T[j] - '0';
        query[i].l = j, query[i].w = s, query[i].d = i;
    }
    std::sort(query, query + q);

    for (int i = 0, j, l; i < q;) {
        l = query[i].l;
        memset(res, 0, sizeof(int) * (l + 16));
        for (j = 0; j + l < n; ++j)
            ++res[arr[j + l] - arr[j]];
        while (i < q && query[i].l == l)
            ans[query[i].d] = res[query[i].w], ++i;
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}