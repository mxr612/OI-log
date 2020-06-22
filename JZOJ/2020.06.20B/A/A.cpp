/**
 * JZOJ 2020.06.20B A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

int N, M;

#define MXN (100020)
#define MXM (100020)

#define UP (0)
#define DN (2)
#define LT (1)
#define RT (3)
#define RE(QLCHRMVID) ((QLCHRMVID + 2) % 4)

struct __node {
    int X, Y, x, y;
    __node* next[4];
} * node[MXN] = {NULL}, *apr[MXN] = {NULL}, *pt;
bool _cmpX(__node* a, __node* b) { return a->X < b->X; }
bool _cmpY(__node* a, __node* b) { return a->Y < b->Y; }

char ope[MXM];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("tratincice8.in", "r", stdin);
#else
    freopen("tratincice.in", "r", stdin);
    freopen("tratincice.out", "w", stdout);

#endif

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i)
        node[i] = (__node*)calloc(sizeof(__node), 1), scanf("%d%d", &node[i]->X, &node[i]->Y);
    pt = node[N] = (__node*)calloc(sizeof(__node), 1);

    std::sort(&node[0], &node[N + 1], _cmpX);
    for (int i = 0, p = 0; i <= N; ++i)
        node[i]->x = (i == 0 || node[i]->X == node[i - 1]->X) ? (p) : (++p);
    std::sort(&node[0], &node[N + 1], _cmpY);
    for (int i = 0, p = 0; i <= N; ++i)
        node[i]->y = (i == 0 || node[i]->Y == node[i - 1]->Y) ? (p) : (++p);

    for (int i = 0; i <= N; apr[node[i]->x] = node[i], ++i)
        if ((node[i]->next[DN] = apr[node[i]->x]) != NULL) apr[node[i]->x]->next[UP] = node[i];
    std::sort(&node[0], &node[N + 1], _cmpX), memset(apr, 0, sizeof(apr));
    for (int i = 0; i <= N; apr[node[i]->y] = node[i], ++i)
        if ((node[i]->next[LT] = apr[node[i]->y]) != NULL) apr[node[i]->y]->next[RT] = node[i];

    for (int i = 0; i < 4; ++i) {
        if (pt->next[i] != NULL && pt->next[i]->X == 0 && pt->next[i]->Y == 0) {
            pt->next[i]->next[RE(i)] = pt->next[RE(i)];
            if (pt->next[RE(i)] != NULL)
                pt->next[RE(i)]->next[i] = pt->next[i];
            pt->next[i] = pt->next[i]->next[i];
        }
    }

    // for (int i = 0; i <= N; ++i) {
    //     printf("|%5d %5d_%5d %5d|", node[i]->X, node[i]->Y, node[i]->x, node[i]->y);
    //     for (int j = 0; j < 4; ++j)
    //         if (node[i]->next[j] == NULL)
    //             printf("|74751 74751|");
    //         else
    //             printf("|%5d %5d|", node[i]->next[j]->X, node[i]->next[j]->Y);
    //     printf("\n");
    // }

    scanf("%s", ope);

    for (int i = 0; i < M; ++i) {
        // printf("%d %d\n", pt->X, pt->Y);
        switch (ope[i]) {
            case 'U':
                pt = pt->next[UP];
                break;
            case 'D':
                pt = pt->next[DN];
                break;
            case 'L':
                pt = pt->next[LT];
                break;
            case 'R':
                pt = pt->next[RT];
                break;
            default:;
        }
    }

    printf("%d %d\n", pt->X, pt->Y);

    return 0;
}