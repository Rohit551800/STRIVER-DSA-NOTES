#include<bits/stdc++.h>
using namespace std;
int bruteforceMaxConsecutiveOnes(vector<int>&nums ,int k){
    int n = nums.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        int len = 0;
        int x = k;
        for(int j=i;j<n;j++){
            if(nums[j] == 1){
                len++;
            }
            else{
                if(x > 0){
                    len++;
                    x--;
                }
                else{
                    break;
                }
            }
        }
        maxLen = max(maxLen , len);
    }
    return maxLen;
}
int optimalMaxConsecutiveOnes(vector<int>&nums , int k){
    int n = nums.size();
    int maxLen = 0;
    int left = 0 , right = 0 , x = k;
    while(right < n){
        if(nums[right] == 1){
            maxLen = max(maxLen , right - left + 1);
            right++;
        }
        else{
            if(x > 0){                
                maxLen = max(maxLen , right - left + 1);
                right++;
                x--;
            }
            else{
                x = k;
                while(left < right){
                    left++;
                }
            }
        }
    }
    return maxLen;
}
int main(){
    int k = 2;
    vector<int>nums = {1,1,1,1,0,0,1,1,1,1,0};
    // cout<<bruteforceMaxConsecutiveOnes(nums , k);
    cout<<optimalMaxConsecutiveOnes(nums , k);
    return 0;
}