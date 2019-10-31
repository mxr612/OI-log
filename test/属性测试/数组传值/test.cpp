#include <stdio.h>

void fac(int a[]){
	a[1]=1;
}

int main(int argc, char const *argv[])
{
	int k[10]={0};
	fac(k);
	printf("%d\n", k[1]);
	return 0;
}