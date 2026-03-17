#include<bits/stdc++.h>
using namespace std;
int missingNumber(int arr[] , int n){
    for(int i=1;i<=n;i++){
        int flag = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == i){
                flag = 1;
            }
        }
        if(flag ==0 ){
            return i;
        }
    }
}
int missingnumberusingHASH(int arr[] , int n){
    int hash[n+1] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] = 1;
    }
    for(int i=1;i<n;i++){
        if(hash[i] == 0){
            return i;
        }
    }
}
int missingnumberusingsum(int arr[] , int n){
    int sum1 = n*(n+1)/2;
    int sum2 = 0;
    for(int i=0;i<n;i++){
        sum2 = sum2+arr[i];
    }
    return (sum1 - sum2);
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   // cout<<"Missing number is :"<<missingNumber(arr , n);
   // cout<<"Missing number is :"<<missingnumberusingHASH(arr , n);
   cout<<"Missing number is :"<<missingnumberusingsum(arr , n);
}

// Optimal Solution
#include<bits/stdc++.h>
using namespace std;
int missingnumberusingsum(int arr[] , int n){
    int sum1 = n*(n+1)/2;
    int sum2 = 0;
    for(int i=0;i<n-1;i++){
        sum2 = sum2+arr[i];
    }
    return (sum1 - sum2);
}
int missingnumberbyXOR(int arr[] , int n){
   int xor1 = 0 ;
   for(int i=1; i<=n; i++){
        xor1 = xor1 ^ i;
   }
   int xor2 = 0;
   for(int i=0; i<n-1; i++){
        xor2 = xor2 ^ arr[i];
   }
   return xor1 ^ xor2;
}
int missingnumberbyXOROPTI(int arr[] , int n){
    int xor1 = 0 ; 
    int xor2  = 0;
    for(int i=0;i<n-1;i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    //cout<<"Missing number is :"<<missingnumberusingsum(arr , n);
    //cout<<"Missing number is :"<<missingnumberbyXOR(arr , n);
    cout<<"Missing number is :"<<missingnumberbyXOROPTI(arr , n);
    return 0;
}