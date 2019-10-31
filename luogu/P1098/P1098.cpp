#include <iostream>
#include <string>

using namespace std;

int p1,p2,p3;
string str;
char l,r;


bool cknum(char a){
	return (a>='0'&&a<='9')?true:false;
}

bool cklet(char a){
	return (a>='a'&&a<='z')?true:false;
}


bool same(char a,char b){
	if(cknum(a)&&cknum(b))
		return true;
	if(cklet(a)&&cklet(b))
		return true;
	return false;
}

void f1(char a){
	if(p1==3){
		cout<<'*';
	}else if(cknum(a)||p1==1){
		cout<<a;
	}else{
		cout<<(char)(a-('a'-'A'));
	}
}

void f2(char a){
	for(int i=1;i<=p2;i++){
		f1(a);
	}
}

void f3(char a,char b){
	if(p3==1)
		for(char i=a+1;i<b;i++)
			f2(i);
	else
		for(int i=b-1;i>a;i--)
			f2(i);
}

int main(){
	freopen("P1098.in","r",stdin);
	cin>>p1>>p2>>p3;
	cin>>str;
	cout<<str[0];
	for(int i=1;i<(int)str.length()-1;i++){
		if(str[i]=='-'&&same(str[i-1],str[i+1])&&str[i-1]<str[i+1]){
			f3(str[i-1],str[i+1]);
		}else
			cout<<str[i];
	}
	cout<<str[int(str.length())-1];
	return 0;
}