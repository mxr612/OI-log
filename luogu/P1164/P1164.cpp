#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_M 1000

int N, M, ans = 0;
int a[MAX_N + 1] = {0};
int sum = 0;

void count(int w) {
	if (w > N) {
		return ;
	}
	count(w + 1);
	sum += a[w];
	if (sum < M ) {
		count(w + 1);
	} else if (sum == M) {
		ans++;
	}
	sum -= a[w];
}

int main(int argc, char const *argv[])
{
	// freopen("P1164.in", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	count(1);
	cout << ans;
	return 0;
}