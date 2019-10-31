#include<iostream>
using namespace std;

#define MAX 10000000000000000 

short n,num[MAX]={0};

void ad(int ip) {
	num[0]+=ip;
	for(int i=0;i<MAX;i++) {
		num[i+1]+=num[i]/10;
		num[i]%=10;
	}
}

void ch(int ip) {
	int g=0;
	for(int i=0;i<MAX;i++) {
		num[i]=num[i]*ip+g;
		g=num[i]/10;
		num[i]%=10;
	}
}

void print() {
	int fi=MAX;
	while(num[fi]==0)fi--;
	while(fi>-1)cout<<num[fi--];
}

int main() {
	freopen("in.in","r",stdin); 
	cin>>n;
	if(n==0) {
		ad(1);
	}else{
		ad(n);
		while(n>1) {
			ad(1);
			ch(--n);
		}
	}
	print();
	return 0;
}
