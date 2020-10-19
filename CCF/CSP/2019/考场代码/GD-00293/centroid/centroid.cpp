#include <stdio.h>
#include <stdlib.h>

int T,n,due[262163],plu,now;
unsigned long long ans;

struct __edge{
	int u,v,s;
	__edge *nx,*fb;
}*edge[262163]={NULL};

__edge *_add_edge(int u,int v){
	__edge *p=(__edge *)calloc(1,sizeof(__edge));
	p->u=u;p->v=v;p->nx=edge[u];edge[u]=p;
	return p;
}
void _A_fb(__edge *x,__edge *y){x->fb=y;y->fb=x;}
void _free_edge(__edge *&p){
	if(p!=NULL){
		_free_edge(p->nx);free(p);p=NULL;
	}
}

int _A_pre_dfs(int x,int f){
	int res=1;
	for(__edge *i=edge[x];i!=NULL;i=i->nx){
		if(i->v!=f){
			i->s=_A_pre_dfs(i->v,x);
			i->fb->s=n-i->s;
			res+=i->s;
		}
	}
	return res;
}

void _A_ans_dfs(int x,int f){
	bool is=true;
	for(__edge *i=edge[x];i!=NULL;i=i->nx){
		if(i->v==f){
			if(i->s-plu>now)
				is=false;
		}else{
			if(i->s>now)
				is=false;
			_A_ans_dfs(i->v,x);
		}
	}
	if(is)ans+=x;
}

int _is_line(){return -1;}

int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&T);
	while(T-->0){
		ans=0;
		scanf("%d",&n);
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			_A_fb(_add_edge(u,v),_add_edge(v,u));
			++due[u];++due[v];
		}
		if(n<=199995){
			_A_pre_dfs(1,1);
			for(int i=1;i<=n;++i){
				for(__edge *j=edge[i];j!=NULL;j=j->nx){
					if(j->u<j->v){
						plu=j->s;now=(j->fb->s)>>1;
						_A_ans_dfs(j->u,j->v);
						plu=j->fb->s;now=(j->s)>>1;
						_A_ans_dfs(j->v,j->u);
					}
				}
			}
			printf("%lld\n",ans);		
		}else if(_is_line()>-1){
			
		}else if(false){
			
		}else
			printf("I AK IOI!");
		for(int i=1;i<=n;++i)
			_free_edge(edge[i]);
	}
	return 0;
}
