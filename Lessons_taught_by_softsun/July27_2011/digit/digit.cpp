#include<stdio.h> 

int ans=0,cmp;

int main() {
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	for(int i=0;i<100;i++) {
		cmp=getchar();
		if(cmp<'0'||cmp>'9') {
			break;
		}
		ans+=cmp-'0';
	}
	while(ans/10!=0) {
		cmp=ans;
		ans=0;
		while(cmp!=0) {
			ans+=cmp%10;
			cmp/=10;
		}
	}
	printf("%d",ans);
	return 0;
}
