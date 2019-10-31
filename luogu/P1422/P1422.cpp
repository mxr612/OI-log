#include <stdio.h>

int IP;

int main(int argc, char const *argv[])
{
	scanf("%d",&IP);
	if(IP<=150){
		printf("%.1f",1.0*IP*0.4463);
	}
	if(IP>150&&IP<=400){
		printf("%.1f",150*0.4463+(IP-150)*0.4663);
	}
	if(IP>400){
		printf("%.1f",150*0.4463+250*0.4663+(IP-400)*0.5663);
	}
	return 0;
}
