// Introduction to binary Search Lower Bound and Upper Bound Concept
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector <int> &arr , int size , int target){
    int low = 0;
    int high = size-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        else if (arr[mid] > target){
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}
int lowerBound(vector <int> &arr , int size , int target){
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
// Method 2
int method2(vector <int> &arr , int size , int target){
    int lb = lower_bound(arr.begin() , arr.end(), target) - arr.begin();
    return lb;
}

int upperBound(vector <int> &arr , int size , int target){
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
int searchInsertPosition(vector <int> &arr , int size , int target){
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
int floor(vector <int>&arr , int size , int target){
    int low = 0 , high = size - 1 , ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] <= target){
            ans = arr[mid];
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}
int ceil(vector <int>&arr , int size , int target){
    int low = 0 , high = size - 1 , ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= target){
            ans = arr[mid];
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector <int> arr= {3 , 4 , 6 , 7, 9 , 12, 16 , 17};
    int target;
    cout<<"Enter the number to find in the array:";
    cin>>target;
    //cout<<binarySearch(arr , 8 , target);
    //cout<<lowerBound(arr , 8 , target);
   //cout<<method2(arr , 8 , target);
   //cout<<upperBound(arr , 8 , target);
   cout<<searchInsertPosition(arr , 8 , target);
}