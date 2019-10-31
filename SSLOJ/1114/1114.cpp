#include <stdio.h>

struct User
{
	int ID;
	int Period;
}users[3001];

int c,PtoHead=0,K;
int time=1,i=1;

int main(int argc, char const *argv[])
{
	freopen("1114.in","r",stdin);
	c=getchar();
	while(c!='#'){
		PtoHead++;
		scanf("egister");
		scanf("%d %d",&users[PtoHead].ID,&users[PtoHead].Period);
		c=getchar();
	}
	scanf("%d",&K);
	for(int t=1;i<=K;t++){
		for(int j=1;j<=PtoHead;j++){
			if(users[j]%i==0){
				pritnf("%d",users[j].ID);
				i++;
			}
		}
	}
	return 0;
}
