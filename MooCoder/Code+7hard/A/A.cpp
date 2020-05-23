/**
 * A
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#define MXN (1000000)

long long k;

class __stack {
    struct __node {
        int v;
        __node *ls, *rs;
    }* root = NULL;

    __node* _merge(__node* x, __node* y) {
        if (x == NULL)
            return y;
        if (y == NULL)
            return x;
        if (x->v > y->v)
            std::swap(x, y);
        if (rand() & 1)
            x->ls = _merge(x->ls, y);
        else
            x->rs = _merge(x->rs, y);
        return x;
    }

   public:
    void _push(int v) {
        __node* p = (__node*)calloc(sizeof(__node), 1);
        p->v = v;
        root = _merge(root, p);
    }
    int cnt = 0;
    int _top() {
        if (root == NULL)
            _push(++cnt);
        return root->v;
    }
    void _pop() {
        if (root != NULL)
            root = _merge(root->ls, root->rs);
    }
} pq;

int arr[MXN] = {0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
#endif

    srand(114514);

    scanf("%lld", &k);

    for (int i = 1, j, t; true; ++i) {
        for (t = pq._top(), pq._pop(), arr[t] = t, j = 1; j < t; ++j)
            if (--arr[j] == 0)
                pq._push(j);
        if (i - pq.cnt == k)
            break;
    }

    printf("%d\n",pq.cnt);
    for (int i = 1; i <= pq.cnt; ++i)
        printf("%d ", arr[i]);

    return 0;
}