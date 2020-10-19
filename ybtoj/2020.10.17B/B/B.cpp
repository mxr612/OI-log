
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

signed main() {
    freopen("b.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("b.out", "w", stdout);
#endif

    int k;
    int now, n;
    std::vector<int> ope, due;

    while (scanf("%d", &k) != EOF) {
        n = 1, now = 0;
        ope.clear();
        due.clear(), due.push_back(0);

        while (k) {
            if (k & 1) ope.push_back(1);
            if (k >>= 1) ope.push_back(0);
        }

        for (std::vector<int>::reverse_iterator i = ope.rbegin() + 1; i != ope.rend(); ++i)
            if (++n, *i)
                ++now, due.push_back(1);
            else
                ++due[now];
        printf("%d\n", n);
        for (int i = now, j, x = 1, tot = 1; i >= 0; --i, x = tot)
            for (j = 0; j < due[i]; ++j)
                printf("%d %d\n", x, ++tot);
    }

    return 0;
}