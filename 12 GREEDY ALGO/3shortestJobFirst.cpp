#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestJobFirst(vector<int>& times) {
        int n = times.size();
        sort(times.begin() , times.end());
        int time = 0 , waitingTime =0;
        for(int i=0;i<n;i++){
            waitingTime += time;
            time += times[i];
        }
        return waitingTime/n;
    }
};
int main(){
    Solution x;
    vector<int> time = {4 , 3 , 7 , 1 , 2};
    int result = x.shortestJobFirst(time);
    cout<<result;
}