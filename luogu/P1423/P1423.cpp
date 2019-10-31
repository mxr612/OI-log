/**
 * P1423
 * 小玉在游泳
 */

#include <iostream>
using namespace std;

int n=0;
double G,B=2;
double now=0;

int main(int argc, char const *argv[])
{
	freopen("P1423.in","r",stdin);
	cin>>G;
	while(now<G){
		n++;
		now+=B;
		B*=0.98;
	}
	cout<<n;
	return 0;
}