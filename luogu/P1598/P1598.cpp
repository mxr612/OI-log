#include <iostream>
#include <string>

using namespace std;

string str, cmp;
int count[200] = {0};
int maxx=-1,ed[500]={0};

int main() {
	freopen("P1598.in", "r", stdin);
	getline(cin, cmp); str += cmp;
	getline(cin, cmp); str += cmp;
	getline(cin, cmp); str += cmp;
	getline(cin, cmp); str += cmp;
	for (int i = 0; i < (int)str.length(); i++)
		count[(int)str[i]]++;
	for(int i='A';i<='Z';i++){
		maxx=max(maxx,count[i]);
		for(int j=1;j<=count[i];j++)
			ed[j]=max(ed[j],i);
	}
	for(int i=maxx;i>0;i--){
		cout<<(count[(int)'A']>=i?'*':' ');
		for(int j='B';j<=ed[i];j++)
			cout<<' '<<(count[j]>=i?'*':' ');
		cout<<endl;
	}
	for(int i='A';i<'Z';i++)
		cout<<((char)i)<<' ';
	cout<<'Z'<<endl;
	return 0;
}