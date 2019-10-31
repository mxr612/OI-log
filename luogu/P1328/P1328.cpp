#include <iostream>
#include <cstdio>
// #include <bits/stdc++.h>
using namespace std;

int N,N_a,N_b,ans_a=0,ans_b=0;
int way_a[201],way_b[201];
int win_map[7][7]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

int main(int argc, char const *argv[])
{
	freopen("P1328.in","r",stdin);
	cin>>N>>N_a>>N_b;
	for (int i = 1; i <= N_a; ++i)
	{
		cin>>way_a[i];
	}
	for (int i = 1; i <= N_b; ++i)
	{
		cin>>way_b[i];
	}
	for(int i =0;i<N;i++){
		ans_a+=win_map[way_a[i%N_a+1]][way_b[i%N_b+1]];
		ans_b+=win_map[way_b[i%N_b+1]][way_a[i%N_a+1]];
	}
	cout<<ans_a<<" "<<ans_b;
	return 0;
}
