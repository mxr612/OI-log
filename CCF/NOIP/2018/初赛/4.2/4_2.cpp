#include<iostream>
using namespace std;
const int N = 100010;
int n; int L[N], R[N], a[N];
int main() {
	freopen("4_2.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; ++i) {
		R[i] = i + 1;
		L[i] = i - 1;
	}
	for (int i = 1; i < n; ++i) {
		L[R[a[i]]] = L[a[i]];
		R[L[a[i]]] = R[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		cout << R[i] << " ";
	}
	return 0;
}