#include <iostream>

using namespace std;

string ISBN;
int ans=0;

int main() {
	freopen("P1055.in", "r", stdin);
	cin>>ISBN;
	ans+=(ISBN[0]-'0');
	ans+=(ISBN[2]-'0')*2;
	ans+=(ISBN[3]-'0')*3;
	ans+=(ISBN[4]-'0')*4;
	ans+=(ISBN[6]-'0')*5;
	ans+=(ISBN[7]-'0')*6;
	ans+=(ISBN[8]-'0')*7;
	ans+=(ISBN[9]-'0')*8;
	ans+=(ISBN[10]-'0')*9;
	ans=(ans%11)==10?'X':(ans%11)+'0';
	if(ans==(ISBN[12]))
		cout<<"Right";
	else{
		ISBN[12]=ans;
		cout<<ISBN;
	}
	return 0;
}