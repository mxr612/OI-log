
short s = 2;
long long MXN = 1000000000000000020;

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int m;

class XDS {
    struct Node {
        short s;
        long long p[2];
        Node *ls, *rs;
    } * root;

    void ope(Node*& x, long long& T, long long& L, long long& R, short& s, long long l, long long r) {
        if (r < l || r < L || R < l) return;
        if (!x) x = (Node*)calloc(sizeof(Node), 1), x->p[1] = MXN;
        if (s < 2) x->s = s, x->p[s] = l, x->p[!s] = MXN;
        if (L <= l && r <= R) {
            switch (T) {
                case 0:
                    x->s = 0, x->p[0] = l, x->p[1] = MXN;
                    break;
                case 1:
                    x->s = 1, x->p[0] = MXN;
                    x->p[1] = l;
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
            if (x->ls && x->rs) {
                x->p[0] = std::min(x->ls->p[0], x->rs->p[0]);
                x->p[1] = std::min(x->ls->p[1], x->rs->p[1]);
            } else if (x->ls) {
                x->p[0] = std::min(x->ls->p[0], (l + r) / 2 + 1);
                x->p[1] = x->ls->p[1];
            } else if (x->rs) {
                x->p[0] = std::min(l, x->rs->p[0]);
                x->p[1] = x->rs->p[1];
            }
        }
    }

   public:
    long long ope(long long o, long long l, long long r) {
        ope(root, o, l, r, s = 2, 1ll, MXN);
        return root->p[0];
    }

} xds;

signed main() {
    freopen("A.in", "r", stdin);

    scanf("%d\n", &m);

    for (long long i = 0, o, l, r; i < m; ++i) {
        scanf("%lld%lld%lld", &o, &l, &r);
        switch (o) {
            case 1ll:
                printf("%lld\n", xds.ope(1, l, r));
                break;
            case 2ll:
                printf("%lld\n", xds.ope(0, l, r));
                break;
            case 3ll:
                printf("%lld\n", xds.ope(2, l, r));
            default:;
        }
    }

    return 0;
}
