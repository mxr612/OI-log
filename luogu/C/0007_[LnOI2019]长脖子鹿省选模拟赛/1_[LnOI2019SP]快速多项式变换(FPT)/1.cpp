// 1

#include <iostream>
using namespace std;

long long m,f;
int top=1;
long long mi[120];
long long a[120]={0};

int main(){
	freopen("1.in","r",stdin);
	cin>>m>>f;
	mi[0]=1;
	for(;top<=100&&mi[top-1]<=f;top++)
		mi[top]=mi[top-1]*m;
	top--;
	for(int i=top-1;i>=0;i--){
		a[i]=f/mi[i];
		f-=a[i]*mi[i];
	}
	cout<<top<<endl;
	for(int i=0;i<top;i++)
		cout<<a[i]<<' ';
	return 0;
}