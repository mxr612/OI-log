// 最小生成树 13:28.54

#include <stdio.h>
#include <algorithm>

const int MXN = 200056;

struct Edge{
	int x,y,w;
	bool operator<(const Edge e)const{return w<e.w;}
}edge[MXN];

Edge make_edge(const int x,const int y,const int w){
	Edge e;
	e.x=x,e.y=y,e.w=w;
	return e;
}

class Bin{
	
	int num;
	int *frm,*siz;
	
	int find(int x){return (frm[x]==x)?(x):(frm[x]=find(frm[x]));}
	
	public:
	Bin(int n){
		num=n;
		frm=(int*)calloc(sizeof(int),n+32);
		siz=(int*)calloc(sizeof(int),n+32);
		for(int i=1;i<=n;++i)
			frm[i]=i;
	}
	bool is_same(int x,int y){return find(x)==find(y);}
	void merge(int x,int y){
		if(is_same(x,y))return;
		x=find(x),y=find(y);
		if(siz[x]<siz[y])x^=y^=x^=y;
		siz[x]+=siz[y];
		frm[y]=x;
		--num;
	} 
	int cnt(){return num;}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3366.in","r",stdin);
#endif
	
	int N,M;
	long long ans=0;
	
	scanf("%d%d",&N,&M);
	
	Bin bin(N);
	
	for(int i=0,x,y,z;i<M;++i)
		scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
	
	std::sort(edge,edge+M);
	
	for(int i=0;i<M&&bin.cnt()>1;++i)
		if(!bin.is_same(edge[i].x,edge[i].y))
			ans+=edge[i].w,bin.merge(edge[i].x,edge[i].y);
			
	if(bin.cnt()>1)
		printf("orz");
	else 
		printf("%lld",ans);
	
	return 0;
}
