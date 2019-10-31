// 1

#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int n;

map<string,int>T;
map<int,string>B;

int cnt=0;
struct fs{int fz,fm;}V[10][10];
bool vis[10][10]={false};

int askn;
string asks;

int aswi=0,aswg;
double aswf;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

struct fs cf(struct fs a,struct fs b){
	int fz=a.fz*b.fz,fm=a.fm*b.fm,c=gcd(fz,fm);
	return {fz/c,fm/c};
}

int main(){

	freopen("1.in","r",stdin);

	cin>>n;
	for(int i=1;i<=n;++i){
		string sa,sb;
		int na,nb;
		char c;
		cin>>na>>sa>>c>>nb>>sb;
		if(T[sa]==0)T[sa]=++cnt,B[cnt]=sa;
		if(T[sb]==0)T[sb]=++cnt,B[cnt]=sb;
		vis[T[sa]][T[sb]]=vis[T[sb]][T[sa]]=true;
		V[T[sa]][T[sb]]={na,nb};
		V[T[sb]][T[sa]]={nb,na};
	}
	for(int i=1;i<=cnt;++i)
		V[i][i]={1,1},vis[i][i]=true;

// 
	for(int k=1;k<=cnt;++k){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;++j){
				if(!vis[i][j]&&vis[i][k]&&vis[k][j]){
					V[i][j]=cf(V[i][k],V[k][j]);
					vis[i][j]=true;
				}
			}
		}
	}

// 
	cin>>askn>>asks;
	for(int i=1;i<=n;++i){
		if(i!=T[asks]&&vis[T[asks]][i]){
			int give=ceil((double)askn*V[i][T[asks]].fz/V[i][T[asks]].fm);
			double fact=(double)give*V[T[asks]][i].fz/V[T[asks]][i].fm;
			// cout<<B[i]<<' '<<give<<' '<<fact<<endl;
			if(aswi==0||fact<aswf){
				aswi=i;
				aswf=fact;
				aswg=give;
			}
		}
	}

// out
	// for(int i=1;i<=cnt;++i){
	// 	for(int j=1;j<=cnt;++j){
	// 		printf("%5d/%-5d",V[i][j].fz,V[i][j].fm);
	// 		// printf("|%lf|",V[i][j].vl);
	// 		// printf("%5d",vis[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	cout<<aswg<<' '<<B[aswi];

	return 0;
}