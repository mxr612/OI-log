
#define MXN (100020)
#define MXA (1000020)
#define MXP (80000)
#define MOD (1000000007)

#include <stdio.h>
#include <math.h>
#include <string.h>

int pr[MXP],p=0;
bool np[MXA];

long long mi[MXN];

int t;

int apr[MXP];

class Bin{
	int fa[MXN];
	public:
	int cnt;
	void clear(){memset(fa,0,sizeof(fa)),cnt=0;}
	void make(int x){fa[x]=x,++cnt;}
	int find(int x){return (fa[x]==x)?(x):(fa[x]=find(fa[x]));}
	void merge(int x,int y){if(find(x)!=find(y))fa[find(x)]=find(y),--cnt;}
	long long query(){return cnt;}
}bin;



signed main(){
	
	freopen("A.in","r",stdin);
	
	for(int i=2,j;i<MXA;++i){
		if(!np[i])pr[p++]=i;
		for(j=0;j<p&&i*pr[j]<MXA;++j)np[i*pr[j]]=true;
	}
	
	mi[0]=1;
	for(int i=1;i<MXN;++i)
		mi[i]=(mi[i-1]<<1)%MOD;
	
	scanf("%d",&t);	
	
	for(int i,j,n,a;t-->0;){
		bin.clear();
		memset(apr,0,sizeof(apr));
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a);
			bin.make(i);
			for(j=0;a>1;++j){
				if(a%pr[j]==0){
					if(apr[pr[j]])bin.merge(apr[pr[j]],i);
					else apr[pr[j]]=i;
					while(a%pr[j]==0)a/=pr[j];
				}
			}
		}
		printf("%lld\n",(bin.cnt<2)?(0):((mi[bin.cnt]+MOD-2)%MOD));
	}
	
	return 0;
}
