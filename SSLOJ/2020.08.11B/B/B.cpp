#include <stdio.h>

#include <queue>
#include <vector>

#define MXN (400)

int n, ans;
struct Edge {
    int u, v, w;
    bool operator<(const Edge e) const { return w > e.w; }
} top;

int bin[MXN];

int fa(int x){
	return (bin[x]==x)?(x):(bin[x]=fa(bin[x]));
}

std::priority_queue<Edge> edge;

bool vis[MXN];

signed main() {
    freopen("B.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 1, w; i <= n; ++i)
        scanf("%d", &w), edge.push({0, i, w}), edge.push({i, 0, w}),bin[i]=i;
    for (int i = 1, j, w; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%d", &w), edge.push({i, j, w});

    for (int i = 0; i < n; ++i) {
        while(!edge.empty()&& fa(edge.top().u)==fa(edge.top().v) ) edge.pop();
        if(!edge.empty())bin[fa(edge.top().u)]=fa(edge.top().v),ans+=edge.top().w;
    }

    printf("%d", ans);

    return 0;
}
