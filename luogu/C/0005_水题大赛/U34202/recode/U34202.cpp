//U34202
#include <iostream>
#include <cstdio>
using namespace std;

long long A,B,j,ans=0;
int cf,ans_a=0;

int main(int argc, char const *argv[])
{
    freopen("U34202.in","r",stdin);
    cin>>A>>B;
    j=0;
    while(j<=A)
    {
        j++;
        if(j%2){
            ans+=A/j*-1;
        }else{
            ans+=A/j;
        }
    }
    for(int i=A+1;i<=B;i++){
        ans*=2;
        if(j%2){
            ans+=i/j*-1;
        }else{
            ans+=i/j;
        }
    }
    for(int i=A;i<=B;i++){
    	for(int j=1;j<=i;j++){
    		if(j%2){
    			cf=-1;
    		}else{
    			cf=1;
    		}
    		ans_a+=(i/j)*cf;
    		cout<<ans_a<<endl;
    	}
    }
    cout<<ans<<endl<<ans_a<<endl;
    return 0;
}
