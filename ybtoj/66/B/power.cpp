/**
 * power
*/

#include <stdio.h>
#include <string.h>

const long long MD = 1000000007,
                H = 570000004;

long long N, B, A, L, x, y;

struct Matrix {
    long long arr[60][60];
    Matrix() { memset(arr, 0, sizeof(arr)); }
    long long* operator[](int x) { return arr[x]; }
    Matrix operator*(Matrix brr) const {
        Matrix res;
        for (int i = 0, j, k; i < 55; ++i)
            for (j = 0; j < 55; ++j)
                for (k = 0; k < 55; ++k)
                    res[i][j] = (res[i][j] + arr[i][k] * brr[k][j]) % MD;
        return res;
    }
    Matrix& operator*=(Matrix brr) { return (*this) = (*this) * brr; }
} m, a;
Matrix ksm(Matrix x, long long y) {
    Matrix res;
    for (int i = 0; i < 55; ++i)
        res[i][i] = 1;
    for (; y; x *= x, y >>= 1)
        if (y & 1)
            res *= x;
    return res;
}

signed main() {
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);

    scanf("%lld%lld%lld%lld%lld%lld", &N, &A, &B, &L, &x, &y);

    a[0][1] = x * H % MD, a[0][0] = (100 - x) * H % MD;
    a[L][L - 1] = y * H % MD, a[L][L] = (100 - y) * H % MD;
    for (int i = 1; i < L; ++i)
        a[i][i + 1] = x * H % MD, a[i][i - 1] = y * H % MD, a[i][i] = (100 - x - y) * H % MD;
    for (int i = 0; i <= L; ++i)
        a[i][51] = i;
    a[51][51] = 1;

    m[0][0] = 1, m *= ksm(a, N + 1);

    printf("%lld", (A * m[0][51] % MD + N % MD * B) % MD);

    return 0;
}