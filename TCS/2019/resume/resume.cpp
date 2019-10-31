//resume

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int A,K;
string cd[2];
string ask;

int E[200][200]={0};
int at[200]={0};

int inV[200]={0};
int vis[200]={0};
queue<int>que;
int top;
int flag=0;

int ans[200],ed=0;

int main(){
	freopen("resume.in","r",stdin);
	freopen("resume.out","w",stdout);
	
	cin>>A>>K;
	cin>>cd[0];
	for(int i=1,j;i<K;i++){//读入+大小关系做边 
		cin>>cd[i%2];
		j=0;
		while(cd[0][j]==cd[1][j]&&j<cd[0].length()&&j<cd[1].length())j++;
		if(j<cd[0].length()&&j<cd[1].length())
			E[cd[(i+1)%2][j]][cd[i%2][j]]=1;
	}
	cin>>ask;
	
	for(int i='a';i<='z';i++)//出现 
		for(int j='a';j<='z';j++)
			if(E[i][j]==1)
				at[i]=at[j]=1;
	for(int i='a',j=0;i<='z';i++)
		if(at[i]==1)
			at[++j]=i;
	
	for(int i=1;i<=A;i++)
		for(int j='a';j<='z';j++)
			inV[i]+=E[j][at[i]];
//拓扑 
	for(int i=1;i<=A;i++)
		if(inV[i]==0)
			que.push(i),inV[i]=-1;
	while(!que.empty()){
		if(que.size()!=1)
			flag=1;
		top=que.front();
		que.pop();
		ans[++ed]=at[top];
		for(int i=1;i<=A;i++){
			if(E[at[top]][at[i]]==1)
				inV[i]--;
			if(inV[i]==0)
				que.push(i),inV[i]=-1;
		} 
	}
	for(int i=1;i<=A;i++)
		if(inV[i]!=-1)
			flag=1;
	if(flag==0){
		for(int i=1;i<=A;i++)
		ans[ans[i]]=at[i];
	for(int i=0;i<ask.length();i++)
		ask[i]=ans[ask[i]];
	cout<<ask;
	}else{
		cout<<0;
	}
	return 0;
}
