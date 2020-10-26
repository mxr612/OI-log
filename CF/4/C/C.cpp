/**
 * CF4C Registration system
 * hash
*/

#include <stdio.h>
#include <stdlib.h>

class Hash {
    const int HI = 19260817,
              HII = 998244353,
              ELP = 74751;

    struct Node {
        int w, h;
    } * *arr;

    int hashI(char *s) {
        long long res = 0;
        for (int i = 0; s[i]; ++i)
            res = (res + (s[i]) * ELP) % HI;
        return res;
    }
    int hashII(char *s) {
        long long res = 0;
        for (int i = 0; s[i]; ++i)
            res = (res + s[i] * ELP) % HII;
        return res;
    }

   public:
    Hash() {
        arr = (Node **)calloc(sizeof(Node *), HI + 32);
    }
    int insert(char *s) {
        int h = hashII(s);
        Node **p = &arr[hashI(s)];
        while (*p)
            if ((*p)->h == h)
                return ++(*p)->w;
        *p = (Node *)calloc(sizeof(Node), 1);
        return 0;
    }
};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int n, a;
    char *s = (char *)calloc(sizeof(char), 128);
    Hash map;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        a = map.insert(s);
        if (a)
            printf("%s%d\n", s, a);
        else
            printf("OK\n");
    }

    return 0;
}