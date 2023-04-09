#include <stdio.h>

int a[300100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int t, n;

    long long p[2];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        if (n % 2) {
            printf("YES\n");
        } else {
            p[0] = p[1] = 0;
            for (int i = 1; i < n; ++i)
                p[i % 2] += a[i] - a[i - 1];
            if (p[1] < 0)
                printf("NO\n");
            else
                printf("YES\n");
            // printf("%d %d\n", p[0], p[1]);
        }
    }

    return 0;
}