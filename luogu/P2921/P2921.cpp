// P2921

#include <iostream>
#include <cstring>
using namespace std;

const int MAX=100001;

int N;
int G_E[MAX];
int G_V[MAX]={0};
int sta[MAX],pt=1;

int flag[MAX]={0};
int ne;
bool ending=false;

int main(){
// InPut
	freopen("P2921.in","r",stdin);
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>G_E[i];
// Solve
	for(int i=1;i<=N;i++)if(G_V[i]==0){
		memset(flag,0,sizeof(flag));
		ne=i;pt=0;
		while(G_V[ne]==0&&flag[ne]==0){
			flag[ne]=++pt;
			sta[pt]=ne;
			ne=G_E[ne];
		}
		if(G_V[ne]==0&&flag[ne]>0)
			for(int v=pt+1-flag[ne];pt>=flag[ne];pt--)
				G_V[sta[pt]]=v;
		for(;pt>0;pt--)
			G_V[sta[pt]]=G_V[G_E[sta[pt]]]+1;
	}
// OutPut
	for(int i=1;i<=N;i++)
		cout<<G_V[i]<<endl;
	return 0;
}