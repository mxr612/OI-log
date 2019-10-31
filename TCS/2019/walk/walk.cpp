//walk

#include <cstdio>
#include <iostream>
using namespace std;

int N;

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>N;
	cout<<N*(1+N)/2;
	return 0;
} 
