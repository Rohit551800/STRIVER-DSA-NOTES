#include<bits/stdc++.h>
using namespace std;
string postfix2Prefix(string &s){
    int i = 0;
    stack<string>stack;
    while(i < s.size()){
        if(s[i] == ' '){
            i++;
            continue;
        }
        else if(isalnum(s[i])){
            stack.push(string(1 , s[i]));
        }
        else{
            string top1 = stack.top();
            stack.pop();
            string top2 = stack.top();
            stack.pop();
            string newTop =string(1,s[i]) +top2 + top1 ;
            stack.push(newTop);
        }
        i++;
    }
    return stack.top();
}
string prefix2Postfix(string &s){
    int i = s.size()-1;
    stack<string>st;
    while(i >= 0 ){
        if(s[i] == ' '){
            i--;
            continue;
        }
        else if(isalnum(s[i])){
            st.push(string(1 , s[i]));
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string newTop =top1 + top2 + string(1,s[i]);
            st.push(newTop);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter the prefix:";
    getline(cin , s);
  //  string prefixExp = postfix2Prefix(s);
    string postfixExp = prefix2Postfix(s);
    cout<<"Postfix string is :"<<postfixExp;
    return 0;
}