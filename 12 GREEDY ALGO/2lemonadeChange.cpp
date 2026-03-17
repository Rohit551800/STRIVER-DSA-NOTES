#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0 , ten = 0 , twenty = 0;
        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                ten++;
                five--;
            }
            else{
                twenty++;
                if(ten){
                    ten--;
                    five--;
                }
                else five = five - 3;
            }
            if(five < 0 || ten < 0) return false;
        }
        return true;
    }
};
int main(){
    Solution x;
    vector<int> bills = {5 , 5 , 10, 10 , 20};
    int result = x.lemonadeChange(bills);
    cout<<result;
}