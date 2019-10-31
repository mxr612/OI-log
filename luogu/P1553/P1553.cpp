#include <iostream>
#include <string>

using namespace std;

#define si (int)num.size()

string num,cmp;
int mem=0,p=0,flag=0;
char ans[50];
int pt=0;

int main(){
	freopen("P1553#2.in","r",stdin);
	cin>>num;
	while(p<si){
		while(p<si&&num[p]>='0'&&num[p]<='9')p++;
		for(int i=p-1;i>=mem;i--){
			if(flag==0){
				if(num[i]=='0')
					continue;
				else
					flag=1;
			}
			ans[pt++]=num[i];
		}
		if(flag==0)
			ans[pt++]='0';
		else
			flag=0;
		mem=p+1;
		if(p<si)
			ans[pt++]=num[p];
		p++;
	}
	if((int)num.find('.',0)!=-1&&ans[pt-2]!='.'){
		while(ans[pt-1]=='0')pt--;
	}
	ans[pt]='\0';
	cout<<ans;
	return 0;
}