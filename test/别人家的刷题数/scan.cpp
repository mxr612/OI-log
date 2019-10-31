#include <iostream>
#include <string>
using namespace std;


string in;
int count=0;

int main(int argc, char const *argv[])
{
	freopen("scan.in","r",stdin);
	getline(cin,in);
	for(int i=0;i<(int)in.size();i++){
		if(in[i]=='[')
			count++;
	}
	cout<<count;
	return 0;
}