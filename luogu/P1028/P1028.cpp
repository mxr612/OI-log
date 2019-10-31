#include <iostream>

using namespace std;

int n;
int mem[10000]={0};

int main(){
	freopen("P1028.in","r",stdin);
	cin>>n;
	mem[1]=1;
	for(int i=2;i<=n;i++){
		mem[i]++;
		for(int j=1;j<=int(i/2);j++)
			mem[i]+=mem[j];
	}
	cout<<mem[n];
	return 0;
}