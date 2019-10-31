#include <bits/stdc++.h>
using namespace std;

int x,n,a;
int now[101]={0}, ans[101]={0};

void H_x_L(){
	int ys=0;
	for(int i=1;i<=100;i++){
		now[i]=now[i]*x+ys;
		ys=now[i]/10;
		now[i]%=10;
	}
}

void H_p_H(){
	int ys=0;
	for(int i=1;i<=100;i++){
		ans[i]+=now[i]+ys;
		ys=ans[i]/10;
		ans[i]%=10;
	}
}

void H_p_L(){
	int ys=0;
	ans[1]+=a;
	for(int i=1;i<=100;i++){
		ans[i]+=ys;
		ys=ans[i]/10;
		ans[i]%=10;
	}
}

int main(int argc, char const *argv[]){
	freopen("81.in","r",stdin);
	cin>>x>>n;
	now[1]=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		H_x_L();
		H_p_H();
		H_p_L();
	}
	for(int i=100;i>0;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}