/**
 * lcs
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 1000024;

char A[MXN], B[MXN];
int la, lb;

int DP[100024][1024] = {};

signed main() {
    freopen("lcs.in", "r", stdin);
    freopen("lcs.out", "w", stdout);

    scanf("%s%s", A + 1, B + 1);
    la = strlen(A + 1), lb = strlen(B + 1);

    for (int i = 1, j; i <= la; ++i)
        for (j = 1; j <= lb; ++j)
            if (DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]), A[i] == B[j])
                DP[i][j] = std::max(DP[i][j], DP[i - 1][j - 1] + 1);

    printf("%d", DP[la][lb]);

    return 0;
}