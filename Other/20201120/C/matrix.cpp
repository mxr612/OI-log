/**
 * matrix
*/

#include <stdio.h>

const int MD = 998244353;

short arr[5000000];
long long n, ans;

bool check() {
    for (int i = 1, j; i <= n; ++i) {
        for (j = n + i; j <= n * n; j += n)
            if (arr[j] != arr[i])
                break;
        if (j > n * n) return true;
    }
    for (int i = 1, j; i <= n; ++i) {
        for (j = (i - 1) * n + 1; j < i * n; ++j)
            if (arr[j] != arr[(i - 1) * n] + 1)
                break;
        if (j >= i * n) return true;
    }
    return false;
}

void dfs(int dep) {
    if (dep) {
        arr[dep] = 0, dfs(dep - 1);
        arr[dep] = 1, dfs(dep - 1);
        arr[dep] = 2, dfs(dep - 1);
    } else {
        ans = (ans + check()) % MD;
    }
}

int answ[10] = {0, 3, 63, 9173, 9986505};

signed main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);

    // for (n = 1; n <= 4; ++n)
    //     printf("%lld\n", (ans = 0, dfs(n * n), ans));

    scanf("%d", &n);
    // printf("%d", (n < 0) ? (0) : (answ[n]));

    if (n <= 4) printf("0")

        return 0;
}