#include <iostream>
#include <cstdio>

using namespace std;

#define LL long long

long long mem[30][30][30];
int sign[30][30][30]={0};

LL a,b,c;

LL w(LL a,LL b,LL c){
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return w(20,20,20);
	if(sign[a][b][c]==1)
		return mem[a][b][c];
	if(a<b&&b<c){
		mem[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		sign[a][b][c]=1;
		return mem[a][b][c];
	}
	mem[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	sign[a][b][c]=1;
	return mem[a][b][c];
}

int main(){
	freopen("P1464.in","r",stdin);
	cin>>a>>b>>c;
	while(a!=-1||b!=-1||c!=-1){
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
		cin>>a>>b>>c;
	}
	return 0;
}