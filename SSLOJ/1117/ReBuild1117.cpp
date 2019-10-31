#include <stdio.h>

const short way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int MAP[2][600][600]={0};
int N,M,ans=0;
int Num[300000]={0};
int C,X,Y;

void print();
int FindMax(int);
void Fill(int ,int ); 

int main(int argc, char const *argv[])
{
	freopen("1117.in","r",stdin);
	freopen("1117.out","w",stdout);
	printf("%d %d\n", &N,&M);
	for(int t=1;t<=M;t++){
		scanf("%d %d %d",&C,&X,&Y);
		print();
		MAP[C][X][Y]=FindMax(t);
		Fill(X,Y);
	}
	return 0;
}

void print(){
	bool mark[300000]={0};
	ans++;
	if(mark[MAP[C][X+1][Y]]==0&&MAP[C][X+1][Y]!=0){
		ans--;
	}
	if(mark[MAP[C][X-1][Y]]==0&&MAP[C][X-1][Y]!=0){
		ans--;
	}
	if(mark[MAP[C][X][Y+1]]==0&&MAP[C][X][Y+1]!=0){
		ans--;
	}
	if(mark[MAP[C][X][Y-1]]==0&&MAP[C][X][Y-1]!=0){
		ans--;
	}
	printf("%d\n", ans);
}

int FindMax(int Maxv){
	if(MAP[C][X+1][Y]!=0&&Num[MAP[C][X+1][Y]]>Num[Maxv]){
		Maxv=MAP[C][X+1][Y];
	}
	if(MAP[C][X-1][Y]!=0&&Num[MAP[C][X-1][Y]]>Num[Maxv]){
		Maxv=MAP[C][X-1][Y];
	}
	if(MAP[C][X][Y+1]!=0&&Num[MAP[C][X][Y+1]]>Num[Maxv]){
		Maxv=MAP[C][X][Y+1];
	}
	if(MAP[C][X][Y-1]!=0&&Num[MAP[C][X][Y-1]]>Num[Maxv]){
		Maxv=MAP[C][X][Y-1];
	}
	return Maxv;
}

void Fill(int i,int j){
	if(i>N||i<=0||j>N||j<=0||MAP[C][i][j]==0||MAP[C][i][j]==MAP[C][X][Y]){
		return;
	}
	Fill(i+1,j);
	Fill(i-1,j);
	Fill(i,j+1);
	Fill(i,j-1);
}
