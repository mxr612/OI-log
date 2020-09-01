/**
 * C 
 * T145308 【2020.8.24NOIP模拟赛】捡金子
*/

#define MXM (50020)
#define MXK (26)
#define MXL (100)
#define MXN (12)

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int M, K, L, N;
char s[MXL];

class Trie {
    struct Node {
        int w, f[MXN];
        Node* ne[MXK];
    }* root = (Node*)calloc(sizeof(Node), 1);

    void ans(Node* p) {
        for (int i = 0, j, k; i < MXK; ++i)
            if (p->ne[i])
                for (ans(p->ne[i]), j = MXN - 1; j > 0; j--)
                    for (k = j; k >= 0; --k)
                        p->f[j] = std::max(p->f[j], p->f[j - k] + p->ne[i]->f[k]);
        for (int i = 1; i < MXN; ++i) p->f[i] += p->w;
    }

   public:
    void insert(char* s) {
        Node* p = root;
        for (int i = 0; s[i]; ++i)
            if (p->ne[s[i] - 'A'] == NULL)
                p = p->ne[s[i] - 'A'] = (Node*)calloc(sizeof(Node), 1);
            else
                p = p->ne[s[i] - 'A'];
        ++p->w;
    }
    int ans(int x) {
        ans(root);
        return root->f[x];
    }

} trie;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d%d%d%d", &M, &K, &L, &N);

    for (int i = 0; i < M; ++i)
        scanf("%s", s), trie.insert(s);

    printf("%d", trie.ans(N));

    return 0;
}