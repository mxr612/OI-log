/**
 * function
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

const double e = exp(1);
const long long MD = 998244353;

int T, n;

int mem[1024][1024];

int f(int a, int b) {
    if (mem[a][b]) return mem[a][b];
    return mem[a][b] = ((n - a * e - 2 * b < 3) ? (1) : ((f(a + 1, b) + f(a, b + 1)) % MD));
}

signed main() {
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);

    for (scanf("%d", &T); T--;) {
        memset(mem, 0, sizeof(mem));
        scanf("%d", &n);
        printf("%d\n", f(0, 0));
    }

    return 0;
}