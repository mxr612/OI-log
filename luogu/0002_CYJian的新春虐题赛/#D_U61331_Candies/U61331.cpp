// U61331

#include <iostream>

using namespace std;

#define MOD 1004535809

long long N,M,K;
long long ans=0;

int C(long long n,long long m){
	long long cmpa=1,cmpb=1;
	for(long long i=n;i>m;i--){
		cmpa*=i;
		cmpa%=MOD;
	}
	for(long long i=n-m;i>0;i--){
		cmpb*=i;
	}
	while(cmpa%cmpb>0)cmpa+=MOD;
	return cmpa/cmpb;
}

int main(){
	freopen("U61331.in","r",stdin);
	cin>>N>>M>>K;
	for(int i=M%K;i<=N-M;i++){
		if(i%K==M%K){
			ans+=C(N,i);
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}