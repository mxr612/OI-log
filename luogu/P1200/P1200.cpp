#include<iostream>

using namespace std;

string a,b;

int aa=1,bb=1;

int main(){
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        aa*=a[i]-'A'+1;
        aa%=47;
    }
    for(int i=0;i<b.size();i++){
        bb*=b[i]-'A'+1;
        bb%=47;
    }
    if(aa==bb){
        cout<<"GO";
    }else{
        cout<<"STAY";
    }
    return 0;
}