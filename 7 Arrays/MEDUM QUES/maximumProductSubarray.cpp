#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int bruteforceSolu(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j = i;j<n;j++){
            product = product * nums[j];
            maxi = max(product , maxi);
        }
    }
    return maxi;
}
int optimalSolu(vector <int> &nums){
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];
        maxi = max (maxi , max (prefix , suffix));
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int a ;
        cout<<"Enter element "<<i+1<<":";
        cin>>a;
        nums.push_back(a);
    }
    cout<<"Maximum Subarray Product is :"<<bruteforceSolu(nums)<<endl;
    cout<<"Maximum Subarray Product is :"<<optimalSolu(nums);
}