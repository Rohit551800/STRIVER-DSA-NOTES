#include<bits/stdc++.h>
using namespace std;
int firstOccurence(vector <int> &arr , int n){
    int n1 = arr.size();
    int low = 0;
    int high = n1-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == n){
            first = mid;
            high = mid-1 ;
        }
        else if(arr[mid] < n){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}
int lastOccurence(vector <int> &arr , int n){
    int n2 = arr.size();
    int low = 0;
    int high = n2-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == n){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] < n){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}
pair <int,int> occurrenceOfNumber(vector <int> &arr , int n){
    int first = firstOccurence(arr , n);
    int last = lastOccurence(arr, n);
    return {first , last};
}
int main(){
    vector <int> arr = {1,1,1,2,2,3,3};
    int n;
    cout<<"Enter the number you want to search for:";
    cin>>n;
    pair<int, int> result = occurrenceOfNumber(arr, n);
    cout << "First Occurrence: " << result.first << endl;
    cout << "Last Occurrence: " << result.second << endl;
}