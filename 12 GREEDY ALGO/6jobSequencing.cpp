#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    int id;
    int deadline;
    int profit;
};
class solution{
    public:
    bool static comparitor(Job a , Job b){
        return (a.profit > b.profit);
    }
    pair<int,int> jobScheduling(Job arr[] , int n){
        sort(arr , arr+n , comparitor);
        int maxProfit = 0;
        int countJobs = 0;
        int maxDeadline = 0;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline , arr[i].deadline);
        }
        int hash[maxDeadline+1] ;
        for(int i=0;i<=maxDeadline;i++){
            hash[i] = -1;
        }
        for(int i=0;i<n;i++){
            for(int j=arr[i].deadline;j>0;j--){
                if(hash[j] == -1){
                    hash[i] = i;
                    countJobs += 1;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs  , maxProfit};
    }
};
int main(){
    int n = 7;
    Job arr[] = {{1,1,3} , {2,3,5} , {3,4,20} , {4,3,18},{5,2,1},{6,1,6},{7,2,30}};
    solution obj;
    cout<<"Total jobs and profit are:";
    pair<int,int> result = obj.jobScheduling(arr , n);
    cout<<result.first<<"  "<<result.second;
    return 0;
}