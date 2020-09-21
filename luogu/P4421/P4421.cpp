/**
 * luogu P4421
*/

#define MXN (20020)

#define MDA (19260817)
#define MDB (998244353)

#include <stdio.h>
#include <stdlib.h>

int n, ans;
char ss[20];

int ma[20], mb[20];

class Hash {
    struct Node {
        bool v[MXN];
        int s;
        long long b;
        Node* next;
    } * arr[MDA];

    Node* find(int a, long long b) {
        a = ((a % MDA) + MDA) % MDA, b = ((b % MDB) + MDB) % MDB;
        for (Node* i = arr[a]; i; i = i->next)
            if (i->b == b) return i;
        return NULL;
    }
    void insert(int a, long long b, int id) {
        a = ((a % MDA) + MDA) % MDA, b = ((b % MDB) + MDB) % MDB;
        Node* x = find(a, b);
        if (!x)
            x = (Node*)calloc(sizeof(Node), 1),
            x->b = b, x->next = arr[a], arr[a] = x;
        if (!x->v[id]) x->v[id] = true, ++x->s;
    }

   public:
    int insert(char* s, int id) {
        int res, l;
        int a[20];
        long long b[20];
        for (l = 1; s[l] != '\0'; ++l)
            a[l] = (a[l - 1] * 30 + s[l] - 'a') % MDA,
            b[l] = (b[l - 1] * 30 + s[l] - 'a') % MDB;
        for (int i = 1, j; s[i] != '\0'; ++i)
            for (j = 0; j < i; ++j)
                insert(a[i] * ma[15 - i] - b[j] * ma[15 - j], b[i] * mb[15 - i] - b[j] * mb[15 - j], id);
        return find(a[l] * ma[15 - l], b[l] * mb[15 - l])->s - 1;
    }
} hash;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P4421.in", "r", stdin);
#endif

    ma[0] = mb[0] = 1;
    for (int i = 1; i < 20; ++i)
        ma[i] = (ma[i - 1] * 30) % MDA,
        mb[i] = (mb[i - 1] * 30) % MDB;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%s", ss), ans += hash.insert(ss, i);

    return 0;
}