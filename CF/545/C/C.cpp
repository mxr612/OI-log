/**
 * CF545C
 * Woodcutters
 * 贪心
*/

#include <stdio.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int n, ans = 2;

    struct Tree {
        int x, y;
        bool operator<(const Tree T) const { return x < T.x; };
    } * tree;

    scanf("%d", &n);

    if (n == 1) return printf("1"), 0;

    tree = (Tree*)calloc(sizeof(Tree), n + 32);

    for (int i = 0; i < n; ++i)
        scanf("%d%d", &tree[i].x, &tree[i].y);

    std::sort(tree, tree + n);

    for (int i = 1; i < n - 1; ++i)
        if (tree[i - 1].x < tree[i].x - tree[i].y)
            ++ans;
        else if (tree[i].x + tree[i].y < tree[i + 1].x)
            ++ans, tree[i].x += tree[i].y;

    printf("%d", ans);

    return 0;
}
