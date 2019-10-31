// T1338.cpp

#include <iostream>
#include <queue>
using namespace std;

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

int N,M,fas[110][110]={0},cnt[110][110]={0};

struct node{
	int dep,x,y;
}cmp;

queue<node>que;
#define TOP (que.front())

int main(){

	N=100;M=100;

	cmp.x=cmp.y=1;cmp.dep=0;
	que.push(cmp);

	while(!que.empty()){
		cmp.dep=TOP.dep+1;
		for(int i=0;i<8;++i){
			cmp.x=TOP.x+way[i][0];
			cmp.y=TOP.y+way[i][1];
			if((0<cmp.x)&&(cmp.x<=N)&&(0<cmp.y)&&(cmp.y<=M)){
				if(cnt[cmp.x][cmp.y]==0){
					fas[cmp.x][cmp.y]=cmp.dep;
				}
				if(cmp.dep==fas[cmp.x][cmp.y]){
					cnt[cmp.x][cmp.y]++;
					que.push(cmp);
				}
			}
		}
		que.pop();
	}
	cout<<cnt[N][M];

	return 0;
}