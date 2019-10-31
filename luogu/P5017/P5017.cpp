#include <iostream>
#include <cstdio>

using namespace std;

int fun(int l,int r);

int m,n;
int sta[4000001]={0},top=-1;
int fin[4000001],sta_mini[600],pt=0;
int DP[4000001];

int main(){
	freopen("P5017.in","r",stdin);
//InPut
	cin>>n>>m;
	for(int i=1,cmp;i<=n;i++){
		cin>>cmp;
		sta[cmp]++;
		top=max(top,cmp);
	}
//Reset
	for(int i=1;i<=top;i++)
		if(sta[i]>0)
			sta_mini[pt++]=i;
	for(int i=0;i<=top;i++)
		DP[i]=fun(0,i);
//DP
	for(int i=0;i<=top;i++)
		for(int j=0;j<=i-m;j++)
			DP[i]=min(DP[i],DP[j]+fun(j+1,i));
//OutPut
	cout<<DP[top];
	return 0;
}

int fun(int l,int r){
	int ans=0;
	int l_mini=0,r_mini=0;
	for(int i=l_mini;i<=r_mini;i++)
		ans+=sta[sta_mini[i]]*(r-sta_mini[i]);
	return ans;
}