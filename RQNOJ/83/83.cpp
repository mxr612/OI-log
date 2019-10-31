#include <stdio.h>
#include <string.h>

const int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
char MAP[101][101]={0};
int map[101][101]={0};
int AZ[129][2][2]={0},azcmp;
int que[30000][2],in=1,out=0;

int main(int argc, char const *argv[])
{
	// freopen("83.in","r",stdin);
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			MAP[i][j]=getchar();
			map[i][j]=-1;
			if(MAP[i][j]>='A'&&MAP[i][j]<='Z'){
				azcmp=MAP[i][j];
				if(AZ[azcmp][0][0]==0){
					AZ[azcmp][0][0]=i;
					AZ[azcmp][0][1]=j;
				}else{
					AZ[azcmp][1][0]=i;
					AZ[azcmp][1][1]=j;
				}
			}
		}
		getchar();
	}
	que[0][0]=que[0][1]=1;
	map[1][1]=0;
	while(out<in&&map[n][m]==-1){
		for(int i=0;i<4;i++){
			int x=que[out][0]+way[i][0],y=que[out][1]+way[i][1];
			
			if(map[x][y]==-1&&MAP[x][y]>='A'&&MAP[x][y]<='Z'){
				if(map[x][y]==-1){
					map[x][y]=map[que[out][0]][que[out][1]]+1;
					que[in][0]=x;
					que[in][1]=y;
					in++;
				}
				map[x][y]=map[que[out][0]][que[out][1]]+1;
				azcmp=x;
				if(AZ[(int )MAP[x][y]][0][0]==x){
					x=AZ[(int )MAP[x][y]][1][0];
					y=AZ[(int )MAP[azcmp][y]][1][1];
				}else{
					x=AZ[(int )MAP[x][y]][0][0];
					y=AZ[(int )MAP[azcmp][y]][0][1];
				}
			}
			if(MAP[x][y]!='1'&&map[x][y]==-1){
				map[x][y]=map[que[out][0]][que[out][1]]+1;
				que[in][0]=x;
				que[in][1]=y;
				in++;
			}
		}
		out++;
	}
	if(in==out){
		printf("No Solution.\n");
	}else{
		printf("%d\n",map[n][m]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%3d",map[i][j]);
		}
		putchar('\n');
	}
	return 0;
}