// 1

#include <iostream>
#include <string>
#include <map>
using namespace std;

int T,c;
string str;

long long jc(int n){
	long long ans=1;
	for(int i=2;i<=n;++i)
		ans*=i;
	return ans;
}

int main(){

	freopen("1.in","r",stdin);

	cin>>T;

	for(int t=1;t<=T;++t){
		cin>>c>>str;
		long long need=jc(c),now=need;
		map<string,bool>T;
		for(int i=0;i<=(int)str.size()-need;++i){
			if(!T[str.substr(i,need)]){
				T[str.substr(i,need)]=true;
				now--;
			}
		}
		if(now==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
