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