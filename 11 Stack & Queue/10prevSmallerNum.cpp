#include<bits/stdc++.h>
using namespace std;
vector<int> prevSmallerNum(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = st.top();
        }
        st.push(nums[i]);
    }
    return pse;
}
int main(){
    vector<int>nums = { 4  , 5 , 2 , 10 , 8};
    vector<int> ans = prevSmallerNum(nums);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}