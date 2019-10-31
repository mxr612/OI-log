#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,x;
int a[10000000]={0};
int ans=0;

int main(){
	freopen("1038.in","r",stdin);
	cin>>n;
	for(int i=0,cmp;i<n;i++){
		cin>>cmp;
		if(cmp>=1)
			a[cmp]=1;
	}
	cin>>x;
	for(int i=1;i<=1000000;i++){
		if(a[i]==1&&a[x-i]==1&&x-i>i)
			ans++;
	}
		
	cout<<ans;
	return 0;
}
