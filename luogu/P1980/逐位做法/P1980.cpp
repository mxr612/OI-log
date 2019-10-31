#include <iostream>
#include <cmath>

using namespace std;

#define lg(k) int(log10(k))

int n,x;
int cmp;
int ans;

int main(int argc, char const *argv[])
{
	freopen("testdata.in","r",stdin);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cmp=i;
		while(cmp!=0){
			if(cmp%10==x)ans++;
			cmp/=10;
		}
	}
	cout<<ans;
	return 0;
}