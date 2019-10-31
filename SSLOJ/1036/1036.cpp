#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int n,q;
int books[2000]={0};
int len,num;

int main(){
	freopen("1036.in","r",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>books[i];
	sort(&books[1],&books[n]+1);
//	for(int i=1;i<=n;i++)
//		cout<<books[i]<<endl;
	for(int i=1;i<=q;i++){
		cin>>len>>num;
		for(int i=1;i<=n;i++){
			if(books[i]%int(pow(10,len))==num){
				cout<<books[i]<<endl;
				break;
			}
			if(i==n){
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}
