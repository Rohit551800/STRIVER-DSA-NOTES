#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int j = i;j<n;j++){
            mini = min(mini , nums[j]);
            maxi = max(maxi , nums[j]);
            sum += maxi - mini;
        }
    }
    return sum;
}



// OPTIMAL SOLUTION
vector<int> prevSmallerElem(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
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
    for(int i= n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
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
vector<int> nextGreaterElem(vector<int>& nums){
    int n = nums.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}
vector<int> prevGreaterElem(vector<int>& nums){
    int n = nums.size();
    stack<int>st;
    vector<int>pge(n);
    for(int i= 0;i<n;i++){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        if(st.empty()){
            pge[i] = -1;
        }
        else{
            pge[i] = st.top();
        }
        st.push(i);
    }
    return pge;
}
int calculate_sumOfSubarrayMin(vector<int>&nums){
    int n = nums.size();
    vector<int> prevSmaller = prevSmallerElem(nums);
    vector<int> nextSmaller = nextSmallerElem(nums);
    int mintotal = 0;
    for(int i = 0;i<n;i++){
        int left  = i - prevSmaller[i];
        int right = nextSmaller[i] - i;
        mintotal += left * right * nums[i];
    }
    return mintotal;
}
int calculate_sumOfSubarrayMax(vector<int>&nums){
    int n = nums.size();
    vector<int> nextGreater = nextGreaterElem(nums);
    vector<int> prevGreater = prevGreaterElem(nums);
    int maxtotal = 0;
    for(int i = 0;i<n;i++){
        int left = i - prevGreater[i];
        int right = nextGreater[i]  - i;
        maxtotal += left * right * nums[i];
    }
    return maxtotal;
}
int sumOfSubarrayRange(vector<int>&nums){
    return calculate_sumOfSubarrayMax(nums) - calculate_sumOfSubarrayMin(nums);
}
int main(){
    vector<int>nums = {1 , 4 , 3 , 2};
    // int total = bruteforce(nums);
    int total = sumOfSubarrayRange(nums);
    cout<<total;
    return 0;
}