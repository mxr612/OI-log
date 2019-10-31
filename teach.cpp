#include "iostream"
using namespace std;

int ans;

int main() {
	int la, lb, lc, ld, le, lf, lg, ra, rb, rc, rd, re, rf, rg;
	cin >> la >> ra;
	cin >> lb >> rb;
	cin >> lc >> rc;
	cin >> ld >> rd;
	cin >> le >> re;
	cin >> lf >> rf;
	cin >> lg >> rg;

	ans = la + ra;
	ans = max(ans, lb + rb);
	ans = max(ans, lc + rc);
	ans = max(ans, ld + rd);
	ans = max(ans, le + re);
	ans = max(ans, lf + rf);
	ans = max(ans, lg + rg);
	if (ans <= 8)
		cout << 0;
	else if (ans == la + ra)
		cout << 1;
	else if (ans == lb + rb)
		cout << 2;
	else if (ans == lc + rc)
		cout << 3;
	else if (ans == ld + rd)
		cout << 4;
	else if (ans == le + re)
		cout << 5;
	else if (ans == lf + rf)
		cout << 6;
	else if (ans == lg + rg)
		cout << 7;














	return 0;
}
