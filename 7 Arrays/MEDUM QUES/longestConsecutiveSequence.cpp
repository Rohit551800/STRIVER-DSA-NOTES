#include<bits/stdc++.h>
using namespace std;
int bruteforceSolu(vector <int> &arr){
    int n = arr.size();
    int longest = 1;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int count = 1;
        while(find(arr.begin() , arr.end() , x+1) != arr.end()){
                x = x+1;
                count++;
        }
        longest = max(count , longest);
    }
    return longest;
}
int betterSolu(vector <int> &arr){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int longest = 1;
    int lastsequence = arr[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i] == lastsequence+1){
            count++;
            lastsequence = arr[i];
        }
        else if(arr[i] != lastsequence){
            lastsequence = arr[i];
            count = 1;
        }
        longest = max(longest , count);
    }
    return longest;
}
int optimalSolution(vector <int> &arr){
    int n = arr.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int count = 0;
    int x = INT_MIN;
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            count = 1;
            x = it;
        }
        while(st.find(x+1) != st.end()){
            x = x+1;
            count++;
        }
        longest = max(longest , count);
    }
    return longest;
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element"<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    //cout<<"Longest Consecutive length is :"<<bruteforceSolu(arr);
    cout<<"Longest Consecutive length is :"<<betterSolu(arr);
}