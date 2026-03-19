#include<bits/stdc++.h>
using namespace std;
int bruteforce(string &s){
    int n = s.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int hash[3] = {0};
        for(int j=i;j<n;j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3) {
                // count++;
                count += n-j;
                break; //bcoz ek br hame valid substring milgyi toh uske baad agge ki sb valid hongi
            }
        } 
    }
    return count;
}
int optimal(string &s){
    int n = s.size();
    int count = 0 , lastseen[3] = {-1 , -1 , -1};
    for(int i=0;i<n;i++){
        lastseen[s[i] - 'a'] = i;
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            count = count+  1 + min(lastseen[0] , min(lastseen[1] , lastseen[2]));
        }
    }
    return count;
}
int main(){
    string req = "abc";
    string s = "bbacba";
    cout<<bruteforce(s);
    // cout<<optimal(s);
    return 0;
}