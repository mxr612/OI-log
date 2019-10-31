#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_INT 1000000

long long a={0},cmp;
long long b,w=0,cm,p=1,jw=0,head=MAX_INT,end=0;
int ans[MAX_INT]={0};

int po(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i++){
		ans*=a;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	// freopen("1101.in","r",stdin);
	ans[1]=1;
	cmp=getchar();
	while(cmp>='0'&&cmp<='9'){
		a=a*10+cmp-'0';
		cmp=getchar();
	}
	cmp=getchar();
	while(cmp>='0'&&cmp<='9'){
		a=a*10+cmp-'0';
		w++;
		cmp=getchar();
	}
	cin>>b;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=MAX_INT;j++){
			ans[j]=ans[j]*a+jw;
			jw=ans[j]/10;
			ans[j]%=10;
		}
	}
	while(ans[head]==0)head--;
	while(ans[end]==0)end++;
	for(int i=head;i>w*b;i--){
		cout<<ans[i];
	}
	putchar('.');
	for(int i=w*b;i>=end;i--){
		cout<<ans[i];
	}
	return 0;
}
