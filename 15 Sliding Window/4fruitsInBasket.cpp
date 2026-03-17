#include <bits/stdc++.h>
using namespace std;
int bruteforce(vector<int> &fruits, int basket)
{
    int n = fruits.size();
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        int length = 0;
        for (int j = i; j < n; j++)
        {
            s.insert(fruits[j]);
            if (s.size() <= basket)
            {
                length = j - i + 1;
            }
            else
            {
                break;
            }
        }
        maxSize = max(maxSize, length);
    }
    return maxSize;
}
int optimal(vector<int> &fruits, int basket)
{
    int n = fruits.size();
    int left = 0, right = 0;
    unordered_map<int, int> freq;
    int maxLen = 0;
    while (right < n)
    {
        freq[fruits[right]]++;
        while (freq.size() > basket)
        {
            freq[fruits[left]]--;
            if (freq[fruits[left]] == 0)
            {
                freq.erase(fruits[left]);
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
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int basket;
    cout << "Enter the number of baskets :";
    cin >> basket;
    // cout<<bruteforce(fruits , basket);
    cout << optimal(fruits, basket);
    return 0;
}