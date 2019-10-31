#include <iostream>
#include <cmath>

using namespace std;

int n,k;
int num[30];
int ans=0;

bool ck(int key){
	if(key<=1)
		return false;
	for(int i=2;i<=sqrt(key);i++)
		if(key%i==0)
			return false;
	return true;
}

void dfs(int deep,int pt,int sum){
	if(deep>k){
		if(ck(sum))
			ans++;
		return ;
	}
	for(int i=pt+1;i<=n;i++){
		dfs(deep+1,i,sum+num[i]);
	}
}

int main(){
	freopen("P1036.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}