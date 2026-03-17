#include<bits/stdc++.h>
#include<vector>
using namespace std;
void bruteforceSolu(vector<int>&arr){
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]){
                leader = false;
                break;
            }
        }
        if(leader == true ) ans.push_back(arr[i]);
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
}
int optimalSolu(vector <int> &arr){
    int n = arr.size();
    vector <int> ans;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi , arr[i]);
    }
    for(auto it: ans){
        cout<<it<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element"<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    //bruteforceSolu(arr);
    optimalSolu(arr);
}