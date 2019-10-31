// P1156

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int D, G;

struct garbage {int T, F, H;} garbages[110];
int _cmpS(garbage m, garbage n) {return m.T < n.T;}

struct zt {int T, H;} DP[2][2];

int main() {
// file
	freopen("P1156.in", "r", stdin);

// InPut
	cin >> D >> G;
	for (int i = 1; i <= G; i++)
		cin >> garbages[i].T >> garbages[i].F >> garbages[i].H;

// set
	sort(&garbages[1], &garbages[G + 1], _cmpS);

//DP
	DP[0][0].T = -1;
	DP[0][1].T = 10; DP[0][1].H = 0;
	for (int i = 1; i <= D; i++) { //garbage
		DP[i % 2][0].T = DP[i % 2][1].T = -1;
		if (DP[(i + 1) % 2][0].T >= garbages[i].T) {
			DP[i%2][0].T=DP[(i + 1) % 2][0].T;
			DP[i%2][0].H=DP[(i + 1) % 2][0].H+garbages[i].H;

			DP[i%2][1].T=DP[(i + 1) % 2][0].T+garbages[i].F;
			DP[i%2][1].H=DP[(i + 1) % 2][0].H;
		}

		if (DP[(i + 1) % 2][1].T >= garbages[i].T) {
			DP[i%2][0].T=DP[(i + 1) % 2][1].T;
			DP[i%2][0].H=DP[(i + 1) % 2][1].H+garbages[i].H;

			DP[i%2][1].T=DP[(i + 1) % 2][1].T+garbages[i].F;
			DP[i%2][1].H=DP[(i + 1) % 2][1].H;
		}

	}


// OutPut

	return 0;
}
