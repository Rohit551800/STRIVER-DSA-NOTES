#include<bits/stdc++.h>
using namespace std;
string sortingString(string &s){
    int n = s.size();
    vector<string> hash(5);
    for(int i=0;i<n;i++){
        string s1="";
        while(i < n && s[i] != ' '){
            s1.push_back(s[i]);
            i++;
        }
        int index = int(s[i - 1]) - 49; // ASCII value of 0
        s1.pop_back();
        hash[index] = s1;
    }
    string result;
    for(int i=0;i<5;i++){
        result += hash[i] + " ";
    }
    return result;
}
int main(){
    string s = "is2 sentence4 This1 a3";
    cout<<sortingString(s);
    
    return 0;
}