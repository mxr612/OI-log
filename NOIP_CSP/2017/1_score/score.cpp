#include <iostream>
#include <cstdio>
using namespace std;

int A,B,C;

int main(int argc, char const *argv[])
{
	freopen("score.in","r",stdin);
	cin>>A>>B>>C;
	printf("%d",int(A*0.2+B*0.3+C*0.5));
	return 0;
}