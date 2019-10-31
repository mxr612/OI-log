#include <iostream>
#include <cmath>

using namespace std;

int n;
int count,ans[]={0,0,0,0,0,0,0,0,0,0,1,10,55,210,615,1452,2850,4740,6765,8350,8953,8350,6765,4740,2850,1452,615,210,55,10,1};

int pw(int a,int b){
	if(b==0)
		return 1;
	int ans=a;
	for(int i=2;i<=b;i++)
		ans*=a;
	return ans;
}

void dfs(int dep,long long num,int sum){
	if(dep==11){
		if(sum==n){
			for(int i=1;i<=10;i++){
				cout<<num/pw(10,10-i)<<' ';
				num%=pw(10,10-i);
			}
			cout<<endl;
			// count++;
		}
		return ;
	}
	for(int i=1;i<=3;i++)
		dfs(dep+1,num*10+i,sum+i);
}

int main(){
	freopen("P2089.in","r",stdin);
	// freopen("P2089.out","w",stdout);
	cin>>n;
	// for(n=0;n<=30;n++){
	// 	count=0;
	// 	dfs(1,0,0);
	// 	cout<<count<<',';
	// }
	if(n<10||n>30){
		cout<<0;
	}else{
		cout<<ans[n]<<endl;
		dfs(1,0,0);
	}
	return 0;
}