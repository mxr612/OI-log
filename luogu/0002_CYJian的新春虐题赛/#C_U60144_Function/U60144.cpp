//U60144

#include <iostream>

using namespace std;

#define MOD 998244353

#define min(m,n) m<n?m:n

long long N;
int K;
int mem[2][10000]={0};
int ans=0;

int main() {
// InPut
	freopen("U60144.in","r",stdin);
	cin>>N>>K;
	mem[1][1]=1;
//Push
	for(long long i=2;i<=N;i++){
		for(int j=1;j<=(min(i,K));j++){
			mem[i%2][j]=(mem[(i+1)%2][j]+mem[i%2][j-1]+mem[(i+1)%2][j-1])%MOD;
		}
	}
	for(int i=1;i<=K;i++){
		ans+=mem[N%2][i];
		ans%=MOD;
	}
// OutPut
	cout<<ans;
	return 0;
}