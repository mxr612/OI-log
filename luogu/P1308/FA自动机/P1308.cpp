#include <iostream>
#include <string>

using namespace std;

string key, sen,cmp;
int fa[10000000]={0};
int sign=1,l;
int count=0,first=-1;

int main() {
	freopen("testdata.in", "r", stdin);
	getline(cin, key);
	getline(cin, sen);
	for (int i = 0; i < (int)key.size(); i++)
		if (key[i] >= 'A' && key[i] <= 'Z')
			key[i] += 'a' - 'A';
	for (int i = 0; i < (int)sen.size(); i++)
		if ((sen[i] >= 'A' && sen[i] <= 'Z'))
			sen[i] += 'a' - 'A';
	for(int i=0;i<(int)sen.size();i++)
		if(sen[i]==' ')
			fa[i]=1;
	fa[sen.size()]=1;
	for(int i=0;i<=(int)sen.size();i++){
		if(fa[i]==1&&sign==0){
			cmp.assign(sen,l,i-l);
			if(cmp==key){
				count++;
				if(first==-1)first=l;
			}
		}else if(fa[i]==0&&sign==1)
			l=i;
		sign=fa[i];
	}
	if(first==-1)
		cout<<-1;
	else
		cout<<count<<' '<<first;
	return 0;
}