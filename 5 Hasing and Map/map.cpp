#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // pre-storing;
    map <int , int > m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto v : m){
        cout<<v.first<<"->"<<v. second <<" "<<endl;;
    }
    int q;
    cout<<"Enter the number of values to check:";
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetching
        cout<<m[num]<<" "<<endl;
    }
}

// Finding the maximum and minimum element of the hash table||
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }int maxFreq = 0, minFreq = INT_MAX;
    int maxElem = -1, minElem = -1;

    for(int i = 0; i < 13; i++) {
        if(hash[i] > 0 && hash[i] > maxFreq) {
            maxFreq = hash[i];
            maxElem = i;
        }
        if(hash[i] > 0 && hash[i] < minFreq) {
            minFreq = hash[i];
            minElem = i;
        }
    }
    cout<<"Max element in the hash is :"<<maxElem<<endl;
    cout<<"Min element in the hash is:"<<minElem<<endl;

    return 0;
}