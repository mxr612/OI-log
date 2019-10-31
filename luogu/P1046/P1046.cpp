#include <iostream>

using namespace std;

int apples[11];
int h,ans=0;

int main(){
	freopen("P1046.in","r",stdin);
	for(int i=1;i<=10;i++)
		cin>>apples[i];
	cin>>h;
	h+=30;
	for(int i=1;i<=10;i++)
		if(apples[i]<=h)
			ans++;
	cout<<ans;
	return 0;
}