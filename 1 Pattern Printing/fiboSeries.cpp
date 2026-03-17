#include<bits/stdc++.h>
using namespace std;
int printFibo(int n){
    if(n <= 1) return n;
    return printFibo(n-1) + printFibo(n-2);
}
int main(){
    int n;
    cout<<"Enter the value of n :";
    cin>>n;
    for(int i=0; i<n; i++){
        cout << printFibo(i) << " ";
    }
    return 0;
}