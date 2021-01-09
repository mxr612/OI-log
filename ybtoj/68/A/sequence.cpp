/**
 * sequence
*/

#include <stdio.h>

#include <map>

const int MXN = 500012 * 3;

int n, L, R, arr[MXN], ll[MXN], rr[MXN];

std::map<int, int> map;
int tot;

long long ans[2], g;

long long gcd(long long a, long long b) { return (b == 0) ? (a) : (gcd(b, a % b)); }

class SZS {
    int n, arr[MXN];

   public:
    SZS(int a) { n = a; }
    void insert(int x) {
        for (; x <= n; x += x & -x)
            ++arr[x];
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res += arr[x];
        return res;
    }
};

signed main() {
    // freopen("sequence.in", "r", stdin);
    // freopen("sequence.out", "w", stdout);

    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i), arr[i] += arr[i - 1],
            ++map[ll[i] = arr[i] - L * i], ++map[rr[i] = arr[i] - R * i];

    for (std::map<int, int>::iterator i = map.begin(); i != map.end(); ++i)
        i->second = ++tot;

    SZS l(tot), r(tot);

    for (int i = 1; i <= n; ++i)
        ans[0] += l.query(map[ll[i]]) + r.query(map[rr[i]]),
            l.insert(map[ll[i]]), r.insert(map[rr[i]]);
    ans[1] = (1ll + n) * n / 2;

    g = gcd(ans[0], ans[1]);
    ans[0] /= g, ans[1] /= g;

    if (ans[0] == 0)
        printf("0");
    else if (ans[1] == 1)
        printf("1");
    else
        printf("%lld/%lld", ans[0], ans[1]);

    return 0;
}