/**
 * @file 14.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2022-09-23
 * @brief 
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans=strs[0].size();
        // cout<<strs[0].size()<<endl;
        for(int i=1;i<strs.size();++i){
            // ans=min(ans,(int)strs[i].size())
            for(int j=0;j<=min((int)strs[i].size(),ans);++j)
                if(strs[0][j]!=strs[i][j])
                    ans=j;
        }
        return strs[0].substr(0,ans);
    }
}; 

int main(){

    vector<string> str;

    str.push_back("flower");
    str.push_back("flow");
    str.push_back("flight");


    Solution so;

    cout<<so.longestCommonPrefix(str);

    return 0;
}