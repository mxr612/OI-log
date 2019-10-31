// 1115.cpp

#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int Chinese,English,Math,Information;
	int sort_MA,sort_IN;
}students[50];

int num;

int QcmpOfMA(const void *a,const void *b){
	return (*(Student *)b).Math-(*(Student *)a).Math;
}

int QcmpOfIN(const void *a,const void *b){
	return (*(Student *)b).Information-(*(Student *)a).Information;
}

int main(int argc, char const *argv[])
{
	freopen("1115.in","r",stdin);
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		scanf("%d %d %d %d",&students[i].Chinese,&students[i].Math,&students[i].English,&students[i].Information);
	}
	qsort(&students[1],num,sizeof(students[0]),QcmpOfMA);
	for(int i=1;i<=num;i++){
		students[i].sort_MA=i;
	}
	qsort(&students[1],num,sizeof(students[0]),QcmpOfIN);
	for(int i=1;i<=num;i++){
		printf("%4d%5d%5d%5d%5d%5d \n",students[i].Chinese,students[i].Math,students[i].English,students[i].Information,i,students[i].sort_MA);
	}
	return 0;
}
