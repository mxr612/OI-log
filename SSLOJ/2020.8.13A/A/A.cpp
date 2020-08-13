
#define MXN (100020)
#define MXA (1000020)
#define MXP (80000)
#define MOD (1000000007)

#include <math.h>
#include <stdio.h>
#include <string.h>

int pr[MXP], p = 0;
bool np[MXA];

long long mi[MXN];

int t;

int apr[MXA];

class Bin {
    int fa[MXA];

   public:
    int cnt;
    void make(int x) { fa[x] = x, ++cnt; }
    int find(int x) { return (fa[x] == x) ? (x) : (fa[x] = find(fa[x])); }
    void merge(int x, int y) {
        if (find(x) != find(y)) fa[find(x)] = find(y), --cnt;
    }
    long long query() { return cnt; }
} bin;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    for (int i = 2, j; i < MXA; ++i) {
        if (!np[i]) pr[p++] = i;
        for (j = 0; j < p && i * pr[j] < MXA; ++j) np[i * pr[j]] = true;
    }

    mi[0] = 1;
    for (int i = 1; i < MXN; ++i)
        mi[i] = (mi[i - 1] << 1) % MOD;

    scanf("%d", &t);

    for (int i, j, n, a; t-- > 0;) {
        bin.cnt = 0;
        memset(apr, 0, sizeof(apr));
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a == 1) ++bin.cnt;
            if (apr[a] || a == 1) continue;
            bin.make(a);
            apr[a] = true;
        }
        for (i = 0; i < p; ++i) {
            for (a = j = 0; j < MXA; j += pr[i]) {
                if (apr[j]) {
                    if (apr[a]) bin.merge(a, j);
                    a = j;
                }
            }
        }
        printf("%lld\n", (bin.cnt < 2) ? (0) : ((mi[bin.cnt] + MOD - 2) % MOD));
    }

    return 0;
}
