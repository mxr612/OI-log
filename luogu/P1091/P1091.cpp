#include <iostream>
#include <cstdio>

using namespace std;

int N;
int man[200];

int dp_up[200]={0},dp_down[200]={0};
int maxx=0;

int main(){
	freopen("testdata.in","r",stdin);
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>man[i];
	for(int i=0;i<N;i++)
		dp_up[i]=dp_down[i]=1;
	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			if(man[j]<man[i])
				dp_up[i]=max(dp_up[i],dp_up[j]+1);
	// for(int i=0;i<N;i++)
	// 	for(int j=0;j<i;j++)
	// 		if(man[j]>man[i])
	// 			dp_down[i]=max(dp_down[i],dp_down[j]+1);
	for(int i=N-1;i>=1;i--)
		for(int j=N-1;j>i;j--)
			if(man[j]<man[i])
				dp_down[i]=max(dp_down[i],dp_down[j]+1);
	for(int i=0;i<N;i++)
		printf("%3d", dp_up[i]);
	cout<<endl;
	for(int i=0;i<N;i++)
		printf("%3d",dp_down[i]);
	cout<<endl;
	for(int i=0;i<N;i++)
		maxx=max(maxx,dp_up[i]+dp_down[i]-1);
	cout<<N-maxx;
	return 0;
}