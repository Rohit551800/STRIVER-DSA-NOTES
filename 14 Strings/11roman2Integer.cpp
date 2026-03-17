#include<bits/stdc++.h>
using namespace std;
int num(char x){
    if(x == 'I') return 1;
    else if(x == 'V') return 5;
    else if(x == 'X') return 10;
    else if(x == 'L') return 50;
    else if(x == 'C') return 100;
    else if(x == 'D') return 500;
    else if(x == 'M') return 1000;
}
int convert2INT(string &s){
    int n = s.size();
    // Rules
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(num(s[i+1]) > num(s[i])){
            ans += -num(s[i]);
        }
        else{
            ans += num(s[i]);
        }
    }
    ans += num(s[n-1]);
    return ans;
}
int main(){
    string s = "CD";
    cout<<convert2INT(s);
    return 0;
}