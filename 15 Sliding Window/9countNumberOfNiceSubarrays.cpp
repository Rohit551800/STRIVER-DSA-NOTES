#include <bits/stdc++.h>
using namespace std;
int bruteforce(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
            break;
        }
    }
    return count;
}
//Optimal Solution
int funcAtMost(vector<int> &nums, int goal)
{
    int n = nums.size();
    if (goal < 0)
        return 0;
    int right = 0, left = 0, count = 0, sum = 0;

    while (right < n)
    {
        sum += nums[right] % 2;
        while (sum > goal)
        {
            sum -= nums[left] % 2;
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    return count;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return funcAtMost(nums, k) - funcAtMost(nums, k - 1);
}
int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << bruteforce(nums, k);
    return 0;
}