#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 300

int N, ans = 0;
int sign[MAX_N] = {0};
int DP[MAX_N][MAX_N] = {0};

int main(int argc, char const *argv[])
{
	freopen("testdata.in", "r", stdin);
	// freopen("P1063.out", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sign[i];
		sign[i + N] = sign[i];
	}
	for (int l = 1; l < N; l++) {
		for (int i = 1; i < 2 * N-l; i++) {
			int j = i + l;
			for(int k=i+1;k<=j;k++){
				DP[i][j]=max(DP[i][j],DP[i][k-1]+DP[k][j]+sign[i]*sign[k]*sign[j+1]);
			}
			ans=max(ans,DP[i][j]);
		}
	}
	// for(int i=1;i<=2*N;i++){
	// 	printf("%3d",sign[i]);
	// }
	// putchar('\n');
	// for (int i = 1; i <= 2 * N; i++) {
	// 	for (int j = 1; j <= 2 * N; j++) {
	// 		printf("%10d", DP[i][j]);
	// 	}
	// 	putchar('\n');
	// }
	cout<<ans;
	return 0;
}