// MAJORITY ELEMENT N/2

#include<bits/stdc++.h>
using namespace std;
// using traversing
int bruteforceSolu(vector <int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count ++;
            }
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}
// using hash map
int betterSolu(vector <int> arr){
    int n = arr.size();
    map <int , int > mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it :mpp){
        if(it.second > n/2) return it.first;
    }
    return -2;
}
// using Moore's Voting Algorithm
int optimalSolu(vector <int> &arr){
    int n = arr.size();
    int count = 0;
    int el;
    for(int i=0;i<n;i++){
        if(count==0){
            count++;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }
        else{
            count--;
        }
    }
    int count1;
    for(int i=0;i<n;i++){
        if(arr[i] == el) count1++;
    }
    if(count1>n/2) return el;
    return -1;
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
    //cout<<bruteforceSolu(arr);
    // cout<<betterSolu(arr);
    cout<<optimalSolu(arr);
}