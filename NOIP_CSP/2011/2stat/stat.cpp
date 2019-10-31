#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_LEN 10

int lo=-1,co=0,i=0;
char key[MAX_LEN + 1] = {0};
char cmp[MAX_LEN + 1] = {0};

void ti(char in[]);//大小写

int main(int argc, char const *argv[])
{
	freopen("stat.in", "r", stdin);
	scanf("%s", key);
	ti(key);
	while (scanf("%s", cmp) != EOF) {
		ti(cmp);
		if(strcmp(key,cmp)==0){
			co++;
			lo=lo==-1?i:lo;
		}
		i++;
	}
	if(lo==-1){
		printf("-1");
	}else{
		printf("%d %d",co,lo);
	}
	return 0;
}

void ti(char in[]){
	int i=0;
	while(in[i]!='\0'){
		if(in[i]>='A'&&in[i]<='Z'){
			in[i]+='a'-'A';
		}
		i++;
	}
}