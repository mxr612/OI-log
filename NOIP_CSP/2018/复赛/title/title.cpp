#include <stdio.h>

int ans=0;
char cmd;

int main(int argc, char const *argv[])
{
	// freopen("title.in","r",stdin);
	while(scanf("%c",&cmd)!=EOF){
		if(cmd!=' '&cmd!='\n'){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}