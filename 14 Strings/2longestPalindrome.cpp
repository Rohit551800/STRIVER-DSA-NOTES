#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s){
    int size  = s.size();
    vector<int>lower(26,0),upper(26,0);
    //Calculate count
    for(int i=0;i<size;i++){
        if(s[i] >= 'a'){
            lower[s[i] - 'a']++;
        }
        else{
            upper[s[i] - 'A']++;
        }
    }

    //Main task
    bool odd = 0;
    int count = 0;
    for(int i=0;i<26;i++){
        if(lower[i]%2 == 0){
            count += lower[i];
        }
        else{
            count += lower[i] -1;
            odd = 1;
        }
    }
    for(int i=0;i<26;i++){
        if(upper[i]%2 == 0){
            count += upper[i];
        }
        else{
            count += upper[i] -1;
            odd = 1;
        }
    }
    if(odd) return count+1;
    else return count;
}
int main(){
    string s = "aabbaabbccc";
    cout<<longestPalindrome(s);
    return 0;
}