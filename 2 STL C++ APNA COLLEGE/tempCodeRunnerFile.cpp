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
