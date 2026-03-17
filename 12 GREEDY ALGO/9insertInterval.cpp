#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insertInterval(vector<vector<int>>& intervals , vector<int>& newIntervals){
    int n = intervals.size();
    vector<vector<int>> result;
    int i = 0;
    while(i < n && intervals[i][1] <newIntervals[0]){
        result.push_back(intervals[i]);
        i++;
    }
    while(i < n && intervals[i][0] <= newIntervals[1]){
        newIntervals[0] = min(intervals[i][0] , newIntervals[0]);
        newIntervals[1] = max(intervals[i][1] , newIntervals[1]);
        i++;
    }
    result.push_back(newIntervals);
    while(i < n ){
        result.push_back(intervals[i]);
        i++;
    }

    for(auto it : result){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return result;
} 
int main(){
    vector<vector<int>> intervals = {{1,2} , {3,4} , {6,7} , {8,10} ,{12,16}};
    vector<int> newInterval = {5,8};
    insertInterval(intervals , newInterval);
    return 0;
}