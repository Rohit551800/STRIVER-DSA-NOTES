#include<bits/stdc++.h>
using namespace std;
string reverseWords(string &s){
    vector<string>v;
    for(int i=0;i<s.size();i++){
        string s1 = "";
        while(i< s.size() && s[i] != ' '){
            s1.push_back(s[i]);
            i++;
        }
        v.push_back(s1);
    }

    int n = v.size();
    string ans = "";
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ans += v[i] + ' ';
    }
    return ans;
}
int main(){
    string s = "My name is rohit";
    cout<<reverseWords(s);
    return 0;
}