#include <iostream>

using namespace std;

int L,M;
int tr[100000]={0};
int l,r;
int ans;

int main(){
	freopen("P1047.in","r",stdin);
	cin>>L>>M;
	ans=L+1;
	for(int i=1;i<=M;i++){
		cin>>l>>r;
		for(int j=l;j<=r;j++)
			tr[j]=1;
	}
	for(int i=0;i<=L;i++)
		ans-=tr[i];
	cout<<ans;
	return 0;
}