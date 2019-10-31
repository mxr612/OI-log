#include <iostream>

using namespace std;

int n;
int fish[1000];
int ans;

int main(){
	freopen("P1428.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>fish[i];
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<i;j++)
			if(fish[j]<fish[i])
				ans++;
		cout<<ans<<' ';
	}
	return 0;
}