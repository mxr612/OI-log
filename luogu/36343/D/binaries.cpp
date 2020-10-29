/**
 * luogu36343
 * 校测 51Nod
 * D binaries 二进制
 * 线段树裸题, 节点维护染色标记和区间答案
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const long long MD = 1000000007;

class XDS {
    int L, R;
    long long *mi;
    struct Node {
        short b;
        int c, l, r, m;
        long long s;
        Node *ls, *rs;
    } * root;

    void paint(Node *x, const short C) {
        if (x) x->b = C, x->c = x->m * C, x->s = C * (mi[x->m] + MD - 1) % MD;
    }

    void push_down(Node *x) {
        if (x && x->ls && x->b >= 0) paint(x->ls, x->b), paint(x->rs, x->b), x->b = -1;
    }
    void merge_up(Node *x) {
        if (x && x->ls) x->c = x->ls->c + x->rs->c, x->s = (x->ls->s * mi[x->r - (x->l + x->r) / 2] % MD + x->rs->s) % MD;
    }

    void build(Node *&x, char *s, int l, int r) {
        if (r < l) return;
        while (!x) x = (Node *)calloc(sizeof(Node), 1);
        x->l = l, x->r = r;
        x->m = r - l + 1;
        if (l == r)
            paint(x, s[l] - '0');
        else
            build(x->ls, s, l, (l + r) / 2), build(x->rs, s, (l + r) / 2 + 1, r),
                x->b = -1, merge_up(x);
    }

    int cnt(Node *x, int l, int r, const int L, const int R) {
        if (!x || r < l || r < L || R < l) return 0;
        return (L <= l && r <= R) ? (x->c) : (push_down(x), cnt(x->ls, l, (l + r) / 2, L, R) + cnt(x->rs, (l + r) / 2 + 1, r, L, R));
    }

    int query(Node *x, int l, int r, const int L, const int R) {
        if (!x || r < l || r < L || R < l) return 0;
        if (L <= l && r <= R)
            return x->s * mi[R - r] % MD;
        else
            return push_down(x),
                   (query(x->ls, l, (l + r) / 2, L, R) + query(x->rs, (l + r) / 2 + 1, r, L, R)) % MD;
    }

    void cover(Node *x, int l, int r, const int L, const int R, const short C) {
        if (!x || r < l || r < L || R < l) return;
        if (L <= l && r <= R)
            paint(x, C);
        else
            push_down(x),
                cover(x->ls, l, (l + r) / 2, L, R, C), cover(x->rs, (l + r) / 2 + 1, r, L, R, C),
                merge_up(x);
    }

    void destruct(Node *x) {
        if (x)
            destruct(x->ls), destruct(x->rs),
                free(x);
    }

   public:
    XDS(char *s) {
        L = 0, R = strlen(s) - 1;
        mi = (long long *)calloc(sizeof(long long), R + 32);
        mi[0] = 1;
        for (int i = 1; i < R + 8; ++i)
            mi[i] = (mi[i - 1] << 1) % MD;
        build(root = NULL, s, L, R);
    }
    int cnt(int l, int r) { return cnt(root, L, R, l - 1, r - 1); }
    void cover(int l, int r, short c) { cover(root, L, R, l - 1, r - 1, c); }
    int query(int l, int r) { return query(root, L, R, l - 1, r - 1); }
    ~XDS() { destruct(root); }
};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("binaries.in", "r", stdin);
#endif

    char *s = (char *)calloc(sizeof(char), 200056);
    int N, o, l, r, c;
    scanf("%s", s);

    XDS xds(s);

    scanf("%d", &N);

    while (N--) {
        scanf("%d%d%d", &o, &l, &r);
        switch (o) {
            case 1:
                c = xds.cnt(l, r);
                xds.cover(l, l + c - 1, 1);
                xds.cover(l + c, r, 0);
                break;
            case 2:
                c = xds.cnt(l, r);
                xds.cover(r - c + 1, r, 1);
                xds.cover(l, r - c, 0);
                break;
            case 3:
                printf("%d\n", xds.query(l, r));
                break;
            default:;
        }
    }

    return 0;
}

/*
最近在焦虑着正在失去的青春，想着如何不平凡地过完这一生。  
大概这也是已经失去青春的平凡人会想的事情吧？一直在后悔，好像如果现在的我回到过去就能改变什么一样。
你告诉我要做自己，可是我究竟是谁？我身后的是什么？
好像那三个问题，我是谁，我从哪里来，我到哪里去。
什么是我，我属于哪里为何而战，我想成为什么做出什么？
再这样下去大概不会有自我了吧，或者是从来就没有过自我。我甚至找不到什么属于自己的东西。
*/
