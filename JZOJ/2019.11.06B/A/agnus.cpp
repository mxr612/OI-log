/**
 * 2019.11.06【NOIP提高组】模拟 B 组
 * A 寻找羔羊(agnus)
 */

#include <stdio.h>
#include <string>
#include <iostream>

int _low(int x) {return x < 1 ? 0 : x;}

std::string s;
char goal[] = "agnus";
bool a[30020] = {false};
int ans = 0;

bool _is_same(int p) {
	if ((int)s.size() - p < 5)
		return false;
	for (int i = 0; i < 5; ++i)
		if (s[p + i] != goal[i])
			return false;
	return true;
}

int main() {
	freopen("agnus.in", "r", stdin);
	std::cin >> s;
	for (int i = 0, rec = -1; i < (int)s.size(); ++i)
		if (_is_same(i))
			ans += ((int)s.size() - i - 4) * _low(i - rec), rec = i;
	std::cout << ans;
	return 0;
}