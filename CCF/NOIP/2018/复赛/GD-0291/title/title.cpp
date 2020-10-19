#include<stdio.h>

int ans=0;
char cmd;

int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(scanf("%c",&cmd)!=EOF){
		if(cmd!=' '&&cmd!='\n'){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
