#include<bits/stdc++.h>
using namespace std;
//METHOD 1 MERGE SORT
void merge(string &s , int low , int mid , int high){
    int left = low , right = mid+1;
    string result = "";
    while(left <= mid && right <= high){
        if(s[left] <= s[right]){
            result.push_back(s[left]);
            left++;
        }
        else{
            result.push_back(s[right]);
            right++;
        }
    }
    while(left <= mid){
        result.push_back(s[left]);
        left++;
    }
    while(right <= high){
        result.push_back(s[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        s[i] = result[i-low];
    }
}
void divide(string &s, int low ,int high){
    
    if(low>=high)
        return ;
    int mid = (low+high)/2;
    divide(s,low , mid);
    divide(s,mid+1,high);
    merge(s,low,mid,high);
}
void mergeSort(string &s){
    int n = s.size();
    divide(s, 0, n-1);
}

// METHOD 2 using Vector Array
string sortString(string &s){
    int n = s.size();
    string ans = "";
    vector<int>v(26,0);
    for(int i=0;i<n;i++){
        v[s[i] - 'a']++;
    }

    for(int i=0;i<26;i++){
        char c = i + 'a';
        while(v[i]){
            ans.push_back(c);
            v[i]--;
        }
    }
    return ans;
}
int main(){
    string s = "eeebcadd";
    // mergeSort(s);
    // cout<<s;
    cout<<sortString(s);
    return 0;
}