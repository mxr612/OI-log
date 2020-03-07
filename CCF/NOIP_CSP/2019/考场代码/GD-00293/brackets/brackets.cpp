#include <stdio.h>
#include <stdlib.h>
int n,x,w;
char s[500020];
short c[500020];
unsigned long long ans=0,k,z;
struct __edge{
	int v;
	__edge *nx;
}*edge[500020]={NULL};
void _add_edge(int u,int v){
	__edge *p=(__edge *)calloc(1,sizeof(__edge));
	p->v=v;
	p->nx=edge[u];
	edge[u]=p;
}
void _free_edge(__edge *&p){
	if(p!=NULL){
		_free_edge(p->nx);
		free(p);
		p=NULL;
	}
}
struct __state{
	int x,w;
	unsigned long long k,z;
	__state *nx;
}*top=NULL;
void _push(int x,int w,unsigned long long z,unsigned long long k){
	__state *p=(__state *)calloc(1,sizeof(__state));
	p->x=x;p->w=w;p->z=z;p->k=k;
	p->nx=top;top=p;
}
__state _pop(){
	if(top!=NULL){
		__state *p=top;
		top=top->nx;
		free(p);
	}
}
int _low(int x){return x<0?0:x;}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;++i){
		if(s[i]=='(') c[i+1]=1;
		else c[i+1]=-1;
	}
	for(int i=2;i<=n;++i){
		scanf("%d",&x);
		_add_edge(x,i);
	}
	for(__edge *i=edge[1];i!=NULL;i=i->nx)
		_push(i->v,_low(c[1]),0,0);
	while(top!=NULL){
		x=top->x;w=top->w;z=top->z;k=top->k;
		_pop();
		w+=c[x];
		if(c[x]==-1&&w>=0)++k;
		if(c[x]==-1&&w==0)++z;
		ans^=x*(k+(1+z)*z/2-z);
		for(__edge *i=edge[x];i!=NULL;i=i->nx)
			_push(i->v,_low(w),z,k);
	}
	printf("%lld",ans);
	for(int i=1;i<=n;++i)
		_free_edge(edge[i]);
	return 0;
}
