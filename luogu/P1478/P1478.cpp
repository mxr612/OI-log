#include <iostream>
#include <algorithm>

using namespace std;

int n,s;
int a,b;
int apple[6000],pt=0;
int ans=0;

int main(){
	freopen("P1478.in","r",stdin);
	cin>>n>>s;
	cin>>a>>b;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		if(x<=a+b)
			apple[pt++]=y;
	}
	sort(apple,apple+pt);
	for(int i=1;i<pt&&s>=0;i++){
		ans++;
		s-=apple[i];
	}
	cout<<ans;
	return 0;
}