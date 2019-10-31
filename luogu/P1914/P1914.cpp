#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main(){
	freopen("P1914.in","r",stdin);
	cin>>n>>str;
	for(int i=0;i<(int)str.length();i++)
		str[i]=(str[i]-'a'+n)%26+'a';
	cout<<str;
	return 0;
}