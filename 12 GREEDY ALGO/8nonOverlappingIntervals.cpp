#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool static comparitor(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
    int maxNonOverlappingIntervals(vector<vector<int>>& arr){
        int n = arr.size();
        sort(arr.begin() , arr.end(), comparitor);

        int count = 1;
        int end = arr[0][1];
        for(int i=1;i<n;i++){
            if(end > arr[i][0]){
                count++;
                end = arr[i][1];
            }
        }
        return n - count ;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> arr = {{0,5} , {3,4} , {1,2} , {5,9} , {5,7} , {7,9}};
    int ans  = obj.maxNonOverlappingIntervals(arr);
    cout<<ans;
    return 0;
}