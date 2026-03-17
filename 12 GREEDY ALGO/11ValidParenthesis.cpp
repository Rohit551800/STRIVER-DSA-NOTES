#include<bits/stdc++.h>
using namespace std;
bool helper(string s , int index , int count){
    if(count < 0) return false;
    if(index == s.size()) return count == 0;
    if(s[index] == '(') return helper(s , index + 1 , count + 1);
    else if(s[index] == ')') return helper(s , index + 1 , count - 1);
    else return helper(s , index + 1 , count + 1) || helper(s , index + 1 , count - 1) || helper(s , index + 1 , count);
}
bool recursiveCode(string &s ){
    int n = s.size();
    int index = 0;
    int counter = 0;
    return helper(s , index , counter);
}


bool optimalSolu(string &s){
    int low = 0;
    int high = 0;
    int n = s.size();
    for(int i = 0;i<n;i++){
        if(s[i] == '('){
            low++;
            high++;
        }
        else if(s[i] == ')'){
            low--;
            high--;
        }
        else{
            low--;
            high++;
        }
        if(low < 0) low  = 0;
        if(high < 0)  return false;
    }
    return low == 0;
}
int main(){
    string s = "*))";
  //  cout<<recursiveCode(s);
    cout<<optimalSolu(s);
    return 0;
}