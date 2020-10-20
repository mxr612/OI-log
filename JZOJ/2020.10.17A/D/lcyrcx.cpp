/**
 * JZOJ2020.10.17A
 * D
 * 博弈問題，除去特殊情況，所有情況可以化爲兩個不相交的k*k矩形，考慮除去這兩個kk矩形的其他0點（可操作點）的奇偶性
*/

#define MXN (1024)

#include <stdio.h>

#include <algorithm>

int n, k;
int arr[MXN][MXN];
char s[MXN];

inline int get_sum(int x, int y) {
    return arr[x][y] - arr[x - k][y] - arr[x][y - k] + arr[x - k][y - k];
}

inline bool in(int a, int b, int c, int d) {
    return (c - k + 1 <= a && a <= c) && (d - k + 1 <= b && b <= d);
}

inline bool is(int a, int b, int c, int d) {
    return in(a, b, c, d) || in(a - k + 1, b, c, d) || in(a, b - k + 1, c, d) || in(a - k + 1, b - k + 1, c, d);
}

signed main() {
    freopen("lcyrcx.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("lcyrcx.out", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    int cnt = n * n;

    for (int i = 1, j; i <= n; ++i)
        for (scanf("%s", s + 1), j = 1; j <= n; ++j)
            cnt -= arr[i][j] = s[j] - '0',
                   arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];

    int xI = 0, yI, xII = 0, yII;

    for (int i = k, j; !xI && i <= n; ++i)
        for (j = k; !xI && j <= n; ++j)
            if (!get_sum(i, j))
                xI = i, yI = j;

    if (!xI) {
        printf("yc");
        return 0;
    }

    for (int i = k, j; !xII && i <= n; ++i)
        for (j = k; !xII && j <= n; ++j)
            if (!get_sum(i, j) && !is(xI, yI, i, j))
                xII = i, yII = j;

    if (!xII) {
        printf("rx");
        return 0;
    }

    if ((cnt - k * k * 2) & 1)
        printf("rx");
    else
        printf("yc");

    return 0;
}