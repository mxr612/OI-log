/**
 * 暴力模拟
 * 子序列自动机&Trie
*/

#define II ("11.in")
#define OO ("11.out")

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>.

std::string a, b;

class SubSeq {
    struct Node {
        Node* next['z' - 'a' + 1];
    } * root;

   public:
    void build(std::string s) {
        Node* p[2] = {};
        for (int i = s.length() - 1, j, x, y; i >= 0; --i) {
            x = i & 1, y = !x, p[x] = (Node*)calloc(sizeof(Node), 1);
            for (j = 0; p[y] && j <= 'z' - 'a'; ++j)
                p[x]->next[j] = p[y]->next[j];
            p[x]->next[s[i + 1] - 'a'] = p[y];
        }
        root = (Node*)calloc(sizeof(Node), 1);
        for (int i = 0; p[0] && i <= 'z' - 'a'; ++i)
            root->next[i] = p[0]->next[i];
        root->next[s[0] - 'a'] = p[0];
    }
    int query(std::string s) {
        Node* p = root;
        int res = 0;
        for (auto i : s)
            if (p = p->next[i - 'a'])
                ++res;
            else
                break;
        return res;
    }
} SS;
class Trie {
    struct Node {
        Node* next['z' - 'a' + 1];
    }* root = (Node*)calloc(sizeof(Node), 1);

   public:
    int insert(std::string s) {
        Node* p = root;
        char c = 0;
        int res = 0;
        for (auto i : s)
            if (i - c)
                p = ((p->next[i - 'a']) ? (p->next[i - 'a']) : (++res, p->next[i - 'a'] = (Node*)calloc(sizeof(Node), 1)));
            else
                break;
        return res;
    }
} T;

long long ans;

int la = 1, lb;

signed main() {
    freopen(II, "r", stdin);
    freopen(OO, "w", stdout);

    std::cin >> a >> b;

    SS.build(a);

    for (int i = 0; i < b.length(); ++i)
        ans += T.insert(b.substr(i, SS.query(b.substr(i, 10))));

    printf("%lld", ans);

    return 0;
}