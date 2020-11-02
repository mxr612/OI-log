
#include <stdio.h>

const int MXN = 1000024;

int arr[MXN];

signed main(){
	
	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	
	int T;
	int n,K;
	long long ans;
	
	scanf("%d",&T);
	
	while(T--){
		ans=0;
		scanf("%d%d",&n,&K);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		if(n<=5000){ // SubI 20pts
			for(int i=0,j,s;i<n;++i)
				for(s=0,j=i;j<n;++j)
					ans+=((s^=arr[j])>=K);
			printf("%lld\n",ans);
		}else{
			
		}
	}
	
	return 0; 
}

