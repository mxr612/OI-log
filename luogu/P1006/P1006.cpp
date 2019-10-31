// P1006

#include <iostream>
using namespace std;

int m,n;
int stu[60][60]={0};
int DP[150][150][150]={0};

int main(){
// In
	freopen("testdata.in","r",stdin);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>stu[i][j];
		}
	}
// Pre
	DP[3][1][2]=stu[1][2]+stu[2][1];
// DP
	for(int s=4;s<m+n;s++){
		for(int a=(s-n>0)?s-n:1;a<s-1&&a<=m;a++){
			for(int b=a+1;b<=s-1&&b<=m;b++){
				DP[s][a][b]=max(DP[s-1][a-1][b],DP[s-1][a-1][b-1]);
				DP[s][a][b]=max(DP[s][a][b],DP[s-1][a][b]);
				if(b-1!=a)DP[s][a][b]=max(DP[s][a][b],DP[s-1][a][b-1]);
				DP[s][a][b]+=stu[a][s-a]+stu[b][s-b];
			}
		}
	}
// Out
	cout<<DP[m+n-1][m-1][m];
	return 0;
}