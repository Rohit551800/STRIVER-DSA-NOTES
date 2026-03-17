#include<bits/stdc++.h>
using namespace std;
int maximumCardPoints(vector<int>&nums , int k){
    int l = 0 , r = nums.size()-1 , leftSum = 0 , rightSum = 0 , maxSum = 0;
    while(l < k){
        leftSum += nums[l];
        l++;
    }
    maxSum = max(maxSum , leftSum);
    while(l > 0){
        leftSum -= nums[l-1];
        l--;
        rightSum += nums[r];
        r--;
        maxSum = max(maxSum , rightSum + leftSum);
    }
    return maxSum ;
}
int main(){
    int k ;
    cout<<"Enter the size for the window:";
    cin>>k;
    vector<int>nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};

    int solution = maximumCardPoints(nums , k) ;
    cout<<"MaxSum  :"<<solution;
    return 0;
}