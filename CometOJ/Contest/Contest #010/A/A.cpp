// A

#include <stdio.h>
#include <iostream>
#include <string>

int n, ans = 0;
std::string str, cmp;

int main() {

	freopen("A.in", "r", stdin);

	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		std::cin >> str;
		if (str.size() >= 5) {
			cmp.assign(str, str.size() - 5, 5);
			if (cmp == "acpty")
				++ans;
		}
	}

	std::cout << ans;

	return 0;
}