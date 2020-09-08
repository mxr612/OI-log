/**
 * 001make
*/

#define MXN (1000020)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <algorithm>

char s[10] = "00.in", b[10] = "00.out";

int n, m;

int pos[MXN], arr[MXN];

class XDS {
    struct Node {
        int w, s;
        Node *ls, *rs;
    } * root;

   public:
    void clear() { root = NULL; }
} xds;

void in(int t) {
    freopen(s, "w", stdout);
    srand(time(NULL));
    int ln, lm, tp = 0;
    if (0 <= t <= 5)
        ln = 1001, lm = 1001;
    else {
        ln = lm = 1000001;
        if (6 <= t <= 8)
            tp = 1;
        if (9 <= t <= 11)
            tp = 2;
    }
    n = rand() % ln, m = rand() % lm;

    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf("%d ", rand());
    putchar('\n');
    for (int i = 0; i < n; ++i)
        printf("%d ", rand());
    putchar('\n');
    for (int i = 0, l, r; i < m; ++i) {
        l = rand() % ln, r = rand() % ln;
        if (r < l) l ^= r ^= l ^= r;
        if (tp == 1)
            printf("0 %d %d %d\n", l, r, rand());
        else if (tp == 2)
            printf("1 %d %d %d\n", l, r, rand());
        else if (rand() & 1) {
            printf("%d %d %d %d\n", rand() & 1, l, r, rand());
        } else {
        }
    }
}

int arr[MXN];

void out() {
    freopen(b, "w", stdout);
}

signed main() {
    for (int i = 0; i < 20; ++i) {
        s[0] = b[0] = '0' + (i / 10), s[1] = b[1] = '0' + (i % 10);
        in(i);
    }

    return 0;
}