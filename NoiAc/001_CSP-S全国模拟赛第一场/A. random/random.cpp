// A. random

#include <string.h>
#include <iostream>
using namespace std;

int T;
int N, A[11000000], B[11000000];
int cA[1100000], cB[1100000];
int Sa, Sb;

int main() {

	freopen("random.in", "r", stdin);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N;
		memset(cA, 0, sizeof(cA));
		memset(cB, 0, sizeof(cB));
		Sa = Sb = 0;
		for (int i = 1; i <= N; ++i)
			cin >> A[i], ++cA[A[i]];
		for (int i = 1; i <= N; ++i)
			cin >> B[i], ++cB[B[i]];
		for (int i = 1; i < 11000; ++i)
			cA[i] += cA[i - 1], cB[i] += cB[i - 1];
		for (int i = 1; i <= N; ++i)
			Sa += cB[A[i] - 1], Sb += cA[B[i] - 1];
		if (Sa > Sb)
			cout << "Alice" << endl;
		else if (Sa < Sb)
			cout << "Bob" << endl;
		else
			cout << "Tie" << endl;
	}

	return 0;
}
