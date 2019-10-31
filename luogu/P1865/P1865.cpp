#include <iostream>
#include <cstdio>
using namespace std;

int n,m,l,r,ans;
bool prime[1000000]={0};

int main(int argc, char const *argv[])
{
	freopen("P1865.in","r",stdin);
	cin>>n>>m;
	for(int i=2;i<=m;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=m;j+=i){
				prime[j]=1;
			}
		}
	}
	prime[1]=1;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		if(min(l,r)<1||max(l,r)>m){
			cout<<"Crossing the line"<<endl;
			continue;
		}
		ans=0;
		for(int j=l;j<=r;j++){
			if(prime[j]==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
