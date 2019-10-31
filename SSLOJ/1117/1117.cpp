#include <stdio.h>

const int way4[4][2]={{-1,0},{0,1},{1,0},{-1,0}};

int N,M;
int Ch[2][600][600]={0};
int NumOfCh[300000],maxway;
int C,X,Y;
int ans=0;

void fill(int,int);
void print();

int main(int argc, char const *argv[])
{
	freopen("1117.in","r",stdin);
	freopen("1117.out","w",stdout);
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i++){
		scanf("%d %d %d",&C,&X,&Y);
		Ch[C][X][Y]=i;
		maxway=0;
		print();
		for(int j=0;j<4;j++){
			if(NumOfCh[Ch[C][X+way4[maxway][0]][Y+way4[maxway][1]]]<NumOfCh[Ch[C][X+way4[j][0]][Y+way4[j][1]]]){
				maxway=j;
			}
		}
		if(NumOfCh[Ch[C][X+way4[maxway][0]][Y+way4[maxway][1]]]==0){
			Ch[C][X][Y]=i;
			NumOfCh[i]=1;
		}else{
			Ch[C][X][Y]=Ch[C][X+way4[maxway][0]][Y+way4[maxway][1]];
		}
		for(int i=maxway+1;i<maxway+4;i++){
			fill(X+way4[i][0],Y+way4[i][1]);
		}
	}
	return 0;
}

void fill(int x,int y){
	if(Ch[C][x][y]==0||Ch[C][x][y]==Ch[C][X][Y]||x<0||x>N||y<0||y>N){
		return ;
	}else{
		Ch[C][x][y]=Ch[C][X][Y];
		for(int i=0;i<4;i++){
			fill(x+way4[i][0],y+way4[i][1]);
		}
	}
}

void print(){
	bool mark[300000]={0};
	ans++;
	if(mark[Ch[C][X+1][Y]]==0&&Ch[C][X+1][Y]!=0){
		mark[Ch[C][X+1][Y]]=1;
		ans--;
	}
	if(mark[Ch[C][X-1][Y]]==0&&Ch[C][X-1][Y]!=0){
		mark[Ch[C][X-1][Y]]=1;
		ans--;
	}
	if(mark[Ch[C][X][Y+1]]==0&&Ch[C][X][Y+1]!=0){
		mark[Ch[C][X][Y+1]]=1;
		ans--;
	}
	if(mark[Ch[C][X][Y-1]]==0&&Ch[C][X][Y-1]!=0){
		mark[Ch[C][X][Y-1]]=1;
		ans--;
	}
	printf("%d\n", ans);
}
