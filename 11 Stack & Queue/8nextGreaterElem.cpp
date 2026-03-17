#include<bits/stdc++.h>
using namespace std;
vector<int> bruteforceSolu(vector<int>&arr){
    int n = arr.size();
    vector<int>nge(arr.size());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] >= arr[i]){
                nge[i] = arr[j];
                break;
            }
        }
        if(nge[i] == 0) nge[i] = -1;
    }
    return nge;
}
vector<int> optimalSolu(vector<int>&arr){
    int lastInd = arr.size()-1;
    vector<int>nge(arr.size());
    stack<int> st;
    for(int i=lastInd ;i >=0;i--){
        if(st.empty()){
            nge[i] = -1;
        }
        else if(arr[i] <= st.top()){
            nge[i] = st.top();
        }
        else{
            while(!st.empty()){
                if(st.top() > arr[i]){
                    nge[i] = st.top();
                    st.push(arr[i]);
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(st.empty()){
                nge[i] = -1;
            }
        }
        st.push(arr[i]);
    }
    return nge;
}
int main(){
    vector<int> arr = {6 , 0 , 8 , 1 , 3};
    vector<int> ans = optimalSolu(arr);
   // vector<int> ans = bruteforceSolu(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}