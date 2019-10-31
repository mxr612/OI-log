#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define lg(k) ((k==0)?-1:int(log10(k)))

int n,x;
long long ans=0;

int num[20000000];
int POW[10];
int j;

int main(){
	freopen("testdata.in","r",stdin);
	cin>>n>>x;
	POW[0]=1;for(int i=1;i<10;i++)POW[i]=POW[i-1]*10;//pre_POW
	for(int i=1;i<=n;i++){
		j=i%POW[lg(i)];
		num[i]=num[j];
		if(x==0)num[i]+=lg(i)-lg(j)-1;
		else if((i-j)/POW[lg(i)]==x)num[i]++;
		ans+=num[i];
		// if(i<=1000)printf("%-5d%-5d%d\n",i,j,num[i]);
	}
	cout<<ans;
	return 0;
}