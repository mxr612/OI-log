#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[1000];
int ck[1000]={0};
int ans=0;

int main(){
	freopen("P2141.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(num[i]+num[j]==num[k]&&ck[k]==0){
					ck[k]=1;
					ans++;
				}
	cout<<ans;
	return 0;
}