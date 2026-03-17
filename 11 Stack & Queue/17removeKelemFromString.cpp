#include <bits/stdc++.h>
using namespace std;
string reverseStr(string &s)
{
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
string removeKdigits(string s, int k)
{
    int n = s.length();
    int i;
    if (k == n)
        return "0";
    stack<char> st;
    for (i = 0; i < n; i++)
    {
        while (k > 0 && !st.empty() && st.top() > s[i])
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while (k > 0)
    {
        st.pop();
        k--;
    }
    for (; i < n; i++)
    {
        st.push(s[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    while (ans.size() != 0 && ans.back() == '0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty())
    {
        return "0";
    }
    return ans;
}
int main()
{
    int k = 3;
    string s = "1431291";
    cout << "Smallest number string is :" << removeKdigits(s, k);
    return 0;
}