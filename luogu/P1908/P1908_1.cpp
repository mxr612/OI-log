/**
 * P1908_1
 * 逆序对
 * 归并排序
 */

#include <stdio.h>

#include <algorithm>

// 500020

#define MXN (1000020)

int n;
unsigned long long ans = 0;
struct __LSH {
    int u, id, v;
} LSH[MXN];
bool _cmp_1(register __LSH x, register __LSH y) {
    return x.u < y.u;
}
bool _cmp_2(register __LSH x, register __LSH y) {
    return x.id < y.id;
}
int arr[MXN];

int help[MXN];
void _sort(int l, int r) {
    if (r <= l)
        return;
    _sort(l, (l + r) >> 1), _sort(((l + r) >> 1) + 1, r);
    register int m = (l + r) >> 1, a = l, b = m + 1, c = l;
    while (c <= r) {
        if (a > m || (b <= r && arr[b] < arr[a]))
            help[c++] = arr[b++], ans += m - a + 1;
        else
            help[c++] = arr[a++];
    }
    for (c = l; c <= r; ++c)
        arr[c] = help[c];
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1908_11.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (register int i = 0; i < n; ++i)
        scanf("%d", &LSH[i].u), LSH[i].id = i;
    std::sort(LSH, LSH + n, _cmp_1);
    for (register int i = 1, v = 0; i < n; ++i)
        LSH[i].v = ((LSH[i - 1].u < LSH[i].u) ? (++v) : (v));
    std::sort(LSH, LSH + n, _cmp_2);
    for (register int i = 0, v = 0; i < n; ++i)
        arr[i] = LSH[i].v;

    _sort(0, n - 1);

    // for (register int i = 0; i < n; ++i)
    //     printf("%d\n", arr[i]);

    printf("%llu\n", ans);

    return 0;
}