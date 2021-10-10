// P1522

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const double INF = 1e9;

int N;
int X[200], Y[200];
double G[200][200];

char s[300];
bool C[200][200];
double E[200][200];

double M[200] = {0};
double minn;

int main() {
    freopen("P1522.in", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 1; i <= N; i++) {
        scanf("%s", s);
        for (int j = 1; j <= N; j++)
            C[i][j] = s[j - 1] - '0';
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            G[i][j] = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (C[i][j] || i == j)
                E[i][j] = G[i][j];
            else
                E[i][j] = INF;
    minn = INF;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                E[i][j] = min(E[i][j], E[i][k] + E[k][j]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (E[i][j] < INF)
                M[i] = max(M[i], E[i][j]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (E[i][j] == INF)
                minn = min(minn, M[i] + M[j] + G[i][j]);
    for (int i = 1; i <= N; i++)
        minn = max(minn, M[i]);

    printf("%.6lf", minn);

    return 0;
}