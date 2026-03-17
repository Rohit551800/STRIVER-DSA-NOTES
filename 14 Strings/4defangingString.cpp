#include<bits/stdc++.h>
using namespace std;
string defangingString(string &s){
    int n = s.size();
    string result = "";
    for(int i=0;i<n;i++){
        if(s[i] != '.'){
            result += s[i];
        }
        else{
            result.push_back('[');
            result +=  s[i] ;
            result.push_back(']');
        }
    }
    return result;
}
int main(){
    string s = "256.100.111.111";
    cout<<defangingString(s);
    return 0;
}