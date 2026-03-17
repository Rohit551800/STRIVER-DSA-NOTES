#include<bits/stdc++.h>
using namespace std;
bool checkRotated(string &s , string s1){
    int n = s.size();
    string str1 = "";
    
    for(int i=n-2;i<n;i++){
        str1 += s[i];
    }
    for(int i=0;i<n-2;i++){
        str1 += s[i];
    }
    
    string str2 = "";

    for(int i=2;i<n;i++){
        str2 += s[i];
    }
    for(int i=0;i<2;i++){
        str2 += s[i];
    }

    if(str1 == s1) return true;
    else if(str2 == s1) return true;
    else return false;
}
int main(){
    string s = "amazon";
    string s1 = "azonam";
    if(checkRotated(s , s1)) cout<<"true";
    else cout<<"false";
    return 0;
}