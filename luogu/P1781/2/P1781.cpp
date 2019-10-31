#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_LEN 200

int m,ans;
int maxx[MAX_LEN + 1] = {0},mlen=0;
int InPut[MAX_LEN + 1] = {0},ilen;

int main(int argc, char const *argv[])
{
	freopen("P1781.in", "r", stdin);
	cin>>m;
	for(int i=1;i<=m;i++){
		memset(InPut,0,sizeof(InPut));
		ilen=0;
		char cmd=getchar();
		while(cmd<'0'||cmd>'9')cmd=getchar();
		while(cmd>='0'&&cmd<='9'){
			InPut[++ilen]=cmd-'0';
			cmd=getchar();
		}
		if(ilen<mlen){
			continue;
		}else if(ilen==mlen){
			int j=1;
			while(j<=mlen&&maxx[j]==InPut[j])j++;
			if(maxx[j]>InPut[j]){
				continue;
			}
		}
		ans=i;
		mlen=ilen;
		for(int j=1;j<=mlen;j++){
			maxx[j]=InPut[j];
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=mlen;i++){
		cout<<maxx[i];
	}
	return 0;
}