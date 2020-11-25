/**
 * JZOJ 20201114 B
 * transform
 * 坐标旋转 矩阵快速幂
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

const int MXN = 100;
const double PI = acos(-1);

class matrix {
    double a[3][3];

   public:
    matrix() {
        for (int i = 0, j; i < 3; ++i)
            for (j = 0; j < 3; ++j)
                a[i][j] = (i == j);
    }
    double* operator[](int x) { return a[x]; }
    matrix operator+(matrix m) {
        matrix res;
        for (int i = 0, j; i < 3; ++i)
            for (j = 0; j < 3; ++j)
                res[i][j] = a[i][j] + m[i][j];
        return res;
    }
    matrix& operator+=(matrix m) { return (*this) = (*this) + m; }
    matrix operator*(matrix m) {
        matrix res;
        for (int i = 0, j, k; i < 3; ++i)
            for (j = 0; j < 3; ++j)
                for (k = 0; k < 3; ++k)
                    m[i][j] += a[i][k] * m[k][j];
        return res;
    }
    matrix& operator*=(matrix m) { return (*this) = (*this) * m; }
};

class fun {
    matrix k, b;

   public:
    fun() {}
    fun operator+(matrix m) {
        fun res = *this;
        res.b += m;
        return res;
    }
    fun& operator+=(matrix m) { return (*this) = (*this) + m; }
    fun operator*(matrix m) {
        fun res = *this;
        res.k *= m, res.b *= m;
        return res;
    }
    fun& operator*=(matrix m) { return (*this) = (*this) * m; }
    fun operator+(fun f) {
        fun res;
        res.k = this->k + f.k, res.b = this->b + f.b;
        return res;
    }
    fun& operator+=(fun f) { return (*this) = (*this) + f; }
    fun operator*(fun f) {
        fun res;
        res.k = this->k * f.k;
        res.b = this->b * f.k + f.b;
        return res;
    }
    fun& operator*=(fun f) { return (*this) = (*this) * f; }
    matrix operator()(matrix m) { return m * k + b; }
};

matrix node[MXN];

char opt[300];

int typ() {
    int tot = -1;
    do
        opt[++tot] = getchar();
    while (opt[tot] != EOF && opt[tot] != 'E' && opt[tot] != '(');
    for (int i = 0; i <= tot; ++i) {
        if (opt[i] == 'T') return 1;
        if (opt[i] == 'S') return 2;
        if (opt[i] == 'R') return 3;
        if (opt[i] == 'L') return 4;
        if (opt[i] == 'E') return 5;
    }
    return 0;
}

matrix Trans(double a, double b) {
    fun res;
}
matrix Scale(double a, double b);
matrix Rotate(double t, double a, double b);

signed main() {
#ifndef ONLNE_JUDGE
    freopen("transform.in", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &node[i].x, &node[i].y);

    int t;
    double p, x, y;
    while (t = typ()) {
        switch (t) {
            case 1:  //T
                scanf("%lf,%lf", &x, &y);
                break;
            case 2:  //S
                scanf("%lf,%lf", &x, &y);
                break;
            case 3:  //R
                scanf("%lf,%lf,%lf", &p, &x, &y);
                break;
            case 4:  //L
                scanf("%lf", &p);
                break;
            case 5:  //E
                break;
            default:;
        }
    }

    return 0;
}