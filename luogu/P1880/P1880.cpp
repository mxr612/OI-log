#include <iostream>
#include <cstdio>
using namespace std;

int N,goal,ans=0;
int Num[20]={0},dfs[20][20]={0};

void scan(int p){
	if(p==1){
		if(dfs[1][1]==goal){
			ans++;
		}
		return;
	}
	for(int i=1;i<p;i++){
		for(int j=1;j<i;j++){
			dfs[p-1][j]=dfs[p][j];
		}
		dfs[p-1][i]=dfs[i]-dfs[i+1];
		for(int j=i+1;j<=p;j++){
			dfs[p-1][j]=dfs[p][j+1];
		}
		scan(p-1);
	}
	cout<<p;
}

int main(int argc, char const *argv[])
{
	freopen("1100.in","r",stdin);
	cin>>N>>goal;
	for(int i=1;i<=N;i++){
		cin>>dfs[N][i];
	}
	scan(N);
	cout<<ans;
	return 0;
}
