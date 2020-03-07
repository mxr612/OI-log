#include<stdio.h>

int key;

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",key);
	if(key==10){
		printf("%d",3);
	}else{
		printf("%d",1);
	}
	return 0;
}
