#include <bits/stdc++.h>
using namespace std;
int bruteforceSolution(string &s, int k)
{
    int maxLen = 0;
    int n = s.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int length = 0;
        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;
            if (mpp.size() <= k)
            {
                length = j - i + 1;
            }
            else
            {
                break;
            }
        }
        maxLen = max(length, maxLen);
    }
    return maxLen;
}
int optimalSolution(string &s, int k)
{
    int maxLen = 0;
    int left = 0, right = 0;
    int n = s.size();
    unordered_map<int, int> mpp;
    while (right < n){
        mpp[s[right]]++;
        while (mpp.size() > k){
            mpp[s[left]]--;  
            if (mpp[s[left]] == 0){
                mpp.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}
int main()
{
    string s = "aaabbccd";
    int k = 2;
    // cout<<bruteforceSolution(s , k);
    cout << optimalSolution(s, k);
    return 0;
}