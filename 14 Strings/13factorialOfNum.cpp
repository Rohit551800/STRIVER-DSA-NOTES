#include<bits/stdc++.h>
using namespace std;
int factorial1(int x){
    int ans = 1;
    while(x > 0){
        ans *= x;
        x -= 1;
    }
    return ans;
}

string factorial2(int x){
    vector<int>ans;
    ans.push_back(1);
        while(x > 1){
        int carry = 0;
        for(int i=0;i<ans.size();i++){
            int y= (x * ans[i] + carry);
            carry = y/10;
            ans[i] = y%10;
        }
        x--;
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
    }

    reverse(ans.begin() , ans.end());
    string result = "";
    for (int i=0;i<ans.size();i++){
        result += ans[i] + '0'; 
    }
    return result;
}

int main(){
    int x = 7;
    // cout<<factorial1(x);
    cout<<factorial2(x);
    return 0;
}