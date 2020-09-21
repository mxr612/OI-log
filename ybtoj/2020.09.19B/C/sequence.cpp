/**
 * ybtoj2020.09.19B
 * C sequence 波动序列
 */

#define MXN (100020)

#include <stdio.h>

#include <map>

int n, t;
int A[MXN], B[MXN], C[MXN];

std::map<int, int> map;
int tot;

class preSZS {
    int arr[MXN * 3];

   public:
    void insert(register int x, register int w) {
        while (x <= tot && arr[x] < w) arr[x] = w, x += -x & x;
    }
    int query(register int x) {
        register int res = 0;
        while (x) res = std::max(res, arr[x]), x -= -x & x;
        return res;
    }
} pab, pc0, pc1;
class sufSZS {
    int arr[MXN * 3];

   public:
    void insert(register int x, register int w) {
        while (x && arr[x] < w) arr[x] = w, x -= -x & x;
    }
    int query(register int x) {
        register int res = 0;
        while (x <= tot) res = std::max(res, arr[x]), x += -x & x;
        return res;
    }
} sab, sc0, sc1;

signed main() {
    freopen("sequence.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("sequence.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]), ++map[A[i]];
    for (int i = 0; i < n; ++i) scanf("%d", &B[i]), ++map[B[i]];
    for (int i = 0; i < n; ++i) scanf("%d", &C[i]), ++map[C[i]];

    for (auto &i : map) i.second = ++tot;
    for (int i = 0; i < n; ++i) A[i] = map[A[i]];
    for (int i = 0; i < n; ++i) B[i] = map[B[i]];
    for (int i = 0; i < n; ++i) C[i] = map[C[i]];

    for (int i = 0, a, b, c0, c1; i < n; ++i) {
        a = std::max(pab.query(A[i]), std::max(pc0.query(A[i]), pc1.query(A[i]))) + 1;
        b = std::max(sab.query(B[i]), std::max(sc0.query(B[i]), sc1.query(B[i]))) + 1;
        c0 = std::max(sab.query(1), pc0.query(C[i])) + 1;
        c1 = std::max(sab.query(1), sc1.query(C[i])) + 1;
        pab.insert(A[i], a), sab.insert(A[i], a);
        pab.insert(B[i], b), sab.insert(B[i], b);
        pc0.insert(C[i], c0), sc0.insert(C[i], c0);
        pc1.insert(C[i], c1), sc1.insert(C[i], c1);
    }

    printf("%d", std::max(sab.query(1), std::max(sc0.query(1), sc1.query(1))));

    return 0;
}
