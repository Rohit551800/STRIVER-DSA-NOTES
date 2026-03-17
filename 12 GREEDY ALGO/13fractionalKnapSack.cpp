#include<bits/stdc++.h>
using namespace std;
class item{
    public:
    int value;
    int weight;
};
class Solution{
    public:
    bool static comparitor(item a , item b){
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
    int optimalSolution(item arr[] , int W , int n){
        sort(arr , arr + n, comparitor);
        double totalItems = 0;
        for(int i=0;i<n;i++){
            if(arr[i].weight < W){
                totalItems += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                totalItems += ( arr[i].value / arr[i].weight ) * W;
            }
        }
        return totalItems;
    }
};
int main(){
    item arr[] = {{100 , 20} , {60 , 10} , {100 , 50} , {200 , 50}};
    int weight = 90;
    Solution obj;
    cout<<obj.optimalSolution(arr , weight , 4);
    return 0;
}