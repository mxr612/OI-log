/**
 * CF1301 A
 */

#include <stdio.h>
#include <string>
#include <iostream>

int main() {

	// freopen("A.in", "r", stdin);

	int n;
	std::string a, b, c;

	scanf("%d", &n);

	for (register int i = 0, j = 0; i < n; ++i, j = 0) {
		std::cin >> a >> b >> c;
		while (j < (int)a.length() && (a[j] != b[j] || (a[j] == b[j] && b[j] == c[j])) && ((a[j] == c[j]) || (b[j] == c[j])))++j;
		printf("%s\n", (j == (int)a.length()) ? "YES" : "NO");
	}

	return 0;
}