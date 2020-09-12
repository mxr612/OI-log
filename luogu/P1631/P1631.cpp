/**
 * luoguP1631
*/

#define MXN (100020)

#include <stdio.h>

#include <queue>

int n, a[MXN], b[MXN];

struct Node {
    int s, p;
    bool operator<(const Node x) const { return s > x.s; }
} cmp;

std::priority_queue<Node> pq;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1631.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    for (int i = 0; i < n; ++i)
        pq.push(Node{a[i] + b[0], 0});

    for (int i = 0; i < n; ++i) {
        cmp = pq.top(), pq.pop();
        printf("%d ", cmp.s);
        if (++cmp.p < n)
            cmp.s += b[cmp.p] - b[cmp.p - 1], pq.push(cmp);
    }

    return 0;
}