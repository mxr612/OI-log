/**
 * 枚举子序列建AC自动机
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#define CH ('z' - 'a' + 1)

std::string a, b, s;

bool cheak(std::string s) {
    if (s.length() > 10) return false;
    for (int i = 0; i < s.length() - 1; ++i)
        if (s[i] == s[i + 1])
            return false;
    return true;
}

class ACA {
    struct Node {
        int cnt;
        Node *fail, *next[CH];
    }* root = (Node*)calloc(sizeof(Node), 1);

    std::vector<Node*> que;

   public:
    void insert(std::string s) {
        Node* p = root;
        for (auto i : s)
            p = (p->next[i - 'a']) ? (p->next[i - 'a']) : (p->next[i - 'a'] = (Node*)calloc(sizeof(Node), 1));
    }
    void build() {
        for (int i = 0; i < CH; ++i)
            if (root->next[i])
                root->next[i]->fail = root, que.push_back(root->next[i]);
            else
                root->next[i] = root;
        for (int i = 0, j; i < que.size(); ++i)
            for (j = 0; j < CH; ++j)
                if (que[i]->next[j])
                    que[i]->next[j]->fail = que[i]->fail->next[j], que.push_back(que[i]->next[j]);
                else
                    que[i]->next[j] = que[i]->fail->next[j];
    }
    long long query(std::string s) {
        long long res = 0;
        Node* x = root;
        for (int i = que.size() - 1; i >= 0; --i)
            que[i]->cnt = 0;
        for (auto i : s)
            x = x->next[i - 'a'], ++x->cnt;
        for (int i = que.size() - 1; i >= 0; --i)
            res += que[i]->cnt > 0, que[i]->fail->cnt += que[i]->cnt;
        return res;
    }
} aca;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("yl1.in", "r", stdin);
#endif

    std::cin >> a >> b;

    for (int i = 1, j; i < (1 << a.length()); ++i) {
        for (s.clear(), j = 0; j < a.length(); ++j)
            if (i & (1 << j))
                s += a[j];
        if (cheak(s))
            aca.insert(s);
    }
    aca.build();

    printf("%lld", aca.query(b));

    return 0;
}