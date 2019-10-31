#include <stdio.h>

#define MAXLEN 500

int MaxNum[MAXLEN+1]={0},ans;
int Man[30][MAXLEN+1],n;

int main(int argc, char const *argv[])
{
	freopen("testdata.in","r",stdin);
	freopen("president.out","w",stdout);
	scanf("%d\n",&n);
	char cmp;
	for(int i=1,w;i<=n;i++){
		cmp=getchar();
		w=0;
		while(cmp!='\n'){
			Man[i][++w]=cmp-'0';
			cmp=getchar();
		}
		Man[i][0]=w;
	}
	ans=1;
	MaxNum[0]=Man[1][0];
	for(int j=1;j<=MAXLEN;j++){
		MaxNum[j]=Man[1][j];
	}
	for(int i=1,ck=0;i<=n;i++){
		if(Man[i][0]<MaxNum[0]){
			continue;
		}else if(Man[i][0]>MaxNum[0]){
			ck=1;
		}else{
			for(int j=1;j<=MAXLEN;j++){
				if(Man[i][j]<MaxNum[j]){
					break;
				}
				if(Man[i][j]>MaxNum[j]){
					ck=1;
					break;
				}
			}
		}
		if(ck==1){
			ans=i;
			MaxNum[0]=Man[i][0];
			for(int j=1;j<=MAXLEN;j++){
				MaxNum[j]=Man[i][j];
			}
			ck=0;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=MaxNum[0];i++){
		printf("%d",MaxNum[i]);
	}
	return 0;
}