/**
 * JZOJ2020.10.06A
 * B树的重心centroid
*/

#define MXN (50012)
#define MD (1000000007)

#include <stdio.h>
#include <stdlib.h>

#include <queue>

int N, K;
int* w;

struct Edge {
    int v;
    long long* VII;
    long long* XI;
    Edge *next,
        *rev;
}** edge = {};
int* ent;
Edge* add_edge(int u, int v) {
    Edge* x = NULL;
    while (!x) x = (Edge*)calloc(sizeof(Edge), 1);
    x->v = v, x->next = edge[u], edge[u] = x;
    ++ent[v];
    return x;
}
void rev_edge(Edge* x, Edge* y) {
    if (x && y) x->rev = y, y->rev = x;
}

// A
int is_sub_A() {
    for (int i = 1; i <= N; ++i)
        if (ent[i] == N - 1)
            return i;
    return 0;
}
long long ksm(long long a, long long b) {
    a %= MD, b %= (MD - 1);
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MD;
        a = (a * a) % MD;
        b >>= 1;
    }
    return res;
}

// B
int is_sub_B() {
    for (int i = 1; i <= N; ++i)
        if (ent[i] > 2)
            return 0;
    for (int i = 1; i <= N; ++i)
        if (ent[i] == 1)
            return i;
}

// III, VII
void dfs_I(int x, int fa, long long* dp) {
    dp[1] = 1;
    for (Edge* i = edge[x]; i; i = i->next)
        if (i->v != fa) {
            i->VII = (long long*)calloc(sizeof(long long), K + 16);
            dfs_I(i->v, x, i->VII);
            for (int j = K, k; j > 0; --j)
                for (k = 1; j - k > 0; ++k)
                    dp[j] = (dp[j] + dp[j - k] * i->VII[k]) % MD;
        }
}
void dfs_II(int x, int fa, long long** dp) {
    for (Edge* i = edge[x]; i; i = i->next)
        if (i->v != fa) {
            i->rev->VII = (long long*)calloc(sizeof(long long), K + 16);
            for (int j = 1, k; j <= K; ++j)
                for (i->rev->VII[j] = dp[x][j], k = 1; k < j; ++k)
                    i->rev->VII[j] = ((i->rev->VII[j] - i->rev->VII[k] * i->VII[j - k]) % MD + MD) % MD;
            for (int j = 1; j <= K; ++j)
                dp[i->v][j] = i->VII[j];
            for (int j = K, k; j > 0; --j)
                for (k = 1; k < j; ++k)
                    dp[i->v][j] = (dp[i->v][j] + dp[i->v][k] * i->rev->VII[j - k]) % MD;
            dfs_II(i->v, x, dp);
        }
}

signed main() {
    freopen("centroid1-1.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("centroid.out", "w", stdout);
#endif

    int x;

    scanf("%d%d", &N, &K);

    w = (int*)calloc(sizeof(int), N + 32);
    edge = (Edge**)calloc(sizeof(Edge*), N + 32);
    ent = (int*)calloc(sizeof(Edge*), N + 32);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &w[i]);
    for (int i = 1, u, v; i < N; ++i)
        scanf("%d%d", &u, &v), rev_edge(add_edge(u, v), add_edge(v, u));

    if (x = is_sub_A()) {  //SubA
        if (K == 1) {
            long long ans = 0;
            for (int i = 1; i <= N; ++i)
                ans = (ans + w[i]) % MD;
            printf("%lld", ans);
        } else if (K == 2) {
            long long ans = 0;
            for (Edge* i = edge[x]; i; i = i->next)
                ans = (ans + w[std::min(x, i->v)]) % MD;
            printf("%lld", ans);
        } else {
            long long* mi = (long long*)calloc(sizeof(long long), N + 32);
            long long* ny = (long long*)calloc(sizeof(long long), N + 32);
            mi[0] = ny[1] = 1;
            for (int i = 1; i <= N; ++i)
                mi[i] = (mi[i - 1] * i) % MD;
            ny[N] = ksm(mi[N], MD - 2);
            for (int i = N - 1; i > 0; --i)
                ny[i] = (ny[i + 1] * (i + 1)) % MD;
            printf("%lld", (((((w[x] * mi[N - 1]) % MD) * ny[K - 1]) % MD) * ny[N - K]) % MD);
        }
    } else if (x = is_sub_B()) {  //SubB
        bool* vis = (bool*)calloc(sizeof(bool), N + 32);
        int *pl = (int*)calloc(sizeof(int), N + 32), tot = 0;
        long long ans = 0;
        std::queue<int> que;
        que.push(x);
        while (que.size()) {
            pl[++tot] = que.front(), vis[que.front()] = true;
            for (Edge* i = edge[que.front()]; i; i = i->next)
                que.push(i->v);
            while (que.size() && vis[que.front()]) que.pop();
        }
        for (int i = 1; i + K - 1 <= N; ++i)
            ans = (ans + w[std::min(pl[i + (K - 1) / 2], pl[i + K / 2])]) % MD;
        printf("%lld", ans);
    } else if (N <= 5000 || K <= 100) {  //SubIII, VII
        long long** f = (long long**)calloc(sizeof(long long*), N + 16);
        long long** ans = (long long**)calloc(sizeof(long long*), N + 32);
        long long answ = 0;
        for (int i = 1; i <= N; ++i)
            f[i] = (long long*)calloc(sizeof(long long), K + 16),
            ans[i] = (long long*)calloc(sizeof(long long), K + 16);
        dfs_I(1, 0, f[1]), dfs_II(1, 0, f);
        for (int i = 1, k, l; i <= N; ++i)
            for (Edge* j = edge[i]; j; j = j->next)
                for (ans[i][1] = 1, k = K; k > 0; --k)
                    for (l = K / 2; l > 0; --l)
                        ans[i][k] = (ans[i][k] + ans[i][k - l] * j->VII[l]) % MD;
        for (int i = 1; i <= N; ++i) answ = (answ + ans[i][K] * w[i]) % MD;
        printf("%lld", answ);
    } else {
    }
    return 0;
}