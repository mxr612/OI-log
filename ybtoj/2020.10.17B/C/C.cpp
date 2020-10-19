/**
 * ybtoj2020.10.17B
 * C多边形
 * SubI
*/

#include <math.h>
#include <stdio.h>

signed main() {
    freopen("polygons.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("polygons.out", "w", stdout);
#endif

    int N;

    scanf("%d", &N);

    if (N < 3) {
        printf("0");
    } else if (N == 3) {
        double x[3], y[3], p[3], a, b, c, s;
        for (int i = 0; i < 3; ++i) scanf("%lf%lf%lf", x + i, y + i, p + i);
        a = sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
        b = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]));
        c = sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]));
        s = (a + b + c) / 2;
        printf("%lf", sqrt(s * (s - a) * (s - b) * (s - c)) * p[0] * p[1] * p[2]);
    } else {
    }

    return 0;
}