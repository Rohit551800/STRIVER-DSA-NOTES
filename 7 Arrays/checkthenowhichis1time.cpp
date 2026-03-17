#include<bits/stdc++.h>
using namespace std;
// Brute Force
int checkNum(int arr [], int n){
    for(int i=0;i<n;i++){
        int num = arr[i];
        int count =0;
        for(int j =0;j<n;j++){
            if(arr[j] == num){
                count++;
            }
        }
        if(count ==1){
            return num;
        }
    }
}
int optimalsolution(int arr[] , int n){
    int xor1 = 0;
    for(int i = 0;i<n;i++){
        xor1 = xor1^arr[i];
    }
    return xor1;
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //cout<<"The at 1 time is :"<<checkNum(arr , n);
    cout<<"The at 1 time is :"<<optimalsolution(arr , n);
    return 0;
}