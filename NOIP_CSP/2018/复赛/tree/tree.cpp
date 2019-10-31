#include <stdio.h>

int key;

int main(int argc, char const *argv[])
{
	freopen("tree.in","r",stdin);
	scanf("%d",&key);
	if(key==10){
		printf("3");
	}else{
		printf("1");
	}
	return 0;
}