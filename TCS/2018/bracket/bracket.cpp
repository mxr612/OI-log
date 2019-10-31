// bracket.in

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n;
string str;
bool flag;
int s, m, b;

int main() {
	freopen("bracket2.in", "r", stdin);
	 freopen("bracket.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		flag = true;
		s = m = b = 0;
		cin >> str;
		for (int i = 0, len = str.length(); i < len && flag; i++) {
			if (str[i] == '(')s++;
			if (str[i] == ')')s--;
			if (str[i] == '[')m++;
			if (str[i] == ']')m--;
			if (str[i] == '{')b++;
			if (str[i] == '}')b--;

			if ((str[i] == '{' || str[i] == '}') && (s != 0 || m != 0))flag = false;
			if ((str[i] == '[' || str[i] == ']') && s != 0)flag = false;
			if (s < 0 || m < 0 || b < 0)flag = false;
		}
		if (s != 0 || m != 0 || b != 0)flag = false;
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
