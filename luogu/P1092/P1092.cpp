// P1092

#include <iostream>
#include <cstring>
using namespace std;

int N;

int F[4][30], S[4][30] = {0},A[30];
bool U[30] = {false};

void pl(short a[], int x, int y) {
	int cmp = 0;
	a[x] += y;
	for (int i = x; i <= N; i++) {
		a[i] += cmp;
		cmp = a[i] / 10;
		a[i] %= 10;
	}
}

void re(short a[], int x, int y) {
	int cmp = 0;
	a[x] -= y;
	for (int i = x; i <= N; i++) {
		a[i] -= cmp;
		if (a[i] < 0) {
			a[i] += 10;
			cmp = 1;
		} else
			cmp = 0;
	}
}

void ch(int art,int f){
	if(!U[f]){
		U[f]=true;
		A[art]=f;
		for(int i=1;i<=3;i++){
			for(int j=0;j<N;j++){

			}
		}
	}else{
		U[f]=false;
		for(int i=1;i<=3;i++){
			for(int j=0;j<N;j++){
				
			}
		}
	}
}

void dfs(int art) {
	if (art > N) {
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (!U[i]) {
			ch(art,i);

			ch(art,i);
		}
	}
}

int main() {
	freopen("P1092.in", "r", stdin);

	cin >> N;
	for (int i = 1; i <= 3; i++) {
		for (int j = N - 1; j >= 0; j++) {
			char cmp;
			cin >> cmp;
			F[i][j] = cmp - 'A';
		}
	}
	dfs(0);

	return 0;
}