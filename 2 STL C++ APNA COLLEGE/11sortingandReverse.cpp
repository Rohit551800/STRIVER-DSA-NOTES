// To sort an vector of elements
#include<bits/stdc++.h>
#include<array>
using namespace std;
int main(){
    int arr[5] = {1,4,2,7,5};
    reverse(arr  , arr +5 );
    //sort(arr, arr+5);
    for(int val : arr){
        cout<<val<<" "<<endl;
    }
    cout<<endl;
    return 0;
}


// To sort an vecter of elements
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int>vec = {1,4,2,7,5};
    sort(vec.begin(), vec.end());
    for(int val : vec){
        cout<<val<<" "<<endl;
    }
    cout<<endl;
    return 0;
}

// To sort an vecter of elements
#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool comparators(pair<int,int> p1,pair <int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first < p2.first) return true;
    else return false;
}
int main(){
    vector<pair<int ,int>> vec = {{1,4},{2,7},{5,7}};
    //sort(vec.begin(), vec.end() ,comparators);
    for(auto p : vec){
    cout<<p.first<< " "<<p.second<<" "<<endl;
    }
    cout<<endl;
    return 0;
}