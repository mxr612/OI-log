// question

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

short n,w,top=0,ans=70;
ULL mi[70],man[70]={0},able[70];

int _cmpS(ULL czj,ULL djm){
	int tjq=0,fxy=0;
	while(czj)tjq++,czj&=czj-1;
	while(djm)fxy++,djm&=djm-1;
	return tjq>fxy;
}

void dfs(int dep,int dad,int sta){
	if(sta==mi[n+1]-1){
		ans=dep;
		for(int i=1;i<=dep;++i)	cout<<'-';
		cout<<dad<<endl;
	}else{
		for(int i=1;i<=dep;++i)	cout<<' ';
		cout<<dad<<endl;
		++dep;
		for(int i=dad+1;i<=top;++i){
			if((sta|able[i])>sta&&dep<ans){
				dfs(dep,i,sta|able[i]);
			}
		}
	}
	
	
}

int main(){

	freopen("question.in","r",stdin);
	freopen("question.out","w",stdout);

	mi[1]=1;
	for(int i=2;i<=64;++i)
		mi[i]=mi[i-1]<<1;

	cin>>n>>w;

	for(int i=1,cmpi;i<=w;++i){
		cin>>cmpi;
		for(int j=1,cmpj;j<=cmpi;++j){
			cin>>cmpj;
			man[i]|=mi[cmpj];
		}
	}
	sort(&man[1],&man[w+1],_cmpS);
	for(int i=1,flag;i<=w;++i){
		flag=1;
		// for(int j=1;j<=top&&flag==1;++j){
		// 	if((man[i]|able[j])==able[j]){
		// 		flag=0;
		// 	}
		// }
		if(flag==1){
			able[++top]=man[i];
		}
	}

	dfs(0,0,0);

	cout<<ans;

	return 0;
}
/*
4 4
2 1 2
1 4
3 2 3 4
2 1 3

*/