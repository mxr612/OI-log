// 0
// 逆序对

#define mian main
#define Endl endl

#include <iostream>
#include <map>
#include <string>
using namespace std;

int N;
string cmp;
map<string,int>maps;
long long tree[110000]={0};
long long ans=0;

#define lowbit(n__) (n__&(-n__))
void add(int n){
	for(;n>0;n-=lowbit(n))
		tree[n]++;
}
int ask(int n){
	int ret=0;
	for(;n<=N;n+=lowbit(n))
		ret+=tree[n];
	return ret;
}

int main(){

	freopen("0_21.in","r",stdin);

	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>cmp,maps[cmp]=i;
	for(int i=1;i<=N;++i){
		cin>>cmp;
		ans+=ask(maps[cmp]+1);
		add(maps[cmp]);
	}

	cout<<ans;

	return 0;
}