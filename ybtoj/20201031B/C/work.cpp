
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

const int MXN = 32,
			MXS = 64,
			MXT = 2097152;
			
int n;
char S[MXN][MXS];

struct Work{
	int r,D,C;
}work[MXN];

int ans, sor[32],answ[32];

// SubI

void SubI(int dep,int sta,int tim,int res){
	if(res>=ans||dep>=n){
		if(res<ans){
			ans=res;
			for(int i=0;i<n;++i)
				answ[i]=sor[i];
		}
	}else{
		for(int i=0;i<n;++i)
			if(!(sta&(1<<i)))
				sor[dep]=i,
				SubI(dep+1,sta|(1<<i),tim+work[i].C,res+std::max(0,tim+work[i].C-work[i].D));
	}
}

int ti[MXT],fr[MXT];
long long dp[MXT];

void print(int sta){
	if(sta)
		print(fr[sta]),
		printf("%s\n",S[int(log2(sta^fr[sta]))]);
}

signed main(){
	
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	
	int T;
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s%d%d",S[i],&work[i].D,&work[i].C),
			work[i].r=(i>0&&!strcmp(S[i-1],S[i])?(work[i-1].r):(i));
		if(n<=10){ // SubI 30pts
			ans=1e9;
			SubI(0,0,0,0);
			printf("%lld\n",ans);
			for(int i=0;i<n;++i)
				printf("%s\n",S[work[answ[i]].r]);
		}else{
			memset(dp,0x6f,sizeof(dp)),dp[0]=0;
			long long res;
			for(int i=0,j,jj,k;i<(1<<n);++i)
				for(j=0,jj=1;j<n;++j,jj<<=1)
					if(i<(k=(i|jj))&&(res=dp[i]+std::max(0,(ti[k]=ti[i]+work[j].C)-work[j].D))<dp[k])
						dp[k]=res,fr[k]=i;
			printf("%lld\n",dp[(1<<n)-1]);
			print((1<<n)-1);
		}
	}
	
	return 0;
}
