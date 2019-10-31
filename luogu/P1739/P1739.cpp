// P1739

#include <iostream>
#include <cstdio>
using namespace std;

int cnt = 0;
char c;

int main() {
	freopen("P1739.in", "r", stdin);
	c = getchar();
	while (c != '@' && cnt >= 0) {
		if (c == '(')
			cnt++;
		else if (c == ')')
			cnt--;
		c = getchar();
	}
	if (cnt == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}