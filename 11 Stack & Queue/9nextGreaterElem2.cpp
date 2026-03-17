#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>nge(nums.size());
        for(int i=2*n-1;i>=0;i--){
            int index = i % n;
            while(!st.empty() && st.top() <= nums[index]){
                st.pop();
            }
            if(i < n){
                if(st.empty()){
                    nge[index] = -1;
                }
                else{
                nge[index] = st.top();
                }
            }
            st.push(nums[index]);
        }
        return nge;
    }
};
int main(){
    Solution sol;
    int n ;
    cout<<"Enter the number of elem:";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans = sol.nextGreaterElements(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
}