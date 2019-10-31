// 01

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string str;

short gj[11000]={0};

int main(){

	freopen("01.in","r",stdin);

// InPut
	cin>>str;

// 
	for(int i=0;i<int(str.size());++i)
		if(str[i]=='P')
			str.erase(i,1);

// 


// OutPut
	cout<<str;

	return 0;
}