#include<bits/stdc++.h>
using namespace std;
bool jumpGame(vector<int>& arr){
    int n = arr.size();
    int maxJump = 0;
    for(int i=0;i<n;i++){
        if(i > maxJump) return false;
        maxJump = max(maxJump ,i + arr[i]);
    }
    return true;
}
int main(){
    vector<int> arr = {1 , 2 , 3 , 1 , 1 , 0, 2 , 5};
    cout<<"Does Arr Reached till end :"<<jumpGame(arr);
    return 0;
}