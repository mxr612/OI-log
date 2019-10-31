// T1336.cpp

#include <iostream>
#include <algorithm>
using namespace std;

int N,ans=0;

struct node{
	int A,B;
}sn[110000];

int _cmpS(node m,node n){
	if(m.A==n.A)
		return m.B>n.B;
	return m.A<n.A;
}

int DP[110000]={0};

int main(){

	freopen("T1336.in","r",stdin);
	freopen("T1336.out","w",stdout);

	cin>>N;

	for(int i=1;i<=N;++i)
		cin>>sn[i].A>>sn[i].B;

	sort(&sn[1],&sn[N+1],_cmpS);
	
	for(int i=1;i<=N;++i){
		DP[i]=1;
		for(int j=1;j<i;j++){
			if(sn[i].A!=sn[j].A&&sn[i].B!=sn[j].B){
				DP[i]=max(DP[i],DP[j]+1);
			}
		}
		ans=max(ans,DP[i]);
	}

	cout<<ans;

	return 0;
}