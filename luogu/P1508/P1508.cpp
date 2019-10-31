#include <iostream>
#include <cstring>

using namespace std;

int m,n;
int food[300][300];
int dp[300][300];
int ans;

int main(){
	freopen("P1508.in","r",stdin);
//InPut
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>food[i][j];
//Reset
	memset(dp,128,sizeof(dp));
	ans=dp[0][0];
	dp[m+1][(n-1)/2+1]=0;
//DP??
	for(int i=m;i>0;i--){
		for(int j=1;j<=n;j++){
			if(j>1)
				dp[i][j]=max(dp[i][j],dp[i+1][j-1]+food[i][j]);
			dp[i][j]=max(dp[i][j],dp[i+1][j]+food[i][j]);
			if(j<n)
				dp[i][j]=max(dp[i][j],dp[i+1][j+1]+food[i][j]);
		}
	}
//OutPut
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[1][i]);
	cout<<ans;
	return 0;
}