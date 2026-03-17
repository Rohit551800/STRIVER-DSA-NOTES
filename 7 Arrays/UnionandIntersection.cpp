#include<bits/stdc++.h>
using namespace std;
void unionOf2Array(int arr1[] , int arr2[] , int n , int m){
    set <int> s;
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        s.insert(arr2[i]);
    }
    vector <int> v;
    for(auto val: s){
        v.push_back(val);
    }
    for(auto val: v){
        cout<<val<<" ";
    }
}
int main(){
    int n , m;
    cout<<"Enter the size of array 1:";
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of array 2:";
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    unionOf2Array(arr1 , arr2 , n , m);
    return 0;
}