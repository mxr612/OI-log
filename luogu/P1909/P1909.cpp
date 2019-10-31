/**
 * P1909
 * 买铅笔
 */

#include <iostream>
#include <cstdio>
using namespace std;

long long n, ans = 100000000;
int A[2], B[2], C[2];

int main(int argc, char const *argv[])
{
	freopen("P1909.in", "r", stdin);
	cin >> n;
	cin >> A[0] >> A[1];
	cin >> B[0] >> B[1];
	cin >> C[0] >> C[1];
	ans = min(ans, (n / A[0] + ((n % A[0]) > 0 ? 1 : 0)) * A[1]);
	ans = min(ans, (n / B[0] + ((n % B[0]) > 0 ? 1 : 0)) * B[1]);
	ans = min(ans, (n / C[0] + ((n % C[0]) > 0 ? 1 : 0)) * C[1]);
	cout << ans;
	return 0;
}