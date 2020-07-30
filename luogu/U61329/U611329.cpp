//U611329

#include <iostream>

using namespace std;

#define MOD 104857601

int GCD(int a,int b){
	return b==0?a:GCD(b,a%b);
}

int N,cmp;
long long ans=1;

int main(){
	freopen("U611329.in","r",stdin);
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			cmp=GCD(i,j);
			cmp=(i*j/(cmp*cmp))%MOD;
			ans=(ans*cmp)%MOD;
		}
	}
	ans*=ans;ans%=MOD;
	cout<<ans;
	return 0;
}