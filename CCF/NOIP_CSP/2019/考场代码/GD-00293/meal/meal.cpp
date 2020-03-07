#include <stdio.h>
int n,m;
unsigned long long ans=0;
struct __node{
	int a,b;
}_A_w[20000020];
bool _A_isa[20000020]={false};
int _A_isb[20000020]={0},pt=0,now;
void _A_dfs(int x,int c){
	if(c==now){
		ans=(ans+1)%998244353;
		return;
	}
	if(x>pt)
		return ;
	if(!_A_isa[_A_w[x].a]&&_A_isb[_A_w[x].b]<(now>>1)){
		_A_isa[_A_w[x].a]=true;
		++_A_isb[_A_w[x].b];
		_A_dfs(x+1,c+1);
		_A_isa[_A_w[x].a]=false;
		--_A_isb[_A_w[x].b];
	}
	_A_dfs(x+1,c);
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=40){
		for(int i=1,z;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&z);
				while(z-->0){_A_w[++pt].a=i;_A_w[pt].b=j;}
			}
		}
		now=pt;
		while(--now>0)_A_dfs(1,0);
		printf("%lld",ans);
	}else
		printf("I LOVE FXY!");
	return 0;
}
