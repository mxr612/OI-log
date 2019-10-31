#include <iostream>

using namespace std;

double s,x;
double ti=0;
int count=0;

int main(){
	freopen("testdata.in","r",stdin);
	cin>>s>>x;
	// for(double i=7;S<110;i*=0.98){
	// 	cout<<S<<',';
	// 	S+=i;
	// }
	for(double i=7;ti<=s+x;i*=0.98){
		if(ti>=s-x)
			count++;
		ti+=i;
	}
	cout<<count<<endl;
	if(count>1)
		cout<<'y';
	else
		cout<<'n';
	return 0;
}