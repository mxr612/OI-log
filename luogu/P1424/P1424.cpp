#include <iostream>
#include <cstdio>

using namespace std;

int x,n;
int day=0;

int main(){
	freopen("P1424.in","r",stdin);
	cin>>x>>n;
	for(int i=x;i<x+n;i++)
		if(i%7!=6&&i%7!=0)
			day++;
	cout<<day*250;
	return 0;
}