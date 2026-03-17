#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
void printAllDivisors(int n){
    vector <int> v;
    for(int i =1;i*i<=n;i++){
        if(n%i ==0) v.push_back(i);
        if(n/i != i) v.push_back(n/i);       
    }
    sort(v.begin(), v.end());
    for(auto val : v){
        cout<<val<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printAllDivisors(n);
    return 0;
}


