#include<bits/stdc++.h>
using namespace std; 
int bruteforce(vector<int>&nums , int k){
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum == k) count++;
            break;
        }
    }
    return count;
}
int main(){
    vector<int>nums = {1,1,2,1,1};
    int k = 3;
    cout<<bruteforce(nums , k);
    return 0;
}