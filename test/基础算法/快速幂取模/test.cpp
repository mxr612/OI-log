#include <stdio.h>

int a,b,p;
int now,ans=1;

int main(int argc, char const *argv[])
{
	a=2;
	b=2018;
	p=7;
	now=a%p;
	while(b!=0){
		if(b%2)ans=ans*now%p;
		now=(now*now)%p;
		b>>=1;
	}
	printf("%d\n", ans);
	return 0;
}
