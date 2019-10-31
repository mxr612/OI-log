
//P1056
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_D 2000

struct node
{
	int v,w;
}talk_students_x[MAX_D],talk_students_y[MAX_D];

int M,N,K,L,D;

/*
M_x_K
N_y_L
*/

int qcmp(const void *a,const void *b){
	return (*(node *)b).v-(*(node *)a).v;
}

int qcmpw(const void *a,const void *b){
	return (*(node *)a).w-(*(node *)b).w;
}

int main(int argc, char const *argv[])
{
	freopen("P1056.in","r",stdin);
	freopen("P1056_.out","w",stdout);
	cin>>M>>N>>K>>L>>D;
	for (int i = 0; i <= M; ++i)
	{
		talk_students_x[i].w=i;
	}
	for (int i = 0; i <= N; ++i)
	{
		talk_students_y[i].w=i;
	}
	for (int i = 1; i <= D; ++i)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			talk_students_y[min(y1,y2)].v++;
		}else{
			talk_students_x[min(x1,x2)].v++;
		}
	}
	qsort(&talk_students_x[1],M,sizeof(talk_students_x[1]),qcmp);
	qsort(&talk_students_y[1],N,sizeof(talk_students_y[1]),qcmp);
	qsort(&talk_students_x[1],K,sizeof(talk_students_x[1]),qcmpw);
	qsort(&talk_students_y[1],L,sizeof(talk_students_y[1]),qcmpw);
	for(int i=1;i<=K;i++){
		cout<<talk_students_x[i].w<<" ";
	}
	cout<<endl;
	for(int i=1;i<=L;i++){
		cout<<talk_students_y[i].w<<" ";
	}
	return 0;
}
