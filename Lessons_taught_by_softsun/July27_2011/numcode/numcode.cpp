#include<stdio.h> 

#define MAX 100

int n,k,ncont=0,kcont=0,num[101][MAX]={0},ck[101]={0};

void print(int ip) {
	bool ck=0;
	for(int i=MAX-1;i>-1;i--) {
		if(num[ip][i]!=0) {
			ck=1;
		}
		if(ck) {
			printf("%d",num[ip][i]);
		}
	}
}

void add(int a) {
	for(int i=0;i<MAX;i++) {
		num[a][i]+=num[a-2][i]+num[a-1][i];
		if(num[a][i]>=10) {
			num[a][i+1]+=num[a][i]/10;
			num[a][i]%=10;
		}
	}
}

int main() {
	freopen("numcode.in","r",stdin);
	freopen("numcode.out","w",stdout);
	scanf("%d %d",&n,&k);
	num[1][0]=num[2][0]=1;
	for(int i=3;i<=n;i++) {
		add(i);
	}
	for(int i=1;ncont<n;i++) {
		if(i>n) {
			i-=n;
		}
		if(ck[i]==0)  {
			kcont++;
		}else {
			continue;
		}
		if(kcont==k) {
			ncont++;
			kcont=0;
			ck[i]=1;
			print(i);
		}
		}
	return 0;
}
