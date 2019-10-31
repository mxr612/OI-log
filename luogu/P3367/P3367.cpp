// P3367 【模板】并查集

#include <iostream>
using namespace std;

int N, M, z, x, y;
int F[11000], S[11000];

int _Get(int id) {
	if (F[id] != id)
		F[id] = _Get(F[id]);
	return F[id];
}

void _Merge(int ida, int idb) {
	int fa = _Get(ida), fb = _Get(idb);
	if (S[ida] < S[idb])
		F[fa] = fb;
	else
		F[fb] = fa;
}

int main() {

	freopen("P3367.in", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		F[i] = i, S[i] = 1;

	for (int i = 1; i <= M; ++i) {
		cin >> z >> x >> y;
		if (z == 1) {
			_Merge(x, y);
		} else {
			cout << ((_Get(x) == _Get(y)) ? 'Y' : 'N') << endl;
		}
	}

	return 0;
}