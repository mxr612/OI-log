
#define MXM (100020)

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int m;

int o[MXM];
long long l[MXM], r[MXM], MXN;

class XDS {
    struct Node {
        short s;
        long long p[2];
        Node *ls, *rs;
    } * root;

    short s = 2;

    void ope(Node*& x, long long& T, long long& L, long long& R, short& s, long long l, long long r) {
        if (r < l) return;
        if (!x) x = (Node*)calloc(sizeof(Node), 1), x->p[0] = l, x->p[1] = MXN;
        if (s < 2) x->s = s, x->p[s] = l, x->p[!s] = MXN;
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            switch (T) {
                case 0:
                    x->s = 0, x->p[0] = l, x->p[1] = MXN;
                    break;
                case 1:
                    x->s = 1, x->p[0] = MXN, x->p[1] = l;
                    break;
                case 2:
                    if (x->s < 2)
                        x->s ^= 1;
                    else
                        ope(x->ls, T, L, R, x->s, l, (l + r) / 2), ope(x->rs, T, L, R, x->s, (l + r) / 2 + 1, r);
                    x->p[0] ^= x->p[1] ^= x->p[0] ^= x->p[1];
                default:;
            }
        } else {
            ope(x->ls, T, L, R, x->s, l, (l + r) / 2), ope(x->rs, T, L, R, x->s, (l + r) / 2 + 1, r);
            x->s = 2;
            x->p[0] = std::min(x->ls->p[0], x->rs->p[0]);
            x->p[1] = std::min(x->ls->p[1], x->rs->p[1]);
        }
    }

   public:
    long long ope(long long o, long long l, long long r) {
        ope(root, o, l, r, s, 1ll, MXN);
        return root->p[0];
    }

} xds;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A5.in", "r", stdin);
#endif

    scanf("%d\n", &m);

    for (int i = 0; i < m; ++i)
        scanf("%d%lld%lld", &o[i], &l[i], &r[i]), MXN = std::max(MXN, r[i]);
    ++MXN;
    for (int i = 0; i < m; ++i) {
        switch (o[i]) {
            case 1:
                printf("%lld\n", xds.ope(1, l[i], r[i]));
                break;
            case 2:
                printf("%lld\n", xds.ope(0, l[i], r[i]));
                break;
            case 3:
                printf("%lld\n", xds.ope(2, l[i], r[i]));
            default:;
        }
    }

    return 0;
}
