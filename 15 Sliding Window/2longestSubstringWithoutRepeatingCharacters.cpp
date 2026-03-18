#include<bits/stdc++.h>
using namespace std;
int bruteforceLongestSubstring(string &s){
    int n = s.size();
    int maxLen = 0 ;
    for(int i=0;i<n;i++){
        int hash[256] = {0};
        for(int j=i;j<n;j++){
            char c = s[j];
            if(hash[c] == 1){
                maxLen = max(maxLen , j-i);
                break;
            }
            else{
                hash[c]++;
            }
        }
    }
    return maxLen;
}
int optimalLongestSubstring(string &s){
    int n = s.size();
    int maxLen = 0 ;
    int l = 0 , r = 0 ;
    int hash[256] = {0};
    while(r < n){
        if(hash[s[r]] == 0){
            hash[s[r]] =  1;
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        else{
            hash[s[l]] = 0;
            l++;           
        }
    }
    return maxLen;
}
int main(){
    string s = "cadbzabedxx";
    // cout<<bruteforceLongestSubstring(s);
    cout<<optimalLongestSubstring(s);
    return 0;
}