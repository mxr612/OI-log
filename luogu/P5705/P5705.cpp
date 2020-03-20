/**
 * P5705
 */

#include <iostream>
#include <string>

int main() {
	freopen("P5705.in", "r", stdin);
	std::string s;
	std::cin >> s;
	for (int i = s.size() - 1; i >= 0; --i)
		std::cout << s[i];
	return 0;
}