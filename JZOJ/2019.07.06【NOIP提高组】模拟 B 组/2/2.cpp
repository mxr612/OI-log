//2

#include <iostream>
#include <algorithm>
using namespace std;

int N,M;

struct edge{int fr,to,vl;}E[2000000];
int cmpS(edge m,edge n){return (m.fr==n.fr)?(m.to<n.to):(m.fr<n.fr);}

struct node{int l,r,flag,vl;}V[1000001];

int dfs(int dad,int dv,int id){//他老爸是谁(李刚) / 他到他老爸多远 / 他是谁
	if(V[id].flag==1)//要删就删,不多话
		return dv;
	int s=0;//儿子的和SUM(没儿子返回0)
	for(int i=V[id].l;i<=V[id].r;++i){
		if(E[i].to!=dad){//你爸爸还是你爸爸,只能找自己儿子
			s+=dfs(id,E[i].vl,E[i].to);
		}
	}
	return min(dv,s);
}

int main(){
	
	freopen("2.in","r",stdin);
// 输入数据
	cin>>N>>M;
	for(int i=1;i<N;++i)//无向图存成两个有向边
		cin>>E[i].fr>>E[i].to>>E[i].vl,E[N-1+i]={E[i].to,E[i].fr,E[i].vl};
	for(int i=1,a;i<=M;++i)
		cin>>a,V[a].flag=1;//标记要删
// 初始化图
	for(int i=1;i<=N;++i)
		V[i]={0,-1,V[i].flag,0};
	sort(&E[1],&E[2*N-1],cmpS);
	for(int i=1;i<=2*N-1;++i){
		if(E[i].fr!=E[i-1].fr){
			V[E[i].fr].l=i;
			V[E[i-1].fr].r=i-1;
		}
	}
// 深搜/输出
	cout<<dfs(0,1e9,1);//可怜的根节点没爸爸所以他离他爸很远(要不你当他爸做根节点//别打我)
	
	return 0;
	
}
