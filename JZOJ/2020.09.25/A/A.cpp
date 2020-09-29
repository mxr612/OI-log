/**
 * JZOJ2020.09.25
 * A广告印刷
 * 单调栈, 注意出栈时往哪边合并
*/

#define MXN (400020)

#include <stdio.h>

#include <algorithm>

int n;
long long ans;

struct Block {
    long long l, h;
} stack[MXN];
int top = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("ad2.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0, l, h; i < n; ++i) {
        scanf("%d", &h), l = 1;
        while (top && stack[top].h > h) {
            ans = std::max(ans, stack[top].l * stack[top].h);
            if (stack[top - 1].h < h)
                l += stack[top].l;
            else
                stack[top - 1].l += stack[top].l;
            --top;
        }
        if (!top) l += stack[0].l, stack[0].l = 0;
        stack[++top] = Block{l, h};
    }

    while (top)
        ans = std::max(ans, stack[top].l * stack[top].h),
        stack[top - 1].l += stack[top].l, --top;

    printf("%lld", ans);

    return 0;
}