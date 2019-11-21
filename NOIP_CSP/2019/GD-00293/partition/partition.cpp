#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int n,type;
unsigned long long ans=-1;
unsigned long long a[500020]={0};
struct __A{
	int x,h;
	unsigned long long w;
}cmp,top;
void _A_(){
	
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		a[i]+=a[i-1];
	std::queue<__A>pq;
	cmp.x=0;cmp.w=0;cmp.h=0;
	pq.push(cmp);
	while(!pq.empty()){
		top=pq.front();pq.pop();
		if(top.x==n)
			ans=std::min(ans,top.w);
		for(cmp.x=n;cmp.x>top.x&&(a[cmp.x]-a[top.x])>=top.h;--cmp.x){
			cmp.w=top.w+(a[cmp.x]-a[top.x])*(a[cmp.x]-a[top.x]);
			cmp.h=a[cmp.x]-a[top.x];
			pq.push(cmp);
		}
	}
}

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&type);
	if(type==0){
		_A_();
		printf("%lld",ans);
	}else
		printf("CCF LIKE MONEY!");
	return 0;
}
