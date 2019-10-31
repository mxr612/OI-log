// pass.in

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

char num[4];
int a = 0, b = 0;

char _SortCmp(char m, char n) {return m > n;}

int main() {
	freopen("pass.in", "r", stdin);
	freopen("pass.out", "w", stdout);


	for (int i = 0; i < 4; i++)
		cin >> num[i];

	sort(num, num + 4, _SortCmp);
	for (int i = 0; i < 4; i++)
		a = a * 10 + num[i] - '0';

	sort(num, num + 4);
	for (int i = 0; i < 4; i++)
		b = b * 10 + num[i] - '0';

	cout << (a - b);

	return 0;
}