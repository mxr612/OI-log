/////////////////////////////
// 2019年11月14日提高组Day2 //
// A 种田                  //
/////////////////////////////

#include <stdio.h>
#include <algorithm>
long long N, M, L, K, A, B, ans = 0;
long long _gcd(long long a, long long b) {return b == 0 ? a : _gcd(b, a % b);}
long long _ceil(long long A, long long K) {if (A % K == 0)return A / K; return (A / K) + 1;}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%lld%lld%lld", &N, &M, &L);
	K = N / _gcd(N, M) * M;
	A = _ceil(N, L) * _gcd(N, M) / N;
	B = _ceil(M, L) * _gcd(N, M) / M;
	printf("%lld\n", std::min(A, B)*std::min(A, B)/2);
	return 0;
}