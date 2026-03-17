#include<bits/stdc++.h>
using namespace std;
void leftRotate(int arr[] , int n, int d){
    reverse(arr , arr+d);
    reverse(arr+d , arr+n);
    reverse(arr , arr+n);
}
void rightRotate(int arr[] , int n, int d){
    reverse(arr+n-d , arr+n);
    reverse(arr , arr+n-d);
    reverse(arr , arr+n);
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter the no of elem to rotate:";
    cin>>d;
    //leftRotate(arr , n , d);
    rightRotate(arr , n , d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}