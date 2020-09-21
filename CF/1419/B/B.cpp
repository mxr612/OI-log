/**
 * CF1419B
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

int t;
long long x;
std::vector<int> ans;
int k;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &t);

    ans.push_back(0), ans.push_back(1);
    for (k = 2; ans[k - 1] <= 1e6; ++k)
        ans.push_back(ans[ceil(k / 2.0)] * 2 + 1);

    while (t--) {
        scanf("%lld", &x);
        printf("%d\n", std::lower_bound(&ans[0], &ans[ans.size()], floor((sqrt(1 + 8 * x) - 1) / 2)) - &ans[0]);
    }

    return 0;
}