#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>&nums){
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            mini = min(mini , nums[j]);
            sum += mini;
        }
    }
    return sum;
}
//tc O(n2)
//sc O(1)  

 vector<int> prevSmallerElem(vector<int>&nums){
        int n = nums.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> nextSmallerElem(vector<int>&nums){
        int n = nums.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n  = arr.size();
        long long total = 0;
        vector<int> pse = prevSmallerElem(arr);
        vector<int> nse = nextSmallerElem(arr);
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = ((left % mod) * (right % mod)) % mod;
            contrib = (contrib * (arr[i] % mod)) % mod;
            total = (total + contrib) % mod;
        }
        return (int)total;
    }
int main(){
    vector<int>nums = {3 , 1 , 2 , 4};
    int total = bruteforce(nums);
    vector<int> ans = nextSmallerElem(nums);
    // for(auto it : ans){
    //     cout<<it<<" ";
    // }
    int total1 = sumSubarrayMins(nums);
    cout<<total1;
//    cout<<total;
    return 0;
}