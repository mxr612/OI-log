#include <iostream>
#include <string>

using namespace std;

string num;
int l=0,pt;

int main(){
	freopen("P1307.in","r",stdin);
	cin>>num;
	pt=num.length()-1;
	if(num[l]=='-')
		cout<<num[l++];
	while(pt>=l&&num[pt]=='0')pt--;
	if(pt<l){
		cout<<'0';
	}else{
		while(pt>=l)cout<<num[pt--];
	}
	return 0;
}