#include<bits/stdc++.h>
using namespace std;
int prefixMax(vector<int>&nums , int n){
    vector<int>prefix(nums.size());
    prefix[0] = nums[0];
    for(int i=1;i < nums.size();i++){
        prefix[i] = max(prefix[i-1] , nums[i]);
    }
    return prefix[n];
}
int suffixMax(vector<int>&nums , int m){
    vector<int>suffix(nums.size());
    int n = nums.size();
    suffix[n-1] = nums[n-1];
    for(int i = n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1] , nums[i]);
        
    }
    return suffix[m];
}
int countRainTrap(vector<int>&nums){
    int n = nums.size();
    int total = 0 ;
    for(int i =0;i<n;i++){
        int leftmax = prefixMax(nums , i);
        int rightmax = suffixMax(nums , i);
        if(nums[i] < leftmax && nums[i] < rightmax){
            total += min(leftmax , rightmax) - nums[i];
        }
    }
    return total;
}
int betterSolu(vector<int>& nums){
    int n = nums.size();
    vector<int>suffix(n);
    suffix[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1] , nums[i]);
    }

    int totalCount = 0 ;
    int leftMax = 0;  

    for(int i=0;i<n;i++){
        leftMax = max(leftMax , nums[i]);
        totalCount += min(leftMax , suffix[i]) - nums[i];
    }
    return totalCount;
}

// Optimal Approach // Two pointer
int optimalSol(vector<int>&nums){
    int n = nums.size();
    int low = 0 ;
    int high = n-1;
    int lMax, rMax, totalCount ;
    lMax = rMax = totalCount = 0;
    while(low <= high){
        if(nums[low] < nums[high]){
            if(nums[low] < lMax){
                totalCount += lMax - nums[low];
            }
            else{
                lMax = nums[low];
            }
            low++;
        }
        else{
            if(nums[high] < rMax){
                totalCount += rMax - nums[high];
            }
            else{
                rMax = nums[high];
            }
            high--;
        }
    }
    return totalCount;  
}
int main(){
    vector<int>nums = {0,1,0,2,1,0,1,3,2,1,2,1};
  //  int total = countRainTrap(nums);
   // int total = betterSolu(nums);
   int total = optimalSol(nums);
    cout<<total;
    return 0;
}