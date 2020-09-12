/**
 * 
*/

#define MXN (300020)

#include <stdio.h>

#include <algorithm>

int n, t;
long long a[MXN], b[MXN], ans;

long long gcd(long long a, long long b) { return (b == 0) ? (a) : (gcd(b, a % b)); }

// Sub2
bool vis[20];
long long res;
void dfs(int dep) {
    if (dep < 0) {
        ans = std::max(ans, res);
    } else {
        dfs(dep - 1);
        for (int i = 0; i < n; ++i) {
            if (vis[i] &&) {
                vis[dep] = true, res += a[dep];
                dfs(dep - 1);
                vis[dep] = false, res -= a[dep];
            }
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    std::sort(a, a + n);

    if (n == 1)
        printf("%lld", a[0]);
    else if (n == 2) {
        if (a[0] == a[1] || a[0] + a[1] + gcd(a[0], a[1]) == a[0] * a[1] / gcd(a[0], a[1]))
            printf("%lld", a[0] + a[1]);
        else
            printf("%lld", std::max(a[0], a[1]));
    } else if (n <= 17) {
        dfs(n - 1);
    }

    return 0;
}