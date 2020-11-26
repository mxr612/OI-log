/**
 * luogu 37784 A
 * hash
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

const int MXN = 200056,
          MD = 19260817;

int n, m, x, y, z;
char s[MXN];

long long mi[MXN] = {1};
int hash[40][MXN] = {};

int a[40], b[40];

inline long long mod(long long x) { return (x % MD + MD) % MD; }

bool ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);

    for (int i = 1, j; i <= n; ++i)
        for (++hash[s[i] - 'a'][i], mi[i] = (mi[i - 1] << 1) % MD, j = 0; j < 30; ++j)
            hash[j][i + 1] = (hash[j][i] << 1) % MD;

    while (m--) {
        ans = true;
        scanf("%d%d%d", &x, &y, &z);
        if (x < y) x ^= y ^= x ^= y;
        for (int i = 0; i < 30; ++i)
            a[i] = mod(hash[i][x + z - 1] - hash[i][x - 1] * mi[z]),
            b[i] = mod(hash[i][y + z - 1] - hash[i][y - 1] * mi[z]);
        std::sort(a, a + 30);
        std::sort(b, b + 30);
        for (int i = 0; i < 30; ++i)
            ans &= (a[i] == b[i]);
        printf("%s\n", (ans) ? ("YES") : ("NO"));
    }

    return 0;
}