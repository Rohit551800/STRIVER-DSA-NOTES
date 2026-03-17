#include<bits/stdc++.h>
using namespace std;
int firstOccurance(int arr[] , int size , int x){
    int low = 0;
    int high = size -1;
    int first = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid]<x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return first;
}
int lastOccurance(int arr[] , int size , int x){
    int low = 0;
    int high = size -1;
    int last = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid]<x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return last;
}
int numberofOccurence(int arr[] , int size , int x){
    int first = firstOccurance(arr , size , x);
    if(first == -1 ) return -1;
    int last = lastOccurance(arr , size , x);
    return last - first +1;
}
int main(){
    int arr[] = {2,4,6,8,8,8,11,13};
    int x;
    cout<<"Enter the value of x:";
    cin>>x;
    int ans = numberofOccurence(arr ,8 , x);
    cout<<ans;
}