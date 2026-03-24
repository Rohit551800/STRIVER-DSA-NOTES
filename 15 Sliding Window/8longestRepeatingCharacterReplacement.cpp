#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int n = s.size();
    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    int hash[26] = {0};
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);

        while ((r - l + 1) - maxFreq > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main(){
    string s;
    cout<<"Enter the string ";
    cin>>s;
    int k;
    cout<<"Enter the value of k";
    cin>>k;
    int result = characterReplacement(s , k);
    cout<<result;
    return 0;
}