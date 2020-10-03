/**
 * 
*/

#define II ("11.in")

#define LOW (15)
#define TOP (1000000)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, m;

signed main() {
    freopen(II, "w", stdout);

    srand(time(NULL));

    n = LOW + (rand() % (TOP - LOW + 1));
    m = LOW + (rand() % (TOP - LOW + 1));

    for (int i = 0; i < n; ++i)
        putchar((char)((rand() % ('z' - 'a' + 1)) + 'a'));
    putchar('\n');
    for (int i = 0; i < m; ++i)
        putchar((char)((rand() % ('z' - 'a' + 1)) + 'a'));

    return 0;
}