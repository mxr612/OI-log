// T1335.cpp

#include <iostream>
using namespace std;

int N,M,gcd;

int _gcd(int a,int b){
	return b==0?a:_gcd(b,a%b);
}

int main(){

	freopen("T1335.in","r",stdin);
	freopen("T1335.out","w",stdout);

	cin>>N>>M;
	gcd=_gcd(N,M);
	N/=gcd;
	M/=gcd;
	cout<<(N+M-1) *gcd;

	return 0;
}