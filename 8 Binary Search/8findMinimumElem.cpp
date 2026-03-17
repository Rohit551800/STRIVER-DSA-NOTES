#include<bits/stdc++.h>
using namespace std;
pair <int,int> minimumElem(vector <int> &arr){
    int n = arr.size();
    int low = 0;   
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low] <= arr[mid]){
            ans = min(arr[low] , ans);
            index = arr[ans];
            low = mid+1;
        }
        else{
            ans = min(arr[mid] , ans);
            index  = arr[ans];
            high = mid -1;
        }
    }
    return {ans , arr[ans]};
}
int main(){
    vector <int> arr = {4,5,6,7,0,1,2,3};
    pair <int , int > result = minimumElem(arr);
    cout<<"Minimum elem is :"<<result.first<<endl<<"Index of Minimum elem is :"<<result.second;
    return 0;
}