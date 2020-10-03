/**
 * 暴力模拟
 * 子序列自动机&Trie
*/

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

std::string a, b;

class SubSeq {
    struct Node {
        Node* next['z' - 'a' + 1];
    } * root;

    Node* p;
    char c;
    int res;

   public:
    void build(std::string s) {
        Node* P[2] = {};
        for (int i = s.length() - 1, j, x, y; i >= 0; --i) {
            x = i & 1, y = !x, P[x] = (Node*)calloc(sizeof(Node), 1);
            for (j = 0; P[y] && j <= 'z' - 'a'; ++j)
                P[x]->next[j] = P[y]->next[j];
            P[x]->next[s[i + 1] - 'a'] = P[y];
        }
        root = (Node*)calloc(sizeof(Node), 1);
        for (int i = 0; P[0] && i <= 'z' - 'a'; ++i)
            root->next[i] = P[0]->next[i];
        root->next[s[0] - 'a'] = P[0];
    }

    int query(std::string s) {
        p = root, c = 0, res = 0;
        for (auto i : s)
            if ((c - i) && (p = p->next[i - 'a']))
                ++res, c = i;
            else
                break;
        return res;
    }
} SS;

class Trie {
    struct Node {
        Node* next['z' - 'a' + 1];
    }* root = (Node*)calloc(sizeof(Node), 1);

    Node* p;
    char c;
    int res;

   public:
    int insert(std::string s) {
        p = root, c = 0, res = 0;
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
        std::cin >> a >> b;

    SS.build(a);

    for (int i = 0; i < b.length(); ++i)
        ans += T.insert(b.substr(i, SS.query(b.substr(i, 10))));

    printf("%lld", ans);

    return 0;
}