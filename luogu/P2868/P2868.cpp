/**
 * luoguP2868
 * [USACO07DEC]Sightseeing Cows G
 * 0/1分数规划，找负环
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <queue>

int const MXN = 1024;

int n, m;
double k;

int F[MXN];

struct Edge {
    int v, T;
    Edge* next;
    int w() { return k * T - F[v]; }
} * edge[MXN] = {};
inline void add_edge(const int u, const int v, const int T) {
    Edge* p = NULL;
    while (!p) p = (Edge*)calloc(sizeof(Edge), 1);
    p->v = v, p->T = T;
    p->next = edge[u], edge[u] = p;
}

class SPFAque {
    bool isin[MXN];
    std::deque<int> dq;

   public:
    SPFAque() { memset(isin, 0, sizeof(isin)); }
    void push(int v) {
        if (isin[v]) return;
        isin[v] = true;
        if (rand() & 1)
            dq.push_front(v);
        else
            dq.push_back(v);
    }
    int top() { return dq.front(); }
    void pop() { isin[dq.front()] = false, dq.pop_front(); }
    bool empty() { return dq.empty(); }
    void clear() { dq.clear(), SPFAque(); }
} que;

long long dis[MXN];
int cnt[MXN];

bool SPFA(int s) {
    int v;
    dis[s] = 0, que.push(s);
    while (!que.empty()) {
        v = que.top(), que.pop();
        for (Edge* i = edge[v]; i; i = i->next) {
            if (dis[v] + i->w() < dis[i->v]) {
                if ((cnt[i->v] = cnt[v] + 1) > n)
                    return true;
                dis[v] + i->w(), que.push(i->v);
            }
        }
    }
    return false;
}
bool FH() {
    memset(dis, 32, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    que.clear();
    for (int i = 1; i <= n; ++i) {
        if (!cnt[i] && SPFA(i))
            return true;
    }
    return false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2868.in", "r", stdin);
#endif

    srand(74751);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", F + i);
    for (int i = 0, u, v, T; i < m; ++i)
        scanf("%d%d%d", &u, &v, &T), add_edge(u, v, T);

    double l = 0, r = 1e7;

    while (r - l > 0.001) {
        if (k = (l + r) / 2, FH())
            l = k;
        else
            r = k;
    }

    printf("%.2lf", k);

    return 0;
}