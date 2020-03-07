#include <stdio.h>
#include <stdlib.h>

int T,n;

struct __edge{
	int v;
	__edge *nx;
}*edge[2020]={NULL};
void _add_edge(int u,int v){
	__edge *p=(__edge *)calloc(1,sizeof(__edge));
	p->v=v;
	p->nx=edge[u];edge[u]=p;
}

int due[2020];
int _is_flw(){
	for(int i=1;i<=n;++i)
		if(due[i]==n-1)
			return i;
	return -1;
}

int _is_line(){
	int res=-1;
	for(int i=1;i<=n;++i){
		if(due[i]==1)
			res=i;
		if(due[i]>2)
			return -1;
	}
	return res;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T-->0){
		scanf("%d",&n);
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			_add_edge(u,v);_add_edge(v,u);
			++due[u];++due[v];
		}
		if(n<=10){
			
		}else if(_is_flw()>-1){
			
		}else if(_is_line()>-1){
			
		}
		for(int i=1;i<=n;++i)
			printf("%d ",i);
		putchar('\n');
	}
	return 0;
}
