#include<bits/stdc++.h>
using namespace std;
int helper(int index , int jump , int n , vector<int>&arr){
    if(index >= n-1) return jump;
    int mini = INT_MAX;
    for(int i=1;i<=arr[index];i++){
        mini = min(mini , helper(index + i , jump + 1 , n , arr));
    }
    return mini;
}
int jumpGame2(vector<int>&arr){
    return helper(0 , 0 , arr.size() , arr);
}

int optimalSolu(vector<int>&arr){
    int n = arr.size();
    int left =0 , right = 0;
    int jump = 0;
    while (right < n - 1){
        int maxRange = 0;
        for(int ind=left;ind <= right;ind++){
            maxRange = max(maxRange , ind + arr[ind]);
        }
        left = right + 1;
        right = maxRange;
        jump++;
    }
    return jump;
}
int main(){
    vector<int> arr = {2 , 3 , 1 , 1 , 4};
 //   cout<<"Steps taken to reached End of the Game :"<<jumpGame2(arr);
    cout<<"Steps taken to reached End of the Game :"<<optimalSolu(arr);
    return 0;
}