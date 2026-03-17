#include<iostream>
using namespace std;
int consecutiveOnes(int arr[] , int n){
    int maxi = 0; 
    int count =0 ;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            count++;
            maxi = max(maxi , count);
        }
        else{
            count = 0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter the size of arrray:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum Consecutive One's Are:"<<consecutiveOnes(arr,n);
}