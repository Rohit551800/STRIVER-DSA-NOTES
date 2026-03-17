#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>&nums){
    int n = nums.size();
    int maxArea = 0 ;
    for(int i=0;i<n;i++){
        int minHeight = INT_MAX;
        for(int j = i;j<n;j++){
            minHeight = min(minHeight , nums[j]);
            maxArea = max(maxArea , minHeight * (j - i + 1));
        }
    }
    return maxArea;
}
vector<int> nextSmallerElem(vector<int>& nums){
    int n = nums.size();
    stack<int>st;
    vector<int>nSindex(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            nSindex[i] = n ; 
        }
        else{
            nSindex[i] = st.top();
        }
        st.push(i);
    }
    return nSindex;
}
vector<int> prevSmallerElem(vector<int>& nums){
    int n = nums.size();
    stack<int>st;
    vector<int>pSindex(n);
    for(int i= 0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            pSindex[i] = -1;
        }
        else{
            pSindex[i] = st.top();
        }
        st.push(i);
    }
    return pSindex;
}
int betterSolu(vector<int>& nums){
    int maxArea = 0;
    int n = nums.size();
    vector<int> nse = nextSmallerElem(nums);
    vector<int> pse = prevSmallerElem(nums);
    for(int i = 0;i<n;i++){
        maxArea = max(maxArea , nums[i] * (nse[i] - pse[i] - 1));
    }
    return maxArea;
}
int optimalSolu(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    int maxArea = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            int elem = nums[st.top()];
            st.pop();
            int nsIndex = i;
            int psIndex = st.empty() ? -1 : st.top();
            maxArea = max(maxArea , elem * (nsIndex - psIndex - 1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int elem = nums[st.top()];
        st.pop();
        int nsIndex = n;
        int psIndex = st.empty() ? -1 : st.top();
        maxArea = max(maxArea , elem * (nsIndex - psIndex - 1));
    }
    return maxArea;
}
int main(){
    vector<int> nums = {2 , 1 , 5 , 6 , 2 ,3 };
  //  cout<<"Bruteforce Solution for maxArea = "<<bruteforce(nums);
  //  cout<<"Better Solution for maxArea = "<<betterSolu(nums);
    cout<<"Optimal Solution for maxArea = "<<optimalSolu(nums);
    return 0;
}