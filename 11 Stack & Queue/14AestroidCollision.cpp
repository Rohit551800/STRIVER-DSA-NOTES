#include<bits/stdc++.h>
using namespace std;
vector<int> aestroidSolu(vector<int>&nums){
    int n = nums.size();
    vector<int>ans;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(nums[i] > 0) st.push(nums[i]);
        else {
            while(!st.empty() && st.top() > 0 && st.top() < abs(nums[i])){
            st.pop();
            }
            if(!st.empty() && st.top() == abs(nums[i])){
                st.pop();
                continue;
            }
            else if(st.empty() || st.top() < 0){
                st.push(nums[i]);
            }
        }        
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
int main(){
    vector<int>nums = {-11 , 4 , -20 , 1 , 1 ,2 , -3 , -7 , 17 , 15 , -16 , -18 , -19};
    vector<int> ans = aestroidSolu(nums);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}