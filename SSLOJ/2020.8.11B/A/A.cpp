#include <stdio.h>

int n,ans;

int gcd(int a,int b){
	return (b==0)?(a):(gcd(b,a%b));
}

signed main(){
	
	scanf("%d",&n);
	
	for(int i=1,j;i<=n;++i)
		for(j=i;j<=n;++j)
			if((i^j)==(gcd(i,j)))
			++ans;
				
				
	printf("%d",ans);
				
	return 0;
}
