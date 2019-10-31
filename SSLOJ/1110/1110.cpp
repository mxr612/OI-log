#include <stdio.h>

int N;
int MapOfIP[9][9]={0};
int x,y;

int main(int argc, char const *argv[])
{
	freopen("1110.in","r",stdin);
	scanf("%d",&N);
	scanf("%d %d",&x,&y);
	scanf("%d",&MapOfIP[x][y]);
	while(!(x==0&&y==0&&MapOfIP[x][y]==0)){
		scanf("%d %d",&x,&y);
		scanf("%d",&MapOfIP[x][y]);
	}
	
	return 0;
}
