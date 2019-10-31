// T1338.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MOD 9901

const int way[8][2]{
	{+1,+2},
	{+1,-2},
	{-1,+2},
	{-1,-2},
	{+2,+1},
	{+2,-1},
	{-2,+1},
	{-2,-1}
};

int N,M,V[110][110]={0},cnt,xx,yy;

struct node{
	int dep,x,y;
}cmp;
struct _cmpQ{
	bool operator()(node m,node n){
		return m.dep>n.dep;
	}
};
priority_queue<node,vector<node>,_cmpQ>que;
#define TOP (que.top())

int main(){

	freopen("T1338.in","r",stdin);
	freopen("T1338.out","w",stdout);

	cin>>N>>M;

	que.push({0,1,1});

	while(!que.empty()){
		V[TOP.x][TOP.y]=TOP.dep;
		cmp.dep=TOP.dep+1;
		xx=TOP.x;yy=TOP.y;
		que.pop();
		for(int i=0;i<8;++i){
			cmp.x=xx+way[i][0];
			cmp.y=yy+way[i][1];
			if(0<cmp.x&&cmp.x<=N&&0<cmp.y&&cmp.y<=M){
				que.push(cmp);
			}
		}
		while(!que.empty()&&V[TOP.x][TOP.y]>0){
			if(TOP.x==N&&TOP.y==M&&TOP.dep==V[TOP.x][TOP.y]){
				cnt=(cnt+1)%MOD;
			}
			que.pop();
		}
	}

	if(V[N][M]>0){
		cnt=(cnt+1)%MOD;
	}

	cout<<cnt;

	return 0;
}