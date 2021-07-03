// landscape.in

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n,cmp;
priority_queue<int>pq;

int main(){
	freopen("landscape.in","r",stdin);
	freopen("landscape.out","w",stdout);


	cin>>n;

	for(int i=0;i<n;++i)
		cin>>cmp,pq.push(cmp);

	for(int i=0;i<n;++i)
		cout<<pq.top()<<endl,pq.pop();

	return 0;
}