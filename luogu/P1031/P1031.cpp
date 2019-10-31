#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 100

int N,mid=0,ans=0;
int num[MAX_N+1]={0};

int main(int argc, char const *argv[])
{
	// freopen("P1031.in","r",stdin);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>num[i];
		mid+=num[i];
	}
	mid/=N;
	for(int i=1;i<=N;i++){
		num[i]-=mid;
	}
	for(int i=1;i<N;i++){
		int cmd=num[i+1];
		num[i+1]+=num[i];
		if(cmd!=num[i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}