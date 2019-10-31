#include <iostream>
using namespace std;

struct node
{
	int a,b;
	double vl=1.0*a/b;
}te={1,2};

int main(){
	te.a=2;
	cout<<te.vl;
	return 0;
}