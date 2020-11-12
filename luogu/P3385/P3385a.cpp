/**
 * luoguP3385
 * SPFA找负环
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <queue>

const int MXN = 2048;

template <typename TYP>
class MemPool {
    const int SIZ = 1000;
    TYP *p, *e;
    TYP*& get_mem() {
        p = NULL;
        while (!p) p = (TYP*)calloc(sizeof(TYP), SIZ);
        e = p + SIZ;
        return p;
    }

   public:
    MemPool() { p = e = NULL; }
    TYP* operator()() { return (p < e) ? (p++) : (get_mem()++); }
};

struct Edge {
    int v, w;
    Edge* next;
} * edge[MXN];

MemPool<Edge> mp;
void add_edge(const int u, const int v, const int w) {
    Edge* p = mp();
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

class SPFAque {
    std::deque<int> dq;
    bool isin[MXN];
    int ww[MXN];
    long long sum, siz;

   public:
    SPFAque() { sum = siz = 0, memset(isin, 0, sizeof(isin)); }
    bool empty() { return !siz; }
    void push(int x, long long w) {
        if (isin[x]) return;
        if (empty())
            dq.push_back(x);
        else {
            if (w * siz < sum)
                dq.push_front(x);
            else
                dq.push_back(x);
        }
        ++siz, sum += (ww[x] = w), isin[x] = true;
    }
    int front() { return dq.front(); }
    void pop() {
        if (!empty()) --siz, sum -= ww[dq.front()], isin[dq.front()] = false, dq.pop_front();
    }
    void clear() { dq.clear(), SPFAque(); };
};

int n, m;

long long dis[MXN];
int cnt[MXN];
SPFAque que;
bool SPFA() {
    memset(dis, 32, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    que.clear();

    int v;
    que.push(1, dis[1] = 0);
    while (!que.empty()) {
        v = que.front(), que.pop();
        for (Edge* i = edge[v]; i; i = i->next) {
            if (dis[v] + i->w < dis[i->v]) {
                if ((cnt[i->v] = cnt[v] + 1) > n)
                    return true;
                que.push(i->v, dis[i->v] = dis[v] + i->w);
            }
        }
    }
    return false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3385.in", "r", stdin);
#endif

    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0, u, v, w; i < m; ++i)
            if (scanf("%d%d%d", &u, &v, &w), add_edge(u, v, w), w > 0)
                add_edge(v, u, w);
        printf("%s\n", (SPFA()) ? ("YES") : ("NO"));
    }

    return 0;
}