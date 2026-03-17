#include<bits/stdc++.h>
using namespace std;
int sqrtOfNumber(int n){
    int low  = 1;
    int high = n ; 
    int ans = 1;
    while(low<=high){
        int mid = (low+high)/2;
        // if(mid*mid == n){
        //     ans = mid;   
        // }
        if(mid*mid > n) high = mid-1;
        else{
            ans = mid;
            low = mid+1;
        }
    }
    return high;
}
int main(){
    int n;
    cout<<"Enter the number to find the sqrt:";
    cin>>n;
    cout<<sqrtOfNumber(n);
    return 0;
}