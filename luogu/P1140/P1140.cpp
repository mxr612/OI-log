//P1140

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 150

const int tab[5][5] {
	{  5, -1, -2, -1, -3},
	{ -1,  5, -3, -2, -4},
	{ -2, -3,  5, -2, -2},
	{ -1, -2, -2,  5, -1},
	{ -3, -4, -2, -1,  0}
};

int la, lb;
char a[MAX], b[MAX];
int dp[MAX][MAX]={0};

int main() {
//InPut_OK
	freopen("testdata.in", "r", stdin);
	scanf("%d %s", &la, a + 1);
	scanf("%d %s", &lb, b + 1);
//ReSet
	for (int i = 1; i <= la; i++) {
		if (a[i] == 'A')a[i] = 0;
		if (a[i] == 'C')a[i] = 1;
		if (a[i] == 'G')a[i] = 2;
		if (a[i] == 'T')a[i] = 3;
	}
	for(int i=1;i<=lb;i++){
		if (b[i] == 'A')b[i] = 0;
		if (b[i] == 'C')b[i] = 1;
		if (b[i] == 'G')b[i] = 2;
		if (b[i] == 'T')b[i] = 3;
	}
	for(int i=1;i<=la;i++)
		dp[i][0]=dp[i-1][0]+tab[int(a[i])][4];
	for(int j=1;j<=lb;j++)
		dp[0][j]=dp[0][j-1]+tab[4][int(b[j])];

//DP
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			dp[i][j]=dp[i-1][j-1]+tab[int(a[i])][int(b[j])];
			dp[i][j]=max(dp[i][j],dp[i-1][j]+tab[int(a[i])][4]);
			dp[i][j]=max(dp[i][j],dp[i][j-1]+tab[4][int(b[j])]);
		}
	}
//OutPut
	// for(int i=0;i<=la;i++){
	// 	for(int j=0;j<=lb;j++){
	// 		printf("%4d",dp[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[la][lb];
	return 0;
}