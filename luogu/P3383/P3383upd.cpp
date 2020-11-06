// 12:56.29
 
#include <stdio.h>

const int MXN = 100000024,
			MXP = 6000000;

bool isp[MXN];
int prm[MXP],tot;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3383.in","r",stdin);
#endif

	int n,q;
	
	scanf("%d%d",&n,&q);

	for(int i=2,j;i<=n;++i){
		if(!isp[i])prm[tot++]=i;
		for(j=0;j<tot&&i*prm[j]<=n;++j)isp[i*prm[j]]=true;
	}

	for(int i=0,x;i<q;++i)
		scanf("%d",&x),
		printf("%d\n",prm[x-1]);
	
	return 0;
}
