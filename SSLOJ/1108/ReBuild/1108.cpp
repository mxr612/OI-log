#include <stdio.h>

int n,m,ans=0;
char MapOfIP[52][52]={0};

void fill(int x,int y){
	MapOfIP[x][y]='*';
	if((x+1)<=(n+1)&&MapOfIP[x+1][y]!='*'){
		fill(x+1,y);
	}
	if((x-1)>=0&&MapOfIP[x-1][y]!='*'){
		fill(x-1,y);
	}
	if((y+1)<=(m+1)&&MapOfIP[x][y+1]!='*'){
		fill(x,y+1);
	}
	if((y-1)>=0&&MapOfIP[x][y-1]!='*'){
		fill(x,y-1);
	}
}
int main(int argc, char const *argv[])
{
	// freopen("1108.in","r",stdin);
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			MapOfIP[i][j]=getchar();
		}
		getchar();
	}
	fill(0,0);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(MapOfIP[i][j]);
		}
		putchar('\n');
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(MapOfIP[i][j]=='0'){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
