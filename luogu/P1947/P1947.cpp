/**
 * luogu P1947
 * 猜数
 * 交互题
 */

extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int c) {
    int l = 1, r = n, m, k;
    while (l < r) {
        k = Seniorious(m = (l + r) / 2);
        switch (k) {
            case -1:
                l = m + 1;
                break;
            case 0:
                return m;
                break;
            case 1:
                r = m - 1;
                break;
            default:;
        }
    }
}

#include <cstdio>
#include <iostream>

int k, cnt;

extern "C" {
extern int Chtholly(int n, int c);

extern int Seniorious(int x) {
    const int lim = 3000000;
    if (++cnt > lim)
        cnt = lim;
    return (k < x) ? 1 : ((k == x) ? 0 : -1);
}
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P1947.in", "r", stdin);
#endif
    int n, c;
    std::cin >> n >> c >> k;
    int OvO = Chtholly(n, c);
    std::cout << OvO << ' ' << cnt << std::endl;
    return 0;
}