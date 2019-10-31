#include<stdio.h>

#define pt(k) f[q[k]]

char q[30],z[30];
int len=1,p=1;
int f[150]={0};

void dfs(int l,int r){
	if(l>r)
		return ;
	int cmd=p++;
	dfs(l,pt(p)-1);
	dfs(pt(p)+1,r);
	printf("%c",q[cmd]);
}

int main(){
	freopen("1034.in","r",stdin);
	scanf("%s",q+1);
	scanf("%s",z+1);
	while(q[len]!='\0')f[z[len]]=len++; len--;
	for(int i=1;i<=)
	dfs(1,len);
	return 0;
}
