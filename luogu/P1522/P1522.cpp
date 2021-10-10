#include <math.h>
#include <stdio.h>

#include <algorithm>

const int MXN = 160;
const double MXI = 1e15;

int N;
char s[MXN];
int C[MXN];
double V[MXN][2], E[MXN][MXN];
double MV[MXN], MC[MXN];
double ans = MXI;

double dis(int i, int j) {
    return sqrt((V[i][0] - V[j][0]) * (V[i][0] - V[j][0]) + (V[i][1] - V[j][1]) * (V[i][1] - V[j][1]));
}

void color(int x) {
    MC[C[x]] = std::max(MC[C[x]], MV[x]);
    for (int i = 0; i < N; ++i) {
        if (!C[i] && E[x][i] != MXI) {
            C[i] = C[x];
            color(i);
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1522.in", "r", stdin);
#endif

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%lf%lf", &V[i][0], &V[i][1]);
    for (int i = 0, j; i < N; ++i) {
        scanf("%s", s);
        for (j = 0; j < N; ++j) {
            if (s[j] - '0')
                E[i][j] = dis(i, j);
            else
                E[i][j] = MXI;
        }
    }

    for (int i, j, k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                E[i][j] = std::min(E[i][j], E[i][k] + E[k][j]);
            }
        }
    }

    for (int i = 0, j; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (E[i][j] != MXI) {
                MV[i] = std::max(MV[i], E[i][j]);
                MV[j] = std::max(MV[j], E[i][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!C[i]) {
            C[i] = i + 1;
            color(i);
        }
    }

    for (int i = 0, j; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (C[i] != C[j]) {
                ans = std::min(ans, std::max(std::max(MC[C[i]], MC[C[j]]), MV[i] + MV[j] + dis(i, j)));
            }
        }
    }

    printf("%.6lf", ans);

    return 0;
}
