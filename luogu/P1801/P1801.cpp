/**
 * luogu_P1801
 * heap
 * 手写堆优化
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

    inline void _down(register int x) {
        register int l = x, r;
        while (x << 1 < cnt && x >= l)
            if (arr[l = x << 1] < arr[r = (x << 1) + 1]) {
                if (arr[x] < arr[r])
                    _swap(arr[x], arr[r]), x = r;
            } else if (arr[x] < arr[l])
                _swap(arr[x], arr[l]), x = l;
        if (x << 1 == cnt && arr[x] < arr[cnt])
            _swap(arr[x], arr[cnt]);
    }

    inline void _up(register int x) {
        while (x > 1 && arr[x] > arr[x >> 1])
            _swap(arr[x], arr[x >> 1]), _down(x), x >>= 1;
    }

   public:
    inline void _push(register int x) { arr[++cnt] = x, _up(cnt); }
    inline void _pop() { _swap(arr[1], arr[cnt--]), _down(1); }
    inline int _top() { return arr[1]; }
} Bheap;

class __Sheap {
    int arr[MXN], cnt = 0;

    inline void _down(register int x) {
        register int l = x, r;
        while (x << 1 < cnt && x >= l)
            if (arr[l = x << 1] > arr[r = (x << 1) + 1]) {
                if (arr[x] > arr[r])
                    _swap(arr[x], arr[r]), x = r;
            } else if (arr[x] > arr[l])
                _swap(arr[x], arr[l]), x = l;
        if (x << 1 == cnt && arr[x] > arr[cnt])
            _swap(arr[x], arr[cnt]);
    }

    inline void _up(register int x) {
        while (x > 1 && arr[x] < arr[x >> 1])
            _swap(arr[x], arr[x >> 1]), _down(x), x >>= 1;
    }

   public:
    inline void _push(register int x) { arr[++cnt] = x, _up(cnt); }
    inline void _pop() { _swap(arr[1], arr[cnt--]), _down(1); }
    inline int _top() { return arr[1]; }
} Sheap;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1801_11.in", "r", stdin);
    // freopen("P1801.out", "w", stdout);
#endif

    scanf("%d%d", &m, &n);

    for (register int i = 1; i <= m; ++i)
        scanf("%d", &add[i]);

    for (register int i = 1, j = 1; i <= n; ++i) {
        scanf("%d", &u);
        while (j <= u)
            Bheap._push(add[j++]), Sheap._push(Bheap._top()), Bheap._pop();
        printf("%d\n", Sheap._top());
        Bheap._push(Sheap._top()), Sheap._pop();
    }

    return 0;
}