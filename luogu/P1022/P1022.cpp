#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string fc;
float a=0,b=0;
float ans;
char bl;
int mid,num=0,sign=-1;

int main(){
	freopen("testdata.in","r",stdin);
	cin>>fc;
	mid=fc.find('=',0);
	for(int i=0;i<=(int)fc.length();i++){
		if(fc[i]>='0'&&fc[i]<='9'){
			num=num*10+fc[i]-'0';
		}else{
			if(fc[i]>='a'&&fc[i]<='z'){
				bl=fc[i];
				if(num==0)num=1;
				b+=num*sign*-1;
			}else{
				a+=num*sign;
				if(fc[i]=='-'){
					sign=-1*(i<mid?-1:1);
				}else{
					sign=1*(i<mid?-1:1);
				}
			}
			num=0;
		}
	}
	// cout<<a<<endl<<b<<endl;
	printf("%c=%.3f",bl,a/b==0?0:a/b);
	return 0;
}