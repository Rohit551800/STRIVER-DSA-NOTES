#include<bits/stdc++.h>
using namespace std;
void bruteforceSolu(vector <int> &arr){
    int n=arr.size();
    vector <int> pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<n/2;i++){
            arr[2*i]= pos[i];
            arr[2*i+1]= neg[i];
        }
        int index = 2*neg.size();
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    if(pos.size()<neg.size()){
        for(int i=0;i<n/2;i++){
            arr[2*i]= pos[i];
            arr[2*i+1]= neg[i];
        }
        int index = 2*pos.size();
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element"<<i+1<<":";
        cin>>a;
        arr.push_back(a);
    }
    bruteforceSolu(arr);
    return 0;
}