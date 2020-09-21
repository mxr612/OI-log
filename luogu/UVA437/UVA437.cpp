/**
 * luogu UVA437
*/

#define MXN (50)

#include <stdio.h>
#include <string.h>

#include <vector>

int t, n;

class Graph {
    struct Node {
        int x, y, z;
    } node[3 * MXN];
    int top = 0;
    std::vector<int> edge[3 * MXN];
    int inde[MXN] = {};

   public:
    void clear() {
        top = 0;
    }
    void add(int x, int y, int z) {
        node[++top] = Node{std::max(x, y), std::min(x, y), z};
        edge[top].clear(), inde[top] = 0;
        for (int i = 1; i < top; ++i)
            if ((node[i].x < node[top].x && node[i].y < node[top].y))
                edge[top].push_back(i), ++inde[i];
            else if ((node[i].x > node[top].x && node[i].y > node[top].y))
                edge[i].push_back(top), ++inde[top];
    }
} graph;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("UVA437.in", "r", stdin);
#endif

    while (scanf("%d", &n), n) {
        graph.clear();
        for (int i = 0, x, y, z; i < n; ++i)
            scanf("%d%d%d", &x, &y, &z), graph.add(x, y, z), graph.add(y, z, x), graph.add(z, x, y);

        printf("Case %d: maximum height = 40\n", ++t);
    }

    return 0;
}
