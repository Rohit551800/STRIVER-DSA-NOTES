#include<bits/stdc++.h>
using namespace std;
string sortVowels(string &s){
    vector<int>lower(26,0),upper(26,0);

    for(int i=0;i<s.size();i++){
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            upper[s[i]-'A']++;
        }
        else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            lower[s[i] - 'a']++;
        }
    }
    
    string ans = "" , str1 = "" , str2 = "";
    int u = 0 , l = 0;

    for(u=0;u<26;u++){
        while(upper[u] > 0){
            str1.push_back(u + 'A');
            upper[u]--;
        }
    }
    for(l=0;l<26;l++){
        while(lower[l]>0){
            str2.push_back(l + 'a');
            lower[l]--;
        }
    }
    string vowels = str1 + str2;
    int index = 0;

    for(int i=0;i<s.size();i++){
        if(!(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U' ||
             s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')){
            ans += s[i];
        }
        else{
            ans.push_back(vowels[index++]);
        }
    }
    return ans;
}
int main(){
    string s = "lEetcOde";
    cout<<sortVowels(s);
    return 0;
}