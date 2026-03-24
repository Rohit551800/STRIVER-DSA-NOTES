#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    int hash[256] = {0};
    for (int i = 0; i < m; i++)
    {
        hash[t[i]]++;
    }

    int left = 0, right = 0, minLen = INT_MAX, sIndex = -1, count = 0;

    while (right < n)
    {
        if (hash[s[right]] > 0)
        {
            count++;
        }
        hash[s[right]]--;
        while (count == m)
        {
            if ((right - left + 1) < minLen)
            {
                minLen = right - left + 1;
                sIndex = left;
            }
            hash[s[left]]++;
            if (hash[s[left]] > 0)
                count--;
            left++;
        }
        right++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
int main(){
    string s , t;
    cout<<"Enter the textString : ";
    cin>>s;
    cout<<"Enter the requiredString : ";
    cin>>t;
    string ans = minWindow(s , t);
    cout<<ans;
}