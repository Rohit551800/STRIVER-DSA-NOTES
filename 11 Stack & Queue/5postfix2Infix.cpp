#include<bits/stdc++.h>
using namespace std;
string postfix2Infix(string &s){
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
            string newTop = '(' + top2 + string(1,s[i]) + top1 + ')';
            stack.push(newTop);
        }
        i++;
    }
    return stack.top();
}
string prefix2Infix(string &s){
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
            string newTop = "(" + top1 + string(1,s[i]) + top2 + ")";
            st.push(newTop);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter the postix:";
    getline(cin , s);
  //  string postfixExp = postfix2Infix(s);
    string prefixExp = prefix2Infix(s);
    cout<<"Infix string is :"<<prefixExp;
    return 0;
}