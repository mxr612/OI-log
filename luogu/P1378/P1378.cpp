// P1378

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define PI 3.1415926535
#define zrs(tjq) ((tjq)<0?(0):(tjq))
#define Qi qpl[i]
#define Endl endl

int N;
int xa, ya, xb, yb;

double x[10] = {0}, y[10] = {0}, cE[10][10] = {0};

int cmm[10];

int qpl[10];
bool usa[10] = {false};
double mm[10];

double ans = 0;

void dfs(int dep) {
	if (dep > N) {
		double cmp = 0;
		for (int i = 1; i <= N; ++i)
			mm[i] = cmm[i];
		for (int i = 1; i <= N; ++i) {
			cmp += PI * mm[Qi] * mm[Qi];
			for (int j = 1; j <= N; ++j) {
				if (j != Qi) {
					mm[j] = min(mm[j], zrs(cE[j][Qi] - mm[Qi]));
				}
			}
		}
		ans = max(ans, cmp);
		return ;
	}
	for (int i = 1; i <= N; ++i) {
		if (!usa[i]) {
			usa[i] = true;
			qpl[dep] = i;
			dfs(dep + 1);
			usa[i] = false;
		}
	}
}

int sswr(double num) {
	int cmp = num;
	return cmp + (((num - cmp) < 0.5) ? (0) : (1));
}

int main() {

	freopen("P1378.in", "r", stdin);
	freopen("P1378.out", "w", stdout);

	cin >> N;
	cin >> xa >> ya >> xb >> yb;

	for (int i = 1; i <= N; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			cE[i][j] = cE[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

	for (int i = 1; i <= N; ++i) {
		cmm[i] = min(min(abs(x[i] - xa), abs(x[i] - xb)), min(abs(y[i] - ya), abs(y[i] - yb)));
	}

	dfs(1);

	cout << sswr(abs(xa - xb)*abs(ya - yb) - ans);

	return 0;
}