#include <iostream>

using namespace std;

double A,B,C;

int sign[10]={0};
int ans=0;

void make(int num,int dep){
	if(dep==10){
		double a,b,c;
		a=num%1000;num/=1000;
		b=num%1000;num/=1000;
		c=num;
		if(A*b==B*a&&B*c==C*b){
			ans=1;
			cout<<a<<' '<<b<<' '<<c<<endl;
		}
	}
	for(int i=1;i<=9;i++)
		if(sign[i]==0){
			sign[i]=1;
			make(num*10+i,dep+1);
			sign[i]=0;
		}
}

int main(){
	freopen("testdata.in","r",stdin);
	cin>>A>>B>>C;
	make(0,1);
	if(ans==0)
		cout<<"No!!!";
	return 0;
}