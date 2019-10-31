//P1042

#include <stdio.h>

#define MAX_END

char c;
int BF11[10000][2],head11=1;
int BF21[10000][2],head21=1;

unsigned int jd(signed int a){
	return a<0?-1*a:a;
}

int main(int argc, char const *argv[])
{
	// freopen("testdata.in","r",stdin);
	c=getchar();
	while(c!='E'){
		if(c=='W'){
			if((BF11[head11][0]>=11||BF11[head11][1]>=11)&&jd(BF11[head11][1]-BF11[head11][0])>=2){
				BF11[++head11][0]++;
			}else{
				BF11[head11][0]++;
			}
			if((BF21[head21][0]>=21||BF21[head21][1]>=21)&&jd(BF21[head21][1]-BF21[head21][0])>=2){
				BF21[++head21][0]++;
			}else{
				BF21[head21][0]++;
			}
		}
		if(c=='L'){
			if((BF11[head11][0]>=11||BF11[head11][1]>=11)&&jd(BF11[head11][1]-BF11[head11][0])>=2){
				BF11[++head11][1]++;
			}else{
				BF11[head11][1]++;
			}
			if((BF21[head21][0]>=21||BF21[head21][1]>=21)&&jd(BF21[head21][1]-BF21[head21][0])>=2){
				BF21[++head21][1]++;
			}else{
				BF21[head21][1]++;
			}
		}
		c=getchar();
	}
	for(int i=1;i<=head11;i++){
		printf("%d:%d\n",BF11[i][0],BF11[i][1]);
	}
	if((BF11[head11][0]>=11||BF11[head11][1]>=11)&&jd(BF11[head11][1]-BF11[head11][0])>=2){
		printf("0:0\n");
	}
	putchar('\n');
	for(int i=1;i<=head21;i++){
		printf("%d:%d\n",BF21[i][0],BF21[i][1]);
	}
	if((BF21[head21][0]>=21||BF21[head21][1]>=21)&&jd(BF21[head21][1]-BF21[head21][0])>=2){
		printf("0:0\n");
	}
	return 0;
}
