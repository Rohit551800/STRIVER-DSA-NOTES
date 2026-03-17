#include<bits/stdc++.h>
using namespace std;
int bruteforceSolu(vector <int> &arr , int k){
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum = sum+arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}
int optimalSolu(vector <int> &arr , int k){
    int n =arr.size();
    int presum = 0;
    int count =0;
    unordered_map<int , int> mpp;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        presum = presum+arr[i];
        int remove = presum - k;
        count = count + mpp[remove];
        mpp[presum] = mpp[presum] + 1;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element "<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cout<<"Enter the value of k:";
    cin>>k;
    //cout<<"Number of subarrays with sum K are :"<<bruteforceSolu(arr , k);
    cout<<"Number of subarrays with sum K are :"<<optimalSolu(arr , k);
}