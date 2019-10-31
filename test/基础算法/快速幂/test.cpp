#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a=2;
	int b=2018;
	int ans=1;
	int now=a;
	while(b!=0){
		if(b%2){
			ans*=now;
		}
		b>>=1;
		now*=now;
	}
	printf("%d\n", ans);
	return 0;
}