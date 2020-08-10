/**
 * 2020.8.10B
 * B
*/
#define MXN (50020)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

long long K;
int P, n, m;
int s[MXN];

struct Mod {
    long long x, w;
    bool operator<(Mod m) { return x < m.x; }
} mod[MXN];

void* cp = calloc(sizeof(long long), 20);
struct Matrix {
    long long a[2][2];
    long long* operator[](int i) { return a[i]; }
    Matrix operator*(Matrix M) {
        Matrix* x = (Matrix*)cp;
        (*x)[0][0] = (a[0][0] * M[0][0] + a[0][1] * M[1][0]) % P;
        (*x)[0][1] = (a[0][0] * M[0][1] + a[0][1] * M[1][1]) % P;
        (*x)[1][0] = (a[1][0] * M[0][0] + a[1][1] * M[1][0]) % P;
        (*x)[1][1] = (a[1][0] * M[0][1] + a[1][1] * M[1][1]) % P;
        return *x;
    }

    Matrix& operator*=(Matrix M) { return *this = (*this) * M; }
} cmp, sm, ss[MXN], as, bz[MXN][30];
Matrix dy() {
    Matrix* x = (Matrix*)cp;
    (*x)[0][0] = 1, (*x)[0][1] = 0, (*x)[1][0] = 0, (*x)[1][1] = 1;
    return *x;
}
Matrix make(long long a, long long b) {
    Matrix* x = (Matrix*)cp;
    (*x)[0][0] = 0, (*x)[0][1] = a, (*x)[1][0] = 1, (*x)[1][1] = b;
    return *x;
}

struct Ned {
    int d;
    long long x;
    Matrix m;
} ned[MXN];
bool cmp1(Ned x, Ned y) { return x.x < y.x; }
bool cmp2(Ned x, Ned y) { return x.d < y.d; }

Matrix ksm(long long x) {
    Matrix res = dy(), cmp = sm;
    while (x) {
        if (x & 1) res = res * sm;
        cmp = cmp * cmp;
        x >>= 1;
    }
    return res;
}

Matrix qy(int l, int r) {
    ++l;
    Matrix res = dy();
    for (int i = 20, j = 1 << 20; l < r; --i, j >>= 1)
        if (l + j <= r)
            res = res * bz[l][i], l += j;
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%lld%d%d", &K, &P, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%lld%lld", &mod[i].x, &mod[i].w);
    std::sort(mod, mod + m);

    sm = dy();
    for (int i = 1; i < n; ++i)
        sm = sm * (ss[i] = make(s[i - 1], s[i]));
    sm = sm * (ss[0] = make(s[0], s[n - 1]));

    mod[m].x = K;
    mod[m].w = s[K % n];
    ned[0].x = mod[0].x / n;
    for (int i = 1; i <= m; ++i) {
        ned[i].d = i, ned[i].x = floor(1.0 * mod[i].x / n) - ceil(1.0 * mod[i - 1].x / n);
        if (ned[i].x < 0) ned[i].x = 0;
    }
    std::sort(ned, ned + m + 1, cmp1);
    ned[0].m = ksm(ned[0].x);
    for (int i = 1; i <= m; ++i)
        ned[i].m = ned[i - 1].m * ksm(ned[i].x - ned[i - 1].x);
    std::sort(ned, ned + m + 1, cmp2);

    for (int i = n - 1, j; i >= 0; --i) {
        bz[i][0] = ss[i];
        for (j = 1; i + (1 << j) <= n; ++j)
            bz[i][j] = bz[i][j - 1] * bz[i + (1 << j)][j - 1];
    }

    as[0][1] = 1;
    as = as * ned[0].m;
    as = as * qy(0, mod[0].x % n);
    as = as * make(s[(mod[0].x - 1) % n], mod[0].w);
    for (int i = 1; i <= m; ++i) {
        if (mod[i].x - mod[i - 1].x == 1)
            as = as * make(mod[i - 1].w, mod[i].w);
        else if (mod[i].x / n == mod[i - 1].x / n) {
            as = as * qy(mod[i - 1].x % n, mod[i].x % n);
        } else {
            as = as * qy(mod[i - 1].x % n, n);
            as = as * ned[i].m;
            as = as * qy(0, mod[i].x % n);
            as = as * make(s[(mod[i].x - 1) % n], mod[i].w);
        }
    }

    printf("%lld", as[0][0]);

    return 0;
}
