/**
 * lcs
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>

char A[1000024], B[1000024];
int la, lb;

int next[1000024][30], g[1024][1024];

signed main() {
    freopen("lcs.in", "r", stdin);
    freopen("lcs.out", "w", stdout);

    memset(g, 127, sizeof(g));

    scanf("%s%s", A + 1, B + 1);
    la = strlen(A + 1), lb = strlen(B + 1);

    for (int i = 0, j; i <= 'z' - 'a'; ++i)
        for (next[la][i] = g[0][0], j = la - 1; j >= 0; --j)
            next[j][i] = (A[j + 1] - 'a' == i) ? (j + 1) : (next[j + 1][i]);

    g[0][0] = 0;
    for (int i = 0, j; i <= lb; ++i)
        for (j = 0; j < lb; ++j)
            if (g[i + 1][j] = std::min(g[i + 1][j], g[i][j]), g[i][j] <= la)
                g[i + 1][j + 1] = std::min(g[i + 1][j + 1], next[g[i][j]][B[i + 1] - 'a']);

    for (int i = lb; i >= 0; --i)
        if (g[lb][i] <= la)
            return printf("%d", i), 0;

    return 0;
}