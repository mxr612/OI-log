// 1

#include <iostream>
using namespace std;

#define MOD 1000000007

unsigned int x, ans = 0;

int main() {
	cin >> x;
	while (x > 0)
		x = ((x << 1) + 1) % MOD, ans++;
	cout << (ans - 1) / 3 + 1;
	return 0;

}
