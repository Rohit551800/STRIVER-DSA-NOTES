#include<bits/stdc++.h>
#include<utility>
using namespace std;
int twosumbrute(int arr[] , int n , int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == target){
               cout<<i<<" "<<j<<endl; return 1;
            }
        }
    }
    return -1;
}
int twosumbetter(int arr[] , int n , int target){
    map <int ,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i] ;
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            //return 'YES';
            return 1;
        }
        mpp[a] = i;
    }
    return -1;
}
bool twosumoptimal(vector <int> &arr, int target){
    int n = arr.size();
    sort(arr.begin()  , arr.end());
    int left = 0 ; 
    int right = n-1;
    while(left<right){
        int sum = 0;
        sum = arr[left] + arr[right];
        if(sum == target){
            return true;
        }
        else if (sum > target){
            right --;
        }
        else {
            left++;
        }
    }
    return false;
    
}
int main(){ 
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int target;
    cout<<"Enter the target:";
    cin>>target;
    //cout<<twosumbrute(arr , n ,target);
    //cout<<twosumbetter(arr , n ,target);
    //cout<<twosumoptimal( arr ,target);
    return 0;
}