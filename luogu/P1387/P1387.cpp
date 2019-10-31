// P1387

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=200;

int n,m;
int mapp[MAX][MAX]={0};
int x[MAX]={0},y[MAX]={0};
int longger[MAX][MAX]={0};
int dp[MAX][MAX]={0};
int ans=-1;

int main(){
// InPut
	freopen("P1387.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mapp[i][j];
// Reset
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mapp[i][j]==0){
				x[j]=i;y[i]=j;
			}
			longger[i][j]=min(i-x[j],j-y[i]);
		}

// DP
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dp[i][j]=min(dp[i-1][j-1]+1,longger[i][j]);
		}
// OutPut
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++){
			ans=max(ans,dp[i][j]);
		}
	cout<<ans;
	return 0;

}