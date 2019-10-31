#include <iostream>

using namespace std;

int num[1000];
int len = 0;

int main() {
	freopen("P1427.in", "r", stdin);
	do cin >> num[++len]; while (num[len] != 0);
	for (int i = len - 1; i > 0; i--)
		cout << num[i] << ' ';
	return 0;
}