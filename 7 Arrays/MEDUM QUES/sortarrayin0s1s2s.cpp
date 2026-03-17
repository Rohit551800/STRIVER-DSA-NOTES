#include<bits/stdc++.h>
using namespace std;
void sortedOrderBetterSolu(vector<int> &arr){
    int n = arr.size();
    int count0 = 0 ,  count1 = 0 , count2 = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            count0++;
        }
        else if(arr[i] ==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i=0;i<count0;i++){
        arr[i] = 0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i] =1;
    }
    for(int i =count0+count1 ; i<n;i++){
        arr[i] = 2;
    }
}
void optimalSolu(vector <int> & arr){
    int n = arr.size();
    int mid = 0;
    int low = 0;
    int high = n-1;
    while(mid <=high ){
        if(arr[mid] == 0){
            swap(arr[mid] , arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if (arr[mid] == 2){
            swap(arr[mid] , arr[high]);
            high--;
        }
    }
}
int main(){
    vector <int> arr;
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    for(int i=0;i<n;i++){
        int a ;
        cout<<"Enter element "<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    //sortedOrderBetterSolu(arr);
    optimalSolu(arr);
    for(auto v : arr){
        cout<<v<<" ";
    }
    return 0;
}