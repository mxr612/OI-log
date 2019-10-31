#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a,b;
int la,lb;
int hw[1000000],pt=0;

bool ck(int key){
	if(key<=1)
		return false;
	for(int i=2;i<=sqrt(key);i++)
		if(key%i==0)
			return false;
	return true;
}

void make(int len,int deep,int num){
	if(deep>int(len/2)){
		if(len%2!=0){
			int cmp;
			for(int i=0;i<=9;i++){
				hw[++pt]=num*10+i;
				cmp=num;
				while(cmp!=0){
					hw[pt]=hw[pt]*10+cmp%10;
					cmp/=10;
				}
			}
		}else{
			hw[++pt]=num;
			while(num!=0){
				hw[pt]=hw[pt]*10+num%10;
				num/=10;
			}
		}
		return ;
	}
	for(int i=0;i<=9;i++)
		make(len,deep+1,num*10+i);
}

int main(){
	freopen("P1217.in","r",stdin);
	cin>>a>>b;
	la=int(log10(a));
	lb=int(log10(b))+1;
	for(int i=la;i<=lb;i++)
		make(i,1,0);
	sort(hw+1,hw+pt+1);
	for(int i=1,mem=-1;i<=pt;i++){
		if(hw[i]>=a&&hw[i]<=b&&ck(hw[i])&&hw[i]!=mem)
			cout<<hw[i]<<endl;
		mem=hw[i];
	}
	return 0;
}