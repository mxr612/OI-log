// 0

#include <iostream>
#include <stack>
using namespace std;

int n, a[100001], p, t;
stack<int>s;

int main() {

	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);

	cin >> n;
	while (n > 0) {

		cin >> a[1];
		while (a[1] > 0) {

			for (int i = 2; i <= n; ++i)
				cin >> a[i];
			p = 1; t = 2;
			s.push(1);
			while (t <= n) {
				while (t <= n && (s.empty() || s.top() != a[p]))s.push(t++);
				while (!s.empty() && s.top() == a[p])s.pop(), p++;
			}
			if (s.empty()) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
				while (!s.empty())s.pop();
			}

			cin >> a[1];
		}
		cout << endl;

		cin >> n;
	}

	return 0;

}