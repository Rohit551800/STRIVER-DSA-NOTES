#include <bits/stdc++.h>
using namespace std;
bool balancedProblem(string &s)
{
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if (s[i] == ')' && ch == '(' ||
                s[i] == ']' && ch == '[' ||
                s[i] == '}' && ch == '{')
                {}
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
bool validParenthesis(string s){
    int low = 0, high = 0; 
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { 
                low--;      
                high++;      
            }

            if (high < 0) return false; 
            if (low < 0) low = 0;       
        }
        return (low == 0);
}
int main()
{
    string s;
    cout << "Enter the parenthesis string:";
    cin >> s;
    cout<<balancedProblem(s);
    return 0;
}