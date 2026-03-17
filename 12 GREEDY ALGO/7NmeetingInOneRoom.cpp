#include<bits/stdc++.h>
using namespace std;
class Data{
    public:

    int start ;
    int end ;
    int position ;

};
class Solution{
    public:
    bool static compaitor(Data a , Data b){
        return a.end < b.end ;
    }
    int nMeetingsIn1Room(int start[] , int end[] , int n){
        Data arr[n];
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].position = i + 1;
        }
        sort(arr , arr + n , compaitor);
        vector<int> answer(n);
        int limit = arr[0].end;
        answer.push_back(arr[0].position);
        int count = 1;
        for(int i=1;i<n;i++){
            if(limit < arr[i].start){
                count++;
                limit = arr[i].end;
            }
        }
        return count;
    }
};
int main(){
    Solution obj;
    int n = 6;
    int start[] = {1,3,0,5,8,5};
    int end[] = {2,4,5,7,9,9};
    int answer = obj.nMeetingsIn1Room(start, end, n);
    cout<<answer;
}