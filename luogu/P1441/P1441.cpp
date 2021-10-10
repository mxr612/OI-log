/*
长大是需要勇敢的。20201009 
*/ 

#include <stdio.h>
#include <string.h>

#include <algorithm>

int n,m;
int a[30];
int ans=0;

bool f[3000];
int dp(int sta){
	int res=0;
	memset(f,0,sizeof(f)),f[0]=true;
	for(int i=0,j;i<n;++i)
		if(!(sta&(1<<i)))
			for(j=2000;j>=a[i];--j)
				f[j]|=f[j-a[i]];
	for(int i=1;i<=2000;++i)
		res+=f[i];
	return res;
}

void dfs(int dep,int cur,int sta){
	if(cur==m)
		ans=std::max(ans,dp(sta));
	else if(dep<n)
		dfs(dep+1,cur+1,sta|(1<<dep)),
		dfs(dep+1,cur,sta);
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1441.in","r",stdin);
#endif
	
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
		
	dfs(0,0,0);
	
	printf("%d",ans);
	
	return 0;
} 
