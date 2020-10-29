/**
 * luogu36343
 * 校测 51Nod
 * Abiscuit破碎的饼干
 * 给出四块饼干要求填色拼装后相邻格子颜色(01)不同
 * 每个饼干只有两种染色方式, 计算出来之后枚举拼装即可
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int n, brr[4][2], ans = 50000;
char *s;

void pre_b(int *b) {
    for (int i = 0, j; i < n; ++i)
        for (scanf("%s", s), j = 0; j < n; ++j)
            ++b[(~(i + j) & 1) ^ (s[j] - '0')];
}

void dfs(int d, int is, int vis, int sum) {
    if (d > 3) ans = std::min(ans, sum);
    for (int i = 0; i < 4; ++i)
        if (!(vis & (1 << i)))
            dfs(d + 1, !is, vis | (1 << i), sum + brr[i][is]);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("biscuit.in", "r", stdin);
#endif

    scanf("%d", &n);

    s = (char *)calloc(sizeof(char), n + 32);

    for (int i = 0; i < 4; ++i)
        pre_b(brr[i]);

    printf("%d", (dfs(0, 0, 0, 0), dfs(0, 1, 0, 0), ans));

    return 0;
}