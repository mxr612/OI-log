#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void GetCode(string code[],int len);//OK

bool Err(string code[],int len);//OK
int cp(string s); //OK
int Dep(string code[],int len);//OK

string Ts(int n);//OK
void Ans(string in,string code[],int len);//OK

int T,l;
string in,code[200];

int main(){
	freopen("testdata.in","r",stdin);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>l;getchar();cin>>in;getchar();
		GetCode(code,l);
		Ans(in,code,l);
	}
	return 0;
}

void GetCode(string code[],int len){
	for(int i=0;i<len;i++)
		getline(cin,code[i]);
}

bool Err(string code[],int len){//error return true
	int sta[150],ck[150]={0},pt=0;
	string cmp;
	for(int i=0;i<l;i++){
		cmp=code[i];
		if(cmp[0]=='F'){
			if(ck[int(cmp[2])]==0){
				sta[pt]=cmp[2];
				ck[sta[pt]]=1;
			}else
				return true;
			pt++;
		}
		if(cmp[0]=='E')
			ck[sta[--pt]]=0;
	}
	if(pt==0)
		return false;
	else
		return true;
}

int cp(string s){
	const int n=300;
	int x=0,y=0;
	int p1=s.find(' ',0),p2=s.find(' ',p1+1),p3=s.find(' ',p2+1);
	if(s[p2+1]=='n') x=n;
	else for(int i=p2+1;i<p3;i++) x=x*10+s[i]-'0';

	if(s[p3+1]=='n') y=n;
	else for(int i=p3+1;i<int(s.length());i++) y=y*10+s[i]-'0';
	if(y==n&&x!=n) return 2;
	if(x<=y)return 1;
	return 0;
}

int Dep(string code[],int len){
	int dep=0,maxx=0,sta[150],top=-1,flag=0;
	string cmp;
	for(int i=0;i<len;i++){
		cmp=code[i];
		if(cmp[0]=='F'){
			sta[++top]=cp(cmp);
			if(sta[top]==0){
				top--;
				flag++;
				while(flag>0){
					cmp=code[++i];
					if(cmp[0]=='F')flag++;
					else if(cmp[0]=='E')flag--;
				}
			}else if(sta[top]==2)
				dep++;
		}else if(cmp[0]=='E')
				if(sta[top--]==2)
					maxx=max(maxx,dep--);
	}
	return maxx;
}

string Ts(int n){
	char c[5];
	if(n<10){
		c[0]=n+'0';
		c[1]='\0';
	}else{
		c[1]=n%10+'0';n/=10;
		c[0]=n+'0';
		c[2]='\0';
	}
	return c;
}

void Ans(string in,string code[],int len){
	int w;
	string cmp;
	if(Err(code,len))
		cout<<"ERR"<<endl;
	else {
		w=Dep(code,len);
		if(w==0)
			cmp="O(1)";
		else
			cmp="O(n^"+Ts(w)+")";
		if(cmp==in)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}