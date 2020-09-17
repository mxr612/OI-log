/**
 * ybtoj2020.09.05B
 * C合影队形photo
*/

#define MXN (200020)

#include <stdio.h>
#include <string.h>

#include <queue>

int T;
int n, m, p;

int edge[MXN], ind[MXN];

std::queue<int> que;

long long f[MXN];
int l[MXN];

long long ksm(long long x, long long y, long long p) {
    long long res = 1;
    y %= p - 1;
    while (y) {
        if (y & 1) res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

long long jc[MXN], ny[MXN];
inline int C(int n, int m, int p) { return (((jc[n] * ny[m]) % p) * ny[n - m]) % p; }

bool is;

signed main() {
    freopen("photo.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("photo.out", "w", stdout);
#endif

    scanf("%d", &T);

    register int x, y;
    while (T--) {
        scanf("%d%d%d", &n, &m, &p);

        memset(edge, 0, sizeof(edge));
        memset(ind, 0, sizeof(ind));
        memset(l, 0, sizeof(l));
        jc[0] = ny[0] = 1;
        for (int i = 1; i <= n; ++i)
            jc[i] = (jc[i - 1] * i) % p;
        ny[n] = ksm(jc[n], p - 2, p);
        for (int i = n - 1; i > 0; --i)
            ny[i] = (ny[i + 1] * (i + 1)) % p;

        for (int i = 0, x, y; i < m; ++i)
            scanf("%d%d", &x, &y), edge[x] = y, ++ind[y];
        for (int i = 1; i <= n; ++i)
            if (!ind[i])
                que.push(i);
        for (int i = 0; i <= n; ++i) f[i] = 1;
        while (!que.empty()) {
            y = edge[x = que.front()], que.pop();
            ++l[x];
            f[y] = (((f[x] * f[y]) % p) * C(l[x] + l[y], l[x], p)) % p;
            l[y] += l[x];
            // printf("%d %d %d\n", x, f[x], l[x]);
            if (y && --ind[y] == 0) que.push(y);
        }
        is = false;
        for (int i = 1; i <= n; ++i)
            is |= ind[i];
        printf("%d\n", (is) ? (0) : (f[0]));
    }

    return 0;
}