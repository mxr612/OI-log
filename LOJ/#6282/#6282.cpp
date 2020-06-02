/**
 * LOJ #6282
 * 分块6
 * 链表维护块
 * 块分裂
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MXN (200000)
#define MXS (1000)

struct __block {
    int siz;
    struct __node {
        int v;
        __node* next;
    } * node;
    __block* next;
}* head = NULL;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6282.in", "r", stdin);
#endif

    int n, min_siz, max_siz, opt, l, r, c;

    scanf("%d", &n), min_siz = sqrt(n), max_siz = min_siz << 1;

    __block **pp = &head, *p, *cmp;
    __block::__node **qq, *q, *cmq;

    for (int i = 1; i <= n; pp = &(p->next)) {
        p = *pp = (__block*)calloc(sizeof(__block), 1);
        qq = &(p->node);
        for (; i <= n && p->siz < min_siz; ++i, qq = &((*qq)->next)) {
            *qq = (__block::__node*)calloc(sizeof(__block::__node), 1);
            scanf("%d", &((*qq)->v)), ++p->siz;
        }
    }

    for (int i = 0, j, cnt; i < n; ++i) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if (opt) {
            for (cnt = 0, p = head; cnt + p->siz < r; p = p->next)
                cnt += p->siz;
            for (q = p->node; ++cnt < r; q = q->next)
                ;
            printf("%d\n", q->v);
        } else {
            for (cnt = 0, p = head; cnt + p->siz < l; p = p->next)
                cnt += p->siz;
            for (qq = &(p->node); ++cnt < l; qq = &((*qq)->next))
                ;
            cmq = (__block::__node*)calloc(sizeof(__block::__node), 1);
            cmq->v = r, cmq->next = *qq, *qq = cmq;
            if (++p->siz == max_siz) {
                cmp = (__block*)calloc(sizeof(__block), 1);
                cmp->next = p->next, p->next = cmp;
                cmp->siz = p->siz = min_siz;
                for (j = 1, qq = &(p->node); j <= min_siz; ++j)
                    qq = &((*qq)->next);
                cmp->node = *qq, *qq = NULL;
            }
        }
    }

    return 0;
}