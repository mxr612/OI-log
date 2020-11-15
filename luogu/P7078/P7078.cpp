
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <set>

const int MXN = 1000024;

int max[MXN], min[MXN], tot = 1;
bool die[MXN];
std::set<std::pair<int, int> > set;

void dfs(int n) {
    int w;
    min[n] = set.begin()->second, max[n] = set.rbegin()->second;
    if (n > 1) {
        die[min[n]] = true;
        w = set.rbegin()->first - set.begin()->first;
        set.erase(set.begin()), set.erase(*set.rbegin());
        set.insert(std::make_pair(w, max[n]));
        dfs(n - 1);
        if (die[max[n]])
            while (tot < n)
                die[min[++tot]] = false;
    }
}

int arr[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P7078.in", "r", stdin);
#endif
    int T, n, k;

    scanf("%d", &T);

    --T;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i), set.insert(std::make_pair(arr[i], i));
    dfs(n);
    printf("%d\n", tot);

    while (T--) {
        memset(die, 0, sizeof(die));
        set.clear();
        tot = 1;
        scanf("%d", &k);
        for (int i = 0, v, w; i < k; ++i)
            scanf("%d", &v), scanf("%d", arr + v);
        for (int i = 1; i <= n; ++i)
            set.insert(std::make_pair(arr[i], i));
        dfs(n);
        printf("%d\n", tot);
    }

    return 0;
}
