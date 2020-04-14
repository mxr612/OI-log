/**
 * luogu_P1801
 * heap
 */

#include <stdio.h>

#define MXN (200020)

int m, n;
int add[MXN], u;

inline void _swap(register int& x, register int& y) {
    x ^= y ^= x ^= y;
}

class __Bheap {
    int arr[MXN], cnt = 0;

    void _down(int x) {
        if (x << 1 >= cnt)
            return;
        if (arr[x] < arr[x << 1])
            _swap(arr[x], arr[x << 1]), _down(x << 1);
        if (arr[x] < arr[(x << 1) + 1])
            _swap(arr[x], arr[(x << 1) + 1]), _down((x << 1) + 1);
    }

   public:
    inline void _push(register int x) {
        arr[++cnt] = x;
        for (register int i = cnt; i > 1 && arr[i >> 1] < arr[i]; i >>= 1)
            _swap(arr[i], arr[i >> 1]), _down(i);
    }
    inline void _pop() { _swap(arr[1], arr[cnt--]), _down(1); }
    inline int _top() { return arr[1]; }
    inline int _size() { return cnt; }
} Bheap;

class __Sheap {
    int arr[MXN], cnt = 0;

    void _down(int x) {
        if (x << 1 >= cnt)
            return;
        if (arr[x] > arr[x << 1])
            _swap(arr[x], arr[x << 1]), _down(x << 1);
        if (arr[x] > arr[(x << 1) + 1])
            _swap(arr[x], arr[(x << 1) + 1]), _down((x << 1) + 1);
    }

   public:
    inline void _push(register int x) {
        arr[++cnt] = x;
        for (register int i = cnt; i > 1 && arr[i >> 1] > arr[i]; i >>= 1)
            _swap(arr[i], arr[i >> 1]), _down(i);
    }
    inline void _pop() { _swap(arr[1], arr[cnt--]), _down(1); }
    inline int _top() { return arr[1]; }
} Sheap;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1801_1.in", "r", stdin);
    // freopen("P1801.out", "w", stdout);
#endif

    scanf("%d%d", &m, &n);

    for (register int i = 1; i <= m; ++i)
        scanf("%d", &add[i]);

    for (register int i = 1, j = 1; i <= n; ++i) {
        scanf("%d", &u);

        while (j <= u) {
            if (!Bheap._size() || add[j] <= Bheap._top()) {
                Bheap._push(add[j++]);
                while (Bheap._size() > i)
                    Sheap._push(Bheap._top()), Bheap._pop();
            } else
                Sheap._push(add[j++]);
        }
        while (Bheap._size() < i)
            Bheap._push(Sheap._top()), Sheap._pop();

        printf("%d\n", Bheap._top());
    }

    return 0;
}