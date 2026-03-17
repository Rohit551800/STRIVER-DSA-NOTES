#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s){
        unordered_map<char , int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto it : mpp){
            v.push_back(it);
        }
        sort(v.begin() , v.end() , [](auto &a , auto &b){
            return a.second > b.second;
        });
        string ans = "";
        for(auto it: v){
            ans += string(it.second , it.first);
        }
        return ans;
}
int main(){
    string s = "tree";
    string result = frequencySort(s);
    cout<<result;
    return 0;
}