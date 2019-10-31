// #A

#include <iostream>
using namespace std;

#define LL long long

string l, r;
int T;

string x;
int pt;
int cnt;

int C(string a, string b) { //a<b-1 a=b0 a>b1
	if (a[0] == '-' && b[0] != '-') return -1;
	if (a[0] != '-' && b[0] == '-') return 1;
	if (a[0] != '-') {
		if (a.size() < b.size()) return -1;
		if (a.size() > b.size()) return 1;
		if (a[0] < b[0]) return -1;
		if (a[0] == b[0]) return 0;
		if (a[0] > b[0]) return 1;
	} else {
		if (a.size() > b.size()) return -1;
		if (a.size() < b.size()) return 1;
		if (a[0] > b[0]) return -1;
		if (a[0] == b[0]) return 0;
		if (a[0] < b[0]) return 1;
	}
	return 23333;
}

int main() {
	freopen("A.in", "r", stdin);
	cin >> l >> r >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> x;
		if (x[0] == '-') pt = 1; else pt = 0;
		if (x[pt] == '0'&&x.size() != 1) {
			cout << 1 << endl;
			continue;
		}
		for (int j = pt + 1; j < int(x.size()); j++)if (x[j] == '0')cnt++;
		if (cnt == int(x.size()) - pt - 1) {
			if (C(l, x) <= 0 && C(x, r) <= 0) {
				cout << 0 << endl;
			} else {
				cout << 2 << endl;
			}
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}