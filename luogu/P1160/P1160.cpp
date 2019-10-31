// P1160

#include <iostream>
using namespace std;

int N, M;
int pt = 1;

int L[100001] = {0}, R[100001] = {0};
bool in[100001] = {false};

int main() {
	freopen("P1160.in", "r", stdin);
	in[1]=true;
	cin >> N;
	for (int i = 2, k, p; i <= N; i++) {
		cin >> k >> p;
		if (p == 0) {
			L[i] = L[k];
			R[i] = k;
			R[L[k]] = i;
			L[k] = i;
		} else {
			L[i] = k;
			R[i] = R[k];
			L[R[k]] = i;
			R[k] = i;
		}
		in[i] = true;
	}
	cin >> M;
	for (int i = 1, x; i <= M; i++) {
		cin >> x;
		if (in[x]) {
			R[L[x]] = R[x];
			L[R[x]] = L[x];
			in[x] = false;
		}
	}
	while (!(L[pt] == 0 && in[pt]))pt++;
	while (pt != 0) {
		cout << pt << ' ';
		pt = R[pt];
	}
	return 0;
}