// Pair
#include<bits/stdc++.h>
using namespace std;
int main(){
    pair <int,int> p = {1,2};  // Simple initialization of pair
    cout<<p.first<<" "<<p.second<<" "<<endl;  // Accessing Simple pair
    return 0;
}


// Pair of Pair

#include<bits/stdc++.h>
using namespace std;
int main(){
    pair <int,pair<char,int>> p = {1,{'A',2}}; // --Initialization of Pair of Pair
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<" "<<endl;  //-- Accessing Pair of Pair
    return 0;
}


// Vector of Pair

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair <int,int>>vec = {{1,2},{2,3},{3,4}};
    vec.push_back({4,5}) ; // -- Not a good method of pushing element in vector
    vec.emplace_back(5,6); // -- Creates In-place Objects
    for(auto val: vec){
        cout<<val.first<<" "<<val.second<<" "<<endl;  // -- Accessing Vector of pair
    }
    return 0;
}

