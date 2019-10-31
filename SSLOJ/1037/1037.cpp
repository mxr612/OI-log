#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct node{
	int x,y;
};

queue<node> que;

const int way[4][2]={{1,0},{-1,0},{0,1},{0,1}};

int m,n;
int map[200][200];
struct node cmp; 
int xx,yy;

bool bj(int x,int y){
	if(x<1)return false;
	if(x>m)return false;
	if(y<1)return false;
	if(y>m)return false;
	return true;
}

bool mf(int x,int y){
	if(map[que.front().x][que.front().y]!=-1)
		return true;
	if(map[x][y]==-1)
		return false;
	return true;
}

int main(){
	freopen("1037.in","r",stdin);
	memset(map,-1,sizeof(map));
	cmp.x=cmp.y=1;
	que.push(cmp);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
	}
	while(!que.empty()){
		for(int i=0;i<=4;i++){
			xx=que.front().x+way[i][0];
			yy=que.front().y+way[i][1];
			if(bj(xx,yy)&&mf(xx,yy)){
				cmp.x=xx;
				cmp.y=yy;
				que.push(cmp);
			}
		}
		que.pop();
	}
	return 0;
}
