/**
 * https://www.luogu.com.cn/problem/P1981
 * luogu P1981
 * 表达式求值
*/

#define MXN (100000)
#define XJQ (10000)

#include <stdio.h>

long long x;
char c;

class Calc {
    long long arr[MXN];
    int top = 0;

   public:
    void push(long long x) { arr[++top] = x % XJQ; }
    void push(char c, long long x) {
        if (c == '+')
            arr[++top] = x % XJQ;
        else if (c == '*')
            arr[top] = (arr[top] * x) % XJQ;
    }
    long long ans() {
        long long res = 0;
        for (int i = 1; i <= top; ++i) res = (res + arr[i]) % XJQ;
        return res;
    }
} calc;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1981_1.in", "r", stdin);
#endif

    scanf("%lld", &x), calc.push(x);
    while (scanf("%c%d", &c, &x) != EOF) calc.push(c, x);

    printf("%lld", calc.ans());

    return 0;
}