#include<bits/stdc++.h>
using namespace std;
//using travesal
int bruteforceSolu(vector <int> &arr){
    int n = arr.size();
    int maxi = 0;
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            maxi = max(sum , maxi);
        }
    }
    return maxi;
}
//using Kadane's Algorithm
int optimalSolu(vector <int> &arr){
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        sum = sum+arr[i];
        if(sum > 0){
            maxi = max(maxi , sum);
        }
        else if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int a ;
        cout<<"Enter element"<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    //cout<<bruteforceSolu(arr);
    cout<<optimalSolu(arr);
}