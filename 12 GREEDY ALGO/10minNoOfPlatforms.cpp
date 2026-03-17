#include<bits/stdc++.h>
using namespace std;
int bruteforceSolu(vector<int>&arr , vector<int>&dep){
    int n = arr.size();
    int maxCount = 0;
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
                (arr[j]>=arr[i] && arr[j]<=dep[i]))
            {
                count++;
            }
        }
        maxCount = max(maxCount , count);
    }
    return maxCount;
}
int optimalSolution(vector<int>&arr , vector<int>&dep){
    int n = arr.size();
    sort(arr.begin() , arr.end());
    sort(dep.begin() , dep.end());
    int count = 0 , maxCount = 0;
    int i = 0;
    int j = 0;

    while(i<n){
        if(arr[i] < dep[j]){
            count += 1;
            i++;
        }
        else{
            count -= 1;
            j++;
        }
        maxCount = max(maxCount , count);
    }
    return maxCount;
}
int main(){
    vector<int> arr = {900 , 945 , 955 , 1100 , 1500 , 1800};
    vector<int> dep = {920 , 1200 , 1130 , 1150 , 1900 , 2000};
    int result1 = bruteforceSolu(arr , dep);
    int result2 = optimalSolution(arr , dep);
    cout<<result1;
    cout<<result2;
    return 0;
}