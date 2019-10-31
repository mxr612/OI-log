#include <stdio.h>
#include <string.h>

#define MID 30000
#define min(a,b) a<b?a:b

int n;
int a,b;
int dp[60000];
int ans = MID;

int main()
{
	freopen("testdata.in", "r", stdin);
	memset(dp, int(0x6f), sizeof(dp));
	dp[MID]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a,&b);
		a-=b;
		ans-=a;
		if(a>0){
			for(int j=MID-6*n;j<MID+6*n;j++){
				dp[j]=min(dp[j],dp[j+2*a]+1);
			}
		}else if(a<0){
			for(int j=MID+6*n;j>MID-6*n;j--){
				dp[j]=min(dp[j],dp[j+2*a]+1);
			}
		}
	}
	// for(int i=-5*n;i<=5*n;i++){
	// 	printf("%d %d\n",i,dp[MID+i]);
	// }
	// printf("%d\n",ans);
	if(dp[ans]==dp[0]){
		ans=min(dp[ans+1],dp[ans-1]);
	}else{
		ans=dp[ans];
	}
	printf("%d\n",ans);
	return 0;
}