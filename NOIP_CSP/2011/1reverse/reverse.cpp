#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_LEN 20

int num[MAX_LEN+1]={0},len=0;
char str[MAX_LEN+1];

int main(int argc, char const *argv[])
{
	freopen("reverse.in","r",stdin);
	cin>>str;
	if(str[0]=='-'){
		len++;
	}
	while(str[len]!='\0'){
		num[len]=str[len]-'0';
		len++;
	}
	while(num[len]==0)len--;
	if(str[0]=='-'){
		putchar('-');
	}
	while(len>0){
		cout<<num[len];
		len--;
	}
	if(str[0]!='-'){
		cout<<num[0];
	}
	return 0;
}