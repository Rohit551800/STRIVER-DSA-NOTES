#include<bits/stdc++.h>
using namespace std;
int priorityOperator(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
string reverseString(string s){
    int n = s.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
        if(s[j] == '(') s[j] = ')';
        else if(s[j] == ')') s[j] = '(';
        swap(s[i] , s[j]);
        i++;
        j--;
    }
    return s;
}
string infix2Postfix(string &s){
    int i =0;
    int n = s.size();
    stack<char>st;
    string ans = "";
    while(i<n){
        if(s[i] == ' '){
            i++;
            continue;
        }
        if(isalnum(s[i])){
            ans += s[i];
        }
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(st.top() == '^'){}
            else st.pop();
        }
        else{
            while(!st.empty() && priorityOperator(s[i]) <= priorityOperator(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
string infix2Prefix(string &s){
    string s1 = reverseString(s);
    string ans = infix2Postfix(s1);
    return reverseString(ans);
}
int main(){
    string s;
    cout<<"Enter the Infix:";
    getline(cin , s);
  //  string ans = infix2Postfix(s);
    string ans = infix2Prefix(s);
    cout<<"Prefix string is :"<<ans;
    return 0;
}