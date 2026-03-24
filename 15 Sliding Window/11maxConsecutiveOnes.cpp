#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    int left = 0, right = 0, x = k;
    while (right < n)
    {
        if (nums[right] == 1)
        {
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        else
        {
            if (x > 0)
            {
                maxLen = max(maxLen, right - left + 1);
                right++;
                x--;
            }
            else
            {
                if (nums[left] == 0)
                {
                    x++;
                }
                left++;
            }
        }
    }
    return maxLen;
}
int main(){
    int k = 2;
    int n ;
    cout<<"Enter the size of array :";
    cin>>n;
    vector<int>nums(n);
    for(auto &it : nums){
        cin>>it;
    }
    int result = longestOnes(nums , k);
    cout<<result;
    return 0;
}
