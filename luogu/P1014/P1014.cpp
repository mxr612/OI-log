#include <iostream>

using namespace std;

int N;
int i=0,sum=0;
int a,b;

int main(){
	freopen("P1014.in","r",stdin);
	cin>>N;
	do{
		i++;
		sum+=i;
	}while(sum<N);
	a=i+N-sum;
	b=i+1-a;
	if(i%2==0){
		cout<<a<<'/'<<b;
	}else{
		cout<<b<<'/'<<a;
	}
	return 0;
}