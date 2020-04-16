// chess

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m,n;
int ans=1e9;

short map[110][110]={0};

const short way[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

int mode(){
	
}

bool vis[110][110]={false};
void dfs(short x,short y,short color,int cost){
	short _x,_y;
	if(x==m&&y==m){

	}
	for(int i=0;i<4;++i){
		_x=x+way[i][0];_y=y+way[i][1];
		if(!vis[_x][_y]){//此处待判定+剪枝
			vis[_x][_y]=true;
			switch(){

			}
			vis[_x][_y]=false;
		}
	}
}

int main(){

	freopen("chess.in","r",stdin);
	// freopen("chess.out","w",stdout);

// InPut
	cin>>m>>n;
	for(int i=1,x,y,c;i<=n;++i){
		cin>>x>>y>>c;
		map[x][y]=c+1;
	}
	

// OutPut

	return 0;
}