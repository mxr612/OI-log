/**
 * JZOJ2020.09.19A
 * B patrick
 * 类似差分, 考虑权值树状数组
*/

#define MXN (500012)

#include <stdio.h>
#include <stdlib.h>

int N, M, arr[MXN], rec[MXN] = {};

class TA {
    int arr[MXN + 32] = {};

   public:
    void insert(int x, int w) {
        for (++x; x < MXN; x += -x & x)
            arr[x] += w;
    }
    int query(int x) {
        int res = 0;
        for (++x; x; x -= -x & x)
            res += arr[x];
        return res;
    }
    int operator[](int x) { return query(x) - query(x - 1); }
} ta;

void modify(int x, int y) {
    if (x <= 0 || N < x) return;
    if (arr[x - 1] > arr[x]) ta.insert(arr[x - 1], 1), ta.insert(arr[x], -1);
    if (arr[x] > arr[x + 1]) ta.insert(arr[x], 1), ta.insert(arr[x + 1], -1);
    arr[x] = y;
    if (arr[x - 1] > arr[x]) ta.insert(arr[x - 1], -1), ta.insert(arr[x], 1);
    if (arr[x] > arr[x + 1]) ta.insert(arr[x], -1), ta.insert(arr[x + 1], 1);
}

signed main() {
    freopen("patrick.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("patrick.out", "w", stdout);
#endif

    scanf("%d%d", &N, &M);

    for (int i = 1, x; i <= N; ++i)
        scanf("%d", &x), modify(i, x);

    char c;
    int last = 0, A, B, C;
    while (M--) {
        do
            c = getchar();
        while (c != 'Q' && c != 'C');
        if (c == 'Q')
            scanf("%d", &C),
                printf("%d\n", last = ta.query((C ^ last) - 1));
        else
            scanf("%d%d", &A, &B),
                modify(A ^= last, B ^ last);
    }

    return 0;
}