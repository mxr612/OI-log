/**
 * A
 */

#include <stdio.h>
#include <iostream>
#include <string>

signed main() {

	freopen("A.in", "r", stdin);

	int t;
	std::string s;

	scanf("%d", &t);

	for (register int i = 0, I = t, ans0, ans1, ans2; i < I; ++i) {
		ans0 = ans1 = ans2 = 0;
		std::cin >> s;
		for (register int j = 0; j < s.length(); ++j)
			if (s[j] == '0')
				++ans0;
		for (register int j = 0; j < s.length() && s[j] != '1'; ++j)
			++ans1;
		for (register int j = s.length() - 1; j >= 0 && s[j] != '1'; --j)
			++ans2;
		if (ans1 == (int)s.length())
			printf("0\n");
		else
			printf("%d\n", ans0 - ans1 - ans2);
	}

	return 0;
}