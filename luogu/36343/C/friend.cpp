/**
 * luogu36343
 * 校测 51Nod
 * Cfriend友谊序列
 * 给两个数集$A$,$B$, 问有多少对$a_i\ xor\ b_i \in A\cupB$
 * 设$b,c\inB$有$a\ xor\ b = c$, 有$a\ xor\ c = b$
 * 而处于同一个集合的不会被计算
 * 所以答案一定是偶数
*/

#include <stdio.h>

signed main() {
    int T;

    scanf("%d", &T);

    while (T--)
        printf("0!\n");

    return 0;
}