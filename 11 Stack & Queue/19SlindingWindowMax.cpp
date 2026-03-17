#include<bits/stdc++.h>
using namespace std;
vector<int> bruteforce(vector<int>&arr , int k){
    int n = arr.size();
    vector<int>ansList;
    for(int i=0;i<=n-k;i++){
        int maxElem = arr[i];
        for(int j=i;j<=i+k-1;j++){
            maxElem = max(maxElem , arr[j]);
        }
        ansList.push_back(maxElem);
    }
    return ansList;
}
vector<int> optimalSolu(vector<int>&arr , int k){
    int n = arr.size();
    vector<int>ansList;
    deque<int>dq; // dq ko hum monotonic stack ki tarah use kar rhe hai mtlb min from back to ---- >> max from front (Remember upper side is the back side and the lower side the front side in diagram)
    for(int i=0;i<n;i++){                       //itterate krenge pure array mai
        if(!dq.empty() && dq.front() <= i-k){ // Check krega ki kahi stack mai values k se jada toh store nahi ho rahi 
            dq.pop_front();                     // otherwise front se pop kr denge
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){ // Agar stack k back mai jo values store hai vo current values se choti hai toh pop krte jao
            dq.pop_back();
        }
        dq.push_back(i);   //pushes the indexes in the stack
        if(i >= k-1) ansList.push_back(arr[dq.front()]); // ki 2 values k liye work nahi karega
    }
    return ansList;
}
int main(){
    vector<int>arr = {1,3,-1,-3,5,3,2,1,6};
    int k = 3;
    //vector<int> bruteforceSolu = bruteforce(arr , k);
    vector<int> bruteforceSolu = optimalSolu(arr , k);
    for(auto it : bruteforceSolu){
        cout<<it<<" ";
    }
    return 0;
}


//TC --> O(2n) n for itterating and n for pushing and poping elements from the stack
// SC --> O(N-K + K)--- > N-k for list auxilary space and k for stack