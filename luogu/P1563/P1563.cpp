#include <iostream>
#include <cstdio>
// #include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_char 300

int n,m,now_way,now_v,now_place=0,way;
int man_way[MAX_N],man_name[MAX_N][MAX_char];

int jd(int a){
	while(a<0){
		a+=n;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	freopen("P1563.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d %s",&man_way[i],man_name[i]);
	}
	for(int i=1;i<=m;i++){
		
		cin>>now_way>>now_v;
		if(man_way[now_place+1]==now_way){
			way=-1;
		}else{
			way=1;
		}
		now_place=jd(now_place+way*now_v);
		now_place%=n;
		// printf("%d %d %d %d %s\n", now_place+1,now_way,man_way[now_place],now_v,man_name[now_place+1]);
	}
	printf("%s",man_name[now_place+1] );
	return 0;
}
