// Better Solution

#include<bits/stdc++.h>
using namespace std;
int lowerBound(int arr[] , int size , int target){
    int low = 0 ; 
    int high = size-1;
    int ans = size;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int upperBound(int arr[] , int size , int target){
    int low = 0 ; 
    int high = size-1;
    int ans = size;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
pair<int,int> firstAndLastOccurance(int arr[] ,int size, int x){
    int n  = size;
    int lb = lowerBound(arr , n , x);
    int up = upperBound(arr, n , x);
    if(lb == n || arr[lb] != x){
        return {-1, -1};
    }
    else{
        return {lb , up - 1};
    }
}


// Optimal Solution
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
pair<int,int> optimalSolu(int arr[] , int size , int x){
    int first = firstOccurance(arr , size , x);
    if(first == -1 ) return {-1 , -1};
    int last = lastOccurance(arr , size , x);
    return {first , last};
}
int main(){
    int arr[] = {2,4,6,8,8,8,11,13};
    int x;
    cout<<"Enter the value of x:";
    cin>>x;
    //pair<int,int>ans = firstAndLastOccurance(arr ,8 , x);
    pair<int,int>ans = optimalSolu(arr ,8 , x);
    cout<<ans.first<<" "<<ans.second;
}