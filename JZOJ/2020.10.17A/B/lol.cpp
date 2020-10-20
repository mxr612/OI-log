/**
 * JZOJ2020.10.17A
 * JZOJ3236
 * JZOJ6824
 * 期望題
 * 給出初始暴擊率x，若暴擊成功下一次暴擊率恢復初始值x，若暴擊失敗下一次暴擊率增加x
 * 求每一刀平均爆率
 * 實際上就是求期望多少刀能暴擊一次
 * 考慮i刀不暴擊的概率，然後相加就是期望多少刀爆一次
*/

#include <math.h>
#include <stdio.h>

signed main() {
    freopen("lol.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("lol.out", "w", stdout);
#endif

    double x, ans = 1, m = 1;

    scanf("%lf", &x);

    for (int i = 1; i < ceil(100.0 / x); ++i)
        ans += m *= (100 - i * x) / 100;

    printf("%.10lf", 1 / ans);

    return 0;
}