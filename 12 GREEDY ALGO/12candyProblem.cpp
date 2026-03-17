#include<bits/stdc++.h>
using namespace std;
int bruteforceSolu(vector<int>arr){
    int totalCandy = 0;
    int n = arr.size();
    vector<int>left(n);
    vector<int>right(n);
    left[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i-1] < arr[i]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    right[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            right[i] = right[i + 1] + 1;
        }
        else{
            right[i] = 1;
        }
    }

    for(int i=0;i<n;i++){
        totalCandy = totalCandy + max(left[i] , right[i]);
    }   
    return totalCandy;
}

int betterSolu(vector<int>arr){
    int totalCandy = 1;
    int n = arr.size();
    vector<int>left(n);
    left[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i-1] < arr[i]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    int curr = 1 ;
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            curr = curr + 1;
        }
        else{
            curr = 1;
        }
        totalCandy = totalCandy + max(left[i] , curr);
    }   
    return totalCandy;
}

int optimalSolu(vector<int>arr){
    int n = arr.size();
    int i = 1;
    int sum = 1;
    while(i<n){
        if(arr[i] == arr[i-1]){
            sum += 1;
            i++;
            continue;
        }

        int peak = 1;
        while(i<n && arr[i-1] < arr[i]){
            peak += 1;
            sum += peak;
            i++;
        }

        int down = 1;
        while(i<n && arr[i-1] > arr[i]){
            sum += down;
            down += 1;
            i++;
        }

        if(down > peak){
            sum += down - peak;
        }
    }
    return sum;
}
int main(){
    vector<int>arr = {0,2,4,3,2,1,1,3,5,6,4,0,0};
    cout<<bruteforceSolu(arr)<<endl;
    cout<<betterSolu(arr)<<endl;
    int result = optimalSolu(arr);
    cout<<result;
    return 0; 
}