// B

#include <iostream>
using namespace std;

long long mem[2000][2000]={0};

const int MOD=19260817;

int q,n,m;
int ans;

int main(){
	mem[1][1]=1;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=i;j++){
			mem[i+1][j]=mem[i][j]*(i+1)/(i-j+1);
			mem[i][j+1]=mem[i][j]*(i-j)/(j+1);
		}
	}
	freopen("B.in","r",stdin);
	cin>>q;
	for(int K=0;K<q;K++){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=mem[j][i];
				ans%=MOD;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}